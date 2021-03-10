//
// Created by Andrei on 10/03/2021.
//

#include "key_press_event.hpp"

KeyPressEvent::KeyPressEvent(Key key) : pressedKey(key) {}

KeyPressEventBuilder::KeyPressEventBuilder(Key key) : keyPressEvent(key) {}

KeyPressEventBuilder &KeyPressEventBuilder::addModifier(Modifier modifier) {
    this->keyPressEvent.modifiersPressed.push_back(modifier);

    return *this;
}

KeyPressEvent KeyPressEventBuilder::build() {
    return this->keyPressEvent;
}

bool KeyPressEvent::isModifierPressed(Modifier modifier) {
    const auto iterator = std::find(this->modifiersPressed.begin(),
                                    this->modifiersPressed.end(), modifier);
    return iterator != this->modifiersPressed.end();
}

bool KeyPressEvent::isKeyPressed(Key key) {
    return key == this->pressedKey;
}