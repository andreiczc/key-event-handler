//
// Created by Andrei on 10/03/2021.
//

#include "key_press_watcher.hpp"

#include <iostream>
#include <chrono>
#include <memory>

#include "key_press_event.hpp"

#ifdef WIN32

#include "windows_key_press_watcher_implementation.hpp"

#endif

using namespace std;

shared_ptr<KeyPressWatcher> KeyPressWatcher::instance(nullptr);

std::shared_ptr<KeyPressWatcher> KeyPressWatcher::getInstance() {
    if (!KeyPressWatcher::instance) {
        KeyPressWatcher::instance.reset(new KeyPressWatcher());
    }

    return KeyPressWatcher::instance;
}

KeyPressWatcher::KeyPressWatcher() {
#ifdef WIN32
    this->implementation = std::make_unique<WindowsKeyPressWatcherImplementation>();
#endif

    logicThread = thread([this]() {
        while (!this->exitSignal.test()) {
            auto keyPressEvent = this->implementation->monitorKeypress();
            for (auto handler : instance->registeredListeners) {
                handler->onClick(keyPressEvent);
            }

            this_thread::sleep_for(chrono::milliseconds(50));
        }
    });
}

KeyPressWatcher::~KeyPressWatcher() noexcept {
    this->exitSignal.test_and_set();

    if (this->logicThread.joinable()) {
        cout << "joining logic thread" << endl;
        this->logicThread.join();
    }
}

void KeyPressWatcher::registerListener(Clickable *clickable) {
    instance->registeredListeners.emplace_back(clickable);
}

void KeyPressWatcher::unregisterListener(Clickable *clickable) {
    const auto iterator = std::find(instance->registeredListeners.begin(), instance->registeredListeners.end(),
                                    clickable);

    instance->registeredListeners.erase(iterator);
}
