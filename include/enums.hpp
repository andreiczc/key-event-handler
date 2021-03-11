//
// Created by Andrei on 10/03/2021.
//

#ifndef KEY_EVENT_HANDLER_ENUMS_HPP
#define KEY_EVENT_HANDLER_ENUMS_HPP

enum class Key {
	A = 0x41, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	D0 = 0x30, D1, D2, D3, D4, D5, D6, D7, D8, D9
};

enum class Modifier {
	LShift = 0xA0, RShift, LCtrl, RCtrl, LAlt, RAlt,
	Backspace = 0x08, Tab,
	Space = 0x20,
	Esc = 0x1B,
	Enter = 0x0D
};

#endif //KEY_EVENT_HANDLER_ENUMS_HPP
