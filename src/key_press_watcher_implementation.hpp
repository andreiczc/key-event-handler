//
// Created by Andrei on 11/03/2021.
//

#ifndef KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_IMPLEMENTATION_HPP
#define KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_IMPLEMENTATION_HPP

#include "key_press_event.hpp"
#include "key_press_event_builder.hpp"

class KeyPressWatcherImplementation {
public:
	virtual KeyPressEvent monitorKeypress() = 0;

	explicit KeyPressWatcherImplementation() :watcherEvent(KeyPressEventBuilder().build()) {}

protected:
	KeyPressEvent watcherEvent;
};


#endif //KEY_EVENT_HANDLER_KEY_PRESS_WATCHER_IMPLEMENTATION_HPP
