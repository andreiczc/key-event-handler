//
// Created by Andrei on 10/03/2021.
//

#include "clickable.hpp"
#include "key_press_watcher.hpp"

Clickable::Clickable() {
    KeyPressWatcher::registerListener(this);
}

Clickable::~Clickable() noexcept {
    KeyPressWatcher::unregisterListener(this);
}