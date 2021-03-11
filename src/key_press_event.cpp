//
// Created by Andrei on 10/03/2021.
//

#include "key_press_event.hpp"

#include <algorithm>

KeyPressEvent::KeyPressEvent(Key key) : pressedKey(key) {}



bool KeyPressEvent::isModifierPressed(Modifier modifier) {
    const auto iterator = std::find(this->modifiersPressed.begin(),
                                    this->modifiersPressed.end(), modifier);
    return iterator != this->modifiersPressed.end();
}

bool KeyPressEvent::isKeyPressed(Key key) {
    return key == this->pressedKey;
}