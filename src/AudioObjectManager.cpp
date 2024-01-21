//
// Created by fanis on 17.11.2023.
//

#include <vector>
#include <algorithm>
#include "../include/AudioObjectManager.h"


void AudioObjectManager::add(const AudioObject & obj) {
    objects[obj.id] = obj;
    std::cout << "Added AudioObject with Id " << obj.id << " in Position (" << obj.position.x << ", "
            << obj.position.y << ", "
            << obj.position.z << ")" << std::endl;
}

void AudioObjectManager::remove(int objectId) {
    auto it = objects.find(objectId);
    if (it != objects.end()) {
        actionHistory.emplace("remove", it->second);
        std::cout << "Removed AudioObject with Id " << objectId << std::endl;
        objects.erase(it);
    } else {
        std::cout << "AudioObject with Id " << objectId << " not found." << std::endl;
    }
}

void AudioObjectManager::changePosition(int objectId, float newX, float newY, float newZ) {
    auto it = objects.find(objectId);
    if (it != objects.end()) {
        actionHistory.emplace("changePosition", it->second);
        it->second.position = {newX, newY, newZ};
        std::cout << "Changed position of AudioObject with Id " << objectId <<" in Position (" << newX << ", "
                                                                                             << newY << ", "
                                                                                             << newZ << ")"<< std::endl;
    } else {
        std::cout << "AudioObject with Id " << objectId << " not found." << std::endl;
    }
}

void AudioObjectManager::undo() {
    if (!actionHistory.empty()) {
        auto lastAction = actionHistory.top();
        actionHistory.pop();

        redoHistory.push(lastAction); // Store the action in redoHistory stack

        if (lastAction.first == "remove") {
            objects[lastAction.second.id] = lastAction.second;
            std::cout << "Undoing removal of AudioObject with Id " << lastAction.second.id << std::endl;
        } else if (lastAction.first == "changePosition") {
            while (!actionHistory.empty() && actionHistory.top().first == "changePosition" &&
                   actionHistory.top().second.id == lastAction.second.id) {
                // Revert all successive ChangePosition actions on the same object
                lastAction = actionHistory.top();
                actionHistory.pop();
            }
            objects[lastAction.second.id].position = lastAction.second.position;
            std::cout << "Undoing position change of AudioObject with Id " << lastAction.second.id << std::endl;
        } else if (lastAction.first == "add") {
            objects.erase(lastAction.second.id);
            std::cout << "Undoing addition of AudioObject with Id " << lastAction.second.id << std::endl;
        }
    } else {
        std::cout << "No actions to undo." << std::endl;
    }
}

void AudioObjectManager::redo() {
    if (!redoHistory.empty()) {
        auto nextAction = redoHistory.top();
        redoHistory.pop();

        actionHistory.push(nextAction); // Store the action in actionHistory stack

        if (nextAction.first == "remove") {
            remove(nextAction.second.id);
            std::cout << "Redoing removal of AudioObject with Id " << nextAction.second.id << std::endl;
        } else if (nextAction.first == "changePosition") {
            changePosition(nextAction.second.id, nextAction.second.position.x,
                           nextAction.second.position.y, nextAction.second.position.z);
            std::cout << "Redoing position change of AudioObject with Id " << nextAction.second.id << std::endl;
        } else if (nextAction.first == "add") {
            objects[nextAction.second.id] = nextAction.second;
            std::cout << "Redoing addition of AudioObject with Id " << nextAction.second.id << std::endl;
        }
    } else {
        std::cout << "No actions to redo." << std::endl;
    }
}

void AudioObjectManager::printState() const {
    std::cout << "Current state of AudioObjects:" << std::endl;

    // Copy IDs to a vector to be able to sort
    std::vector<int> sortedIds;
    sortedIds.reserve(objects.size());
for (const auto& pair : objects) {
        sortedIds.push_back(pair.first);
    }

    // Sort the vector in ascending order
    std::sort(sortedIds.begin(), sortedIds.end());

    // Iterate and print AudioObjects
    for (const int& objectId : sortedIds) {
        const AudioObject& obj = objects.at(objectId);
        std::cout << "Object with Id " << obj.id
                  << " has position (" << obj.position.x << ", "
                  << obj.position.y << ", " << obj.position.z << ")" << std::endl;
    }
}
