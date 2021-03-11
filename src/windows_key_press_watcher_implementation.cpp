//
// Created by Andrei on 11/03/2021.
//

#include "windows_key_press_watcher_implementation.hpp"
#include "key_press_event_builder.hpp"

// TODO check if window is focused; pass that as param maybe
// TODO make the timeout configurable

KeyPressEvent WindowsKeyPressWatcherImplementation::monitorKeypress() {
    return KeyPressEventBuilder(Key::A).build();
}
