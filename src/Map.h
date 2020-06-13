#ifndef MAP_H
#define MAP_H

#include "Object3d.h"
#include "primitives3d.h"

class Map : public ComplexObject3d
{
private:
    static const int SIZE = 1000.0;

public:
    Map();

};

#endif // MAP_H