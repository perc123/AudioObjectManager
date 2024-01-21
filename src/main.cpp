//
// Created by fanis on 17.11.2023.
//

#include "../include/AudioObjectManager.h"

int main() {

    AudioObjectManager manager;

    // Add object with first id and position A
    AudioObject obj1(1, 1.0, 2.0, 3.0);
    manager.add(obj1);

    // Add object with second id and position B
    AudioObject obj2(2, 4.0, 5.0, 6.0);
    manager.add(obj2);

    // Change position of object with first id to position C
    manager.changePosition(1, 10.0, 20.0, 30.0);

    // Add object with third id and position D
    AudioObject obj3(3, 7.0, 8.0, 9.0);
    manager.add(obj3);

    // Change position of object with second id to position E
    manager.changePosition(2, 40.0, 50.0, 60.0);

    // Remove object with first id
    manager.remove(1);

    // Change position of object with third id to position F
    manager.changePosition(3, 70.0, 80.0, 90.0);

    // Change position of object with third id to position G
    manager.changePosition(3, 700.0, 800.0, 900.0);

    // Undo
    manager.undo();

    manager.undo();

    // Print the final state of AudioObjects
    manager.printState();

    return 0;
}

