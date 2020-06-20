#include "Rover.hpp"
#include "pch.hpp"

#include "primitives3d.hpp"

std::array<Vec3, 8> body_points();

Rover::Rover()
    : ComplexObject3d(Vec3::zero(), Vec3::zero())
{
    Cylinder front_axle = Cylinder(160.0, 1.0, Vec3(20.0, 0.0, 4.0), Vec3(90, 0, 0), Vec3(0.1, 0.1, 0.1));
    Cylinder front_left_wheel =  Cylinder(0.5, 4.0, Vec3(20.0, 2.0, -4.0), Vec3(0, 0, 90), Vec3(0.1, 0.1, 0.4));
    Cylinder front_right_wheel = Cylinder(0.5, 4.0, Vec3(20.0, 2.0, 12.0), Vec3(0, 0, 90), Vec3(0.1, 0.1, 0.4));



    Object8points body = Object8points(body_points(), Vec3(20.0, 0.0, 5.0), Vec3(0.0, 0.0, 0.0), Vec3(1.0, 0.0, 0.0));



    this->objects3d.push_back(std::make_shared<Cylinder>(front_axle));
    this->objects3d.push_back(std::make_shared<Cylinder>(front_left_wheel));
    this->objects3d.push_back(std::make_shared<Cylinder>(front_right_wheel));
    this->objects3d.push_back(std::make_shared<Object8points>(body));


}



std::array<Vec3, 8> body_points()
{
    float x = 10.0, y = 30.0, z = 5.0;
    return std::array<Vec3, 8> {
        Vec3(0.0, 0.0, z  ),  
        Vec3(x  , 0.0, z  ), 
        Vec3(x  , y  , z  ),  
        Vec3(0.0, y  , z  ),  
        Vec3(0.0, 0.0, 0.0), 
        Vec3(x  , 0.0, 0.0),  
        Vec3(x  , y  , 0.0),  
        Vec3(0.0, y  , 0.0),  
    };
}