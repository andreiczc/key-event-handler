//
// Created by Andrei on 11/03/2021.
//

#include "key_press_event_builder.hpp"

KeyPressEventBuilder::KeyPressEventBuilder(Key key) : keyPressEvent(key) {}

KeyPressEventBuilder &KeyPressEventBuilder::addModifier(Modifier modifier) {
    this->keyPressEvent.modifiersPressed.push_back(modifier);

    return *this;
}

KeyPressEvent KeyPressEventBuilder::build() {
    return this->keyPressEvent;
}