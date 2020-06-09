#ifndef MAP_H
#define MAP_H

#include "Object3d.h"

class Map : public Object3d
{
private:

public:
    Map(Vec3 position, Vec3 rotation, Vec3 color) 
    : Object3d(position, rotation, color) {}

    void render() override;

};



#endif // MAP_H