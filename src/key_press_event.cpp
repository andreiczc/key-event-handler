//
// Created by Andrei on 10/03/2021.
//

#include "key_press_event.hpp"

#include <algorithm>

bool KeyPressEvent::isModifierPressed(Modifier modifier) const {
	return this->modifiersPressed.contains(static_cast<int>(modifier));
}

bool KeyPressEvent::isKeyPressed(Key key) const {
	return this->keysPressed.contains(static_cast<int>(key));
}