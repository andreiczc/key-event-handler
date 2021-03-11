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

    void onClick(KeyPressEvent event) override {
        if (event.isKeyPressed(Key::A)) {
            cout << "A is pressed" << endl;
        }
    }

    void mock() {}
};

int main() {
    Test test;
    
    this_thread::sleep_for(chrono::seconds(15));

    test.mock();

    return 0;
}