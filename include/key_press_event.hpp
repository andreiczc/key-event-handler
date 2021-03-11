//
// Created by Andrei on 10/03/2021.
//

#ifndef KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP
#define KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP

#include <vector>
#include "enums.hpp"

#include "define_dll_scope.hpp"

class KeyPressEventBuilder;

class mDLLIMPORTEXPORT KeyPressEvent {
public:
    bool isKeyPressed(Key key) const;

    bool isModifierPressed(Modifier modifier) const;

private:
    explicit KeyPressEvent(Key key);

    Key pressedKey;
    std::vector<Modifier> modifiersPressed;

    friend class KeyPressEventBuilder;
};

#endif //KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP
