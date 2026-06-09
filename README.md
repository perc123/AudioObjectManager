# AudioObjectManager

A C++17 manager for 3D audio objects with unique IDs, positions, and undo / redo.

Originally written as a technical exercise for HOLOPLOT (a Berlin-based spatial audio company) in November 2023; kept here as a small example of clean C++ object-lifecycle code with reversible state changes.

## What it does

Manages a set of `AudioObject` instances, each identified by an integer ID and an `(x, y, z)` position. Supports:

- `add(obj)` — insert a new audio object.
- `remove(id)` — remove an existing object by ID.
- `changePosition(id, x, y, z)` — move an existing object.
- `undo()` / `redo()` — step back and forth through the action history.
- `printState()` — dump the current set of objects, sorted by ID.

## Design notes

- **Storage**: `std::unordered_map<int, AudioObject>` — O(1) average for insert, remove, and lookup by ID; iteration is fine for the `printState` use case where total object count is small.
- **History**: two `std::stack`s, one for undo and one for redo, each storing `(action_name, AudioObject snapshot)` pairs. Performing a new action invalidates the redo stack.
- **Headers / implementation split** — public interface lives in [`include/`](./include), implementation in [`src/`](./src). The CMake target list is in [`CMakeLists.txt`](./CMakeLists.txt).

`src/main.cpp` walks through the original exercise sequence; a second executable in `examples/redo_example_main.cpp` exercises the redo path.

## Build

Requires CMake 3.26+ and a C++17 compiler.

```bash
cmake -B build
cmake --build build
```

Produces two executables in `build/`:

```bash
./build/AudioObjectManager
./build/redo_example_main
```

## Scope

This is an interview / coding-exercise project, not a production audio object manager. `AudioObject` is purely a data record — there is no audio rendering. The interest is in the data structures and the undo / redo design.

Natural extensions if grown into something larger: parametric audio properties beyond position, command-pattern actions instead of stack-of-snapshots, thread-safe access for use from an audio thread, serialization of the scene state.
