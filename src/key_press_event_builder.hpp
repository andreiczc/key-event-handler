//
// Created by Andrei on 11/03/2021.
//

#ifndef KEY_EVENT_HANDLER_KEY_PRESS_EVENT_BUILDER_HPP
#define KEY_EVENT_HANDLER_KEY_PRESS_EVENT_BUILDER_HPP

#include "key_press_event.hpp"

class KeyPressEventBuilder {
public:
	explicit KeyPressEventBuilder() = default;

	KeyPressEventBuilder& addModifier(Modifier modifier);

	KeyPressEventBuilder& addKey(Key key);

	KeyPressEvent build();

private:
	KeyPressEvent keyPressEvent;
};


#endif //KEY_EVENT_HANDLER_KEY_PRESS_EVENT_BUILDER_HPP
