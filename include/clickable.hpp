//
// Created by Andrei on 10/03/2021.
//

#ifndef KEY_EVENT_HANDLER_CLICKABLE_HPP
#define KEY_EVENT_HANDLER_CLICKABLE_HPP

#include "key_press_event.hpp"

#include "define_dll_scope.hpp"

class mDLLIMPORTEXPORT Clickable {
public:
    explicit Clickable();

    virtual ~Clickable() noexcept;

    virtual void onClick(KeyPressEvent event) = 0;
};


#endif //KEY_EVENT_HANDLER_CLICKABLE_HPP
