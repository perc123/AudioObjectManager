//
// Created by fanis on 17.11.2023.
//

#ifndef AUDIOOBJECTMANAGER_H
#define AUDIOOBJECTMANAGER_H

#include <iostream>
#include <unordered_map>
#include <stack>
#include "AudioObject.h"

class AudioObjectManager {
private:
    std::unordered_map<int, AudioObject> objects;
    std::stack<std::pair<std::string, AudioObject>> actionHistory; // For undo functionality
    std::stack<std::pair<std::string, AudioObject>> redoHistory; // For redo functionality


public:
    void add(const AudioObject & obj);
    void remove(int objectId);
    void changePosition(int objectId, float newX, float newY, float newZ);
    void undo();
    void redo();
    void printState() const;
};

#endif
