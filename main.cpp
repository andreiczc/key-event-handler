//
// Created by Andrei on 10/03/2021.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "clickable.hpp"

using namespace std;

class Test : public Clickable {
public:
	Test() : Clickable() {};

	void onClick(const KeyPressEvent& event) override {
		if (event.isKeyPressed(Key::A)) {
			cout << "A is pressed" << endl;
		}
		else if (event.isKeyPressed(Key::D9)) {
			cout << "Digit 9 is pressed" << endl;
		}
		else if (event.isModifierPressed(Modifier::Esc)) {
			cout << "Escape is pressed" << endl;
		}
	}

	void mock() {}
};

int main() {
	Test test;

	this_thread::sleep_for(chrono::seconds(60));

	test.mock();

	return 0;
}