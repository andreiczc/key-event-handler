//
// Created by Andrei on 10/03/2021.
//

#include "key_press_watcher.hpp"

#include <iostream>
#include <chrono>

using namespace std;

shared_ptr<KeyPressWatcher> KeyPressWatcher::instance(nullptr);

std::shared_ptr<KeyPressWatcher> KeyPressWatcher::getInstance() {
    if (!KeyPressWatcher::instance) {
        KeyPressWatcher::instance.reset(new KeyPressWatcher());
    }

    return KeyPressWatcher::instance;
}

KeyPressWatcher::KeyPressWatcher() {
    thread watcherThread([](future<void> future) {
        if (future.wait_for(chrono::milliseconds(1)) == future_status::timeout) {
            int i = 2;
            while (i--) {
                std::cout << "hello world" << std::endl;

                std::this_thread::sleep_for(std::chrono::seconds(15));
            }
        } else {
            cout << "stopping thread" << endl;
        }
    }, move(this->exitSignal.get_future()));

    watcherThread.join();
}

KeyPressWatcher::~KeyPressWatcher() noexcept {
    this->exitSignal.set_value();
}

void KeyPressWatcher::registerListener(const Clickable *clickable) {
    instance->registeredListeners.emplace_back(clickable);
}

void KeyPressWatcher::unregisterListener(const Clickable *clickable) {
    const auto iterator = std::find(instance->registeredListeners.begin(), instance->registeredListeners.end(),
                                    clickable);

    if (instance->registeredListeners.size() == 1 && iterator != instance->registeredListeners.end()) {
        instance.reset();
    }

    instance->registeredListeners.erase(iterator);
}
