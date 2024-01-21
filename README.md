# **Audio Object Manager**

The Audio Object Manager is a C++ program that manages audio objects with unique IDs and 3D positions. It provides functionality to add, remove and change the position of them, as well as undo and redo the previous actions.


## Features
- Add audio objects with unique IDs and 3D positions.
- Remove audio objects by their ID.
- Change the position of audio objects by their ID.
- Undo and redo actions (using a stack data structure).
- Print the current state of audio objects, sorted by ID in ascending order.


## Run Instructions
There are two executables AudioObjectManager.exe with the actions described in the task and redo_example_main.exe where redo actions are included. Both can be found in the Debug folder if you run it on Windows or in the AudioObjectManager folder on macOS. The project is build with CMake.

### On Windows
- To run the main AudioObjectManager executable navigate to the Debug folder and run: ./AudioObjectManager.exe
- To run the redo example main executable navigate to the Debug folder and run: ./redo_example_main.exe

### On macOS
- To run the main AudioObjectManager executable navigate to the AudioObjectManager folder and run: ./AudioObjectManager
- To run the redo example main executable navigate to the AudioObjectManager folder and run: ./redo_example_main

## Comments
The Position of the AudioObjects is represented by three float numbers for the coordinates x, y, z. According to the task, the following sequence of actions are included to the solution:
- Add object with first id and position A=(1, 2, 3)
- Add object with second id and position B=(4, 5, 6)
- Change position of object with first id to position C=(10, 20, 30)
- Add object with third id and position D=(7, 8, 9)
- Change position of object with second id to position E=(40, 50, 60)
- Remove object with first id
- Change position of object with third id to position F=(70, 80, 90)
- Change position of object with third id to position G=(700, 800, 900)
- Undo
- Undo

This leads to the final state of the objects to be:
- Object with first id has position C=(10, 20, 30)
- Object with second id has position E=(40, 50, 60)
- Object with third id has position D=(7, 8, 9)


_Created by Theofanis Gkioles Blatsoukas for HOLOPLOT on 19/11/2023_