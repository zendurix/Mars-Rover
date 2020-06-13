#include "Map.h"
#include "pch.h"

#include "math.h"

#include "primitives3d.h"

Map::Map()
    : ComplexObject3d(Vec3::zero(), Vec3::zero())
{
    const int SQUARE_SIZE = 19;
    for (int i = 0; i < SIZE; i += SQUARE_SIZE)
    {
        for (int j = 0; j < SIZE; j += SQUARE_SIZE)
        {
            Vec3 col = Vec3(1.0, 0.0, 1.0);
            Rectangle rec = Rectangle(SQUARE_SIZE, SQUARE_SIZE, Vec3(i, j, 0), Vec3::zero(), col);
            this->objects3d.push_back(std::make_shared<Rectangle>(rec));
        }
    }
}
