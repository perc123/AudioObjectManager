//
// Created by fanis on 17.11.2023.
//

#ifndef AUDIOOBJECT_H
#define AUDIOOBJECT_H

struct Position {
    float x, y, z;
};

struct AudioObject {
    int id;
    Position position;

    AudioObject();
    AudioObject(int _id, float _x, float _y, float _z);
};

#endif // AUDIOOBJECT_H
