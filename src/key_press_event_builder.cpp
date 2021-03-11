//
// Created by Andrei on 11/03/2021.
//

#include "key_press_event_builder.hpp"

KeyPressEventBuilder& KeyPressEventBuilder::addModifier(Modifier modifier) {
	keyPressEvent.modifiersPressed.insert(static_cast<int>(modifier));

	return *this;
}

KeyPressEventBuilder& KeyPressEventBuilder::addKey(Key key)
{
	keyPressEvent.keysPressed.insert(static_cast<int>(key));

	return *this;
}

KeyPressEvent KeyPressEventBuilder::build() {
	return this->keyPressEvent;
}