//
// Created by Andrei on 10/03/2021.
//

#ifndef KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP
#define KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP

#include <memory>
#include <vector>
#include <atomic>
#include <thread>

#include "clickable.hpp"

class KeyPressWatcher {
public:
    static std::shared_ptr<KeyPressWatcher> getInstance();

    void registerListener(const Clickable *);

    void unregisterListener(const Clickable *);

    virtual ~KeyPressWatcher() noexcept;

private:
    KeyPressWatcher();

private:
    static std::shared_ptr<KeyPressWatcher> instance;
    std::vector<const Clickable *> registeredListeners;
    std::atomic_flag exitSignal;

    std::thread logicThread;
};


#endif //KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP
