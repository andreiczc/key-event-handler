//
// Created by Andrei on 10/03/2021.
//

#include "key_press_watcher.hpp"

#include <iostream>
#include <chrono>

#include "key_press_event.hpp"

using namespace std;

shared_ptr<KeyPressWatcher> KeyPressWatcher::instance(nullptr);

std::shared_ptr<KeyPressWatcher> KeyPressWatcher::getInstance() {
    if (!KeyPressWatcher::instance) {
        KeyPressWatcher::instance.reset(new KeyPressWatcher());
    }

    return KeyPressWatcher::instance;
}

KeyPressWatcher::KeyPressWatcher() {
    logicThread = thread([](atomic_flag *signal) {
        if (!signal->test()) {
            while (true) {
                std::cout << "hello world" << std::endl;
            }
        }
    }, &this->exitSignal);
}

KeyPressWatcher::~KeyPressWatcher() noexcept {
    this->exitSignal.test_and_set();

    if (this->logicThread.joinable()) {
        cout << "joining logic thread" << endl;
        this->logicThread.join();
    }
}

void KeyPressWatcher::registerListener(const Clickable *clickable) {
    instance->registeredListeners.emplace_back(clickable);
}

void KeyPressWatcher::unregisterListener(const Clickable *clickable) {
    const auto iterator = std::find(instance->registeredListeners.begin(), instance->registeredListeners.end(),
                                    clickable);

    instance->registeredListeners.erase(iterator);

}
