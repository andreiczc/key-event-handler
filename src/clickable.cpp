//
// Created by Andrei on 10/03/2021.
//

#include "clickable.hpp"
#include "key_press_watcher.hpp"

Clickable::Clickable() {
    auto instance = KeyPressWatcher::getInstance();
    instance->registerListener(this);
}

Clickable::~Clickable() noexcept {
    auto instance = KeyPressWatcher::getInstance();
    instance->unregisterListener(this);
}