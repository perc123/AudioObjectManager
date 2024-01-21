//
// Created by fanis on 17.11.2023.
//

#include "../include/AudioObject.h"

AudioObject::AudioObject() : id(0), position({0.0, 0.0, 0.0}) {}

AudioObject::AudioObject(int _id, float _x, float _y, float _z)
        : id(_id), position({ _x, _y, _z }) {}
