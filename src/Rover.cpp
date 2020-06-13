#include "Rover.hpp"
#include "pch.hpp"

#include "primitives3d.hpp"

Rover::Rover()
    : ComplexObject3d(Vec3::zero(), Vec3::zero())
{
    Cylinder front_axle = Cylinder(30.0, 5.0, Vec3(20.0, 0.0, 4.0), Vec3(0, 0, 0), Vec3(0.1, 0.1, 0.1));

    this->objects3d.push_back(std::make_shared<Cylinder>(front_axle));
}

