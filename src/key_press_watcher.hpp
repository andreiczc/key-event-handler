//
// Created by Andrei on 10/03/2021.
//

#undef mDLLIMPORTEXPORT
#ifdef WIN32
#ifdef mKEY_PRESS_WATCHER
#define mDLLIMPORTEXPORT __declspec(dllexport)
#else
#define mDLLIMPORTEXPORT __declspec(dllimport)
#endif
#else
#define mDLLIMPORTEXPORT
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
    static std::shared_ptr<KeyPressWatcher> getInstance();

    void registerListener(const Clickable *);

    void unregisterListener(const Clickable *);

    virtual ~KeyPressWatcher() noexcept;

private:
    KeyPressWatcher();

private:
    static std::shared_ptr<KeyPressWatcher> instance;
    std::promise<void> exitSignal;
    std::vector<const Clickable *> registeredListeners;
};


#endif //KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP
