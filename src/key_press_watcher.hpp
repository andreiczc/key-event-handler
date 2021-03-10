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

#ifndef KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP
#define KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP

#include <memory>
#include <future>
#include <vector>
#include <functional>

#include "key_press_event.hpp"
#include "clickable.hpp"

class mDLLIMPORTEXPORT KeyPressWatcher {
public:
    static void registerListener(Clickable*);

    static void unregisterListener(Clickable*);

    virtual ~KeyPressWatcher() noexcept;

private:
    KeyPressWatcher();

    std::shared_ptr<KeyPressWatcher> getInstance();

private:
    static std::shared_ptr<KeyPressWatcher> instance;
    std::promise<void> exitSignal;
    std::vector<Clickable> registeredListeners;
};


#endif //KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP
