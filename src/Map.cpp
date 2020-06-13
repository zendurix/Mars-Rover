#include "Map.hpp"
#include "pch.hpp"

#include "math.hpp"

#include "primitives3d.hpp"

Map::Map()
    : ComplexObject3d(Vec3::zero(), Vec3::zero())
{
    const int SQUARE_SIZE = 5;
    for (int i = 0, count = 0; i < SIZE; i += SQUARE_SIZE, count++)
    {
        for (int j = 0; j < SIZE; j += SQUARE_SIZE, count++)
        {
            Vec3 col = (count % 2 == 0) ? Vec3(1.0, 0.0, 1.0) : Vec3::zero();
            Rectangle rec = Rectangle(SQUARE_SIZE, SQUARE_SIZE, Vec3(i, j, 0), Vec3::zero(), col);
            this->objects3d.push_back(std::make_shared<Rectangle>(rec));
        }
    }
}
