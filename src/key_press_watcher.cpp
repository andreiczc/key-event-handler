//
// Created by Andrei on 10/03/2021.
//

#include "key_press_watcher.hpp"

#include <iostream>
#include <chrono>

using namespace std;

shared_ptr<KeyPressWatcher> KeyPressWatcher::instance(nullptr);

KeyPressWatcher::KeyPressWatcher() {
    thread watcherThread([](future<void> future) {
        if(future.wait_for(chrono::milliseconds(1)) == future_status::timeout) {
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

std::shared_ptr<KeyPressWatcher> KeyPressWatcher::getInstance() {
    if (!KeyPressWatcher::instance) {
        KeyPressWatcher::instance.reset(new KeyPressWatcher());
    }

    return KeyPressWatcher::instance;
}

KeyPressWatcher::~KeyPressWatcher() noexcept {
    cout << "key press watcher destructor called" << endl;
    this->exitSignal.set_value();
}

void KeyPressWatcher::registerListener(Clickable* clickable) {
    instance->registeredListeners.push_back(clickable.onClick);
}

void KeyPressWatcher::unregisterListener(Clickable* clickable) {

}
