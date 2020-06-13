#ifndef MAP_HPP
#define MAP_HPP

#include "Object3d.hpp"
#include "primitives3d.hpp"

class Map : public ComplexObject3d
{
private:
    static const int SIZE = 1000.0;

public:
    Map();

};

#endif // MAP_HPP