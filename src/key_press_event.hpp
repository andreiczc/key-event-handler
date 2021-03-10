//
// Created by Andrei on 10/03/2021.
//

#ifdef WIN32
#undef mDLLIMPORTEXPORT
#ifdef mKEY_PRESS_WATCHER
#define mDLLIMPORTEXPORT __declspec(dllexport)
#else
#define mDLLIMPORTEXPORT __declspec(dllimport)
#endif
#endif

#ifndef KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP
#define KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP

#include "enums.hpp"
#include <vector>

class KeyPressEventBuilder;

class mDLLIMPORTEXPORT KeyPressEvent {
public:
    bool isKeyPressed(Key key);

    bool isModifierPressed(Modifier modifier);

private:
    explicit KeyPressEvent(Key key);

    Key pressedKey;
    std::vector<Modifier> modifiersPressed;

    friend class KeyPressEventBuilder;
};

class mDLLIMPORTEXPORT KeyPressEventBuilder {
public:
    explicit KeyPressEventBuilder(Key key);

    KeyPressEventBuilder &addModifier(Modifier modifier);

    KeyPressEvent build();

private:
    KeyPressEvent keyPressEvent;
};

#endif //KEY_EVENT_HANDLER_KEY_PRESS_EVENT_HPP
