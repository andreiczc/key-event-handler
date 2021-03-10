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

#ifndef KEY_EVENT_HANDLER_CLICKABLE_HPP
#define KEY_EVENT_HANDLER_CLICKABLE_HPP

#include "key_press_event.hpp"

class mDLLIMPORTEXPORT Clickable {
public:
    explicit Clickable();

    virtual ~Clickable() noexcept;

    virtual void onClick(KeyPressEvent event) = 0;
};


#endif //KEY_EVENT_HANDLER_CLICKABLE_HPP
