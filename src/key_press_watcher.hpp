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
#include "key_press_watcher_implementation.hpp"

class KeyPressWatcher {
public:
    static std::shared_ptr<KeyPressWatcher> getInstance();

    void registerListener(Clickable *);

    void unregisterListener(Clickable *);

    virtual ~KeyPressWatcher() noexcept;

private:
    KeyPressWatcher();

private:
    static std::shared_ptr<KeyPressWatcher> instance;

    std::unique_ptr<KeyPressWatcherImplementation> implementation;
    std::vector<Clickable *> registeredListeners;
    std::atomic_flag exitSignal;
    std::thread logicThread;
};

#endif //KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_HPP
