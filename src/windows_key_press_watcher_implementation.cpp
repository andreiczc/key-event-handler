//
// Created by Andrei on 11/03/2021.
//

#include "windows_key_press_watcher_implementation.hpp"

#include "key_press_event_builder.hpp"
#include <Windows.h>
#include <vector>

// TODO check if window is focused; pass that as param maybe
// TODO make the timeout configurable

KeyPressEvent WindowsKeyPressWatcherImplementation::monitorKeypress() {
	auto builderReturn = KeyPressEventBuilder();
	auto builderWatcher = KeyPressEventBuilder();

	for (auto keyCode = (int)Key::A; keyCode <= (int)Key::Z; ++keyCode) {
		if (GetAsyncKeyState(keyCode) & 0xA000) {
			builderWatcher.addKey((Key)keyCode);
			if (!watcherEvent.isKeyPressed((Key)keyCode)) builderReturn.addKey((Key)keyCode);
		}
	}

	for (auto keyCode = (int)Key::D0; keyCode <= (int)Key::D9; ++keyCode) {
		if (GetAsyncKeyState(keyCode) & 0xA000) {
			builderWatcher.addKey((Key)keyCode);
			if (!watcherEvent.isKeyPressed((Key)keyCode)) builderReturn.addKey((Key)keyCode);
		}
	}

	static std::vector<Modifier> modifiers = { Modifier::LShift, Modifier::RShift, Modifier::LCtrl, Modifier::RCtrl, Modifier::LAlt,
									Modifier::RAlt, Modifier::Backspace , Modifier::Tab,Modifier::Space ,Modifier::Esc ,Modifier::Enter };

	for (auto modifier : modifiers) {
		auto keyCode = (int)modifier;

		if (GetAsyncKeyState(keyCode) & 0xA000) {
			builderWatcher.addModifier((Modifier)keyCode);
			if (!watcherEvent.isModifierPressed((Modifier)keyCode)) builderReturn.addModifier((Modifier)keyCode);
		}
	}

	watcherEvent = builderWatcher.build();

	return builderReturn.build();
}
