//
// Created by Andrei on 11/03/2021.
//

#ifndef KEY_EVENT_HANDLER_WINDOWS_KEY_PRESS_WATCHER_IMPLEMENTATION_HPP
#define KEY_EVENT_HANDLER_WINDOWS_KEY_PRESS_WATCHER_IMPLEMENTATION_HPP

#include "key_press_watcher_implementation.hpp"

class WindowsKeyPressWatcherImplementation : public KeyPressWatcherImplementation {
public:
	KeyPressEvent monitorKeypress() override;

	explicit WindowsKeyPressWatcherImplementation() = default;
};


#endif //KEY_EVENT_HANDLER_WINDOWS_KEY_PRESS_WATCHER_IMPLEMENTATION_HPP
