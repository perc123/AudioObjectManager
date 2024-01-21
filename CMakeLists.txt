cmake_minimum_required(VERSION 3.26)
project(AudioObjectManager)

set(CMAKE_CXX_STANDARD 17)

# Add source files for AudioObjectManager executable
set(SOURCE_FILES src/main.cpp
        include/AudioObject.h
        include/AudioObjectManager.h
        src/AudioObjectManager.cpp
        src/AudioObject.cpp)

# Create the AudioObjectManager executable
add_executable(AudioObjectManager ${SOURCE_FILES})

# Add source files for redo_example_main executable
set(REDO_EXAMPLE_SOURCE_FILES examples/redo_example_main.cpp
        include/AudioObject.h
        include/AudioObjectManager.h
        src/AudioObjectManager.cpp
        src/AudioObject.cpp)

# Create the redo_example_main executable
add_executable(redo_example_main ${REDO_EXAMPLE_SOURCE_FILES})

# Include directories for both executables
target_include_directories(AudioObjectManager PRIVATE include)
target_include_directories(redo_example_main PRIVATE include)
