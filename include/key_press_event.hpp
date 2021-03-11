//
// Created by Andrei on 10/03/2021.
//

#ifndef KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP
#define KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP

#include <unordered_set>
#include "enums.hpp"

#include "define_dll_scope.hpp"

class KeyPressEventBuilder;

class mDLLIMPORTEXPORT KeyPressEvent {
public:
	bool isKeyPressed(Key key) const;

	bool isModifierPressed(Modifier modifier) const;

private:
	explicit KeyPressEvent() = default;

	std::unordered_set<int> keysPressed;
	std::unordered_set<int> modifiersPressed;

	friend class KeyPressEventBuilder;
};

#endif //KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP
