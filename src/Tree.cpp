#include "Tree.hpp"
#include "pch.hpp"

#include "primitives3d.hpp"

// Mars trees*
Tree::Tree(float pos_x, float pos_y)
    : ComplexObject3d(Vec3::zero(), Vec3::zero())
{
    Cylinder trunk = Cylinder(25.0, 3.0, Vec3(pos_x, pos_y, -10.0), Vec3(0, 0, 0), normalize_rgb(Vec3(139, 69, 19)));
    Sphere branches = Sphere(7.0,  Vec3(pos_x, pos_y, -20.0), Vec3::zero(), normalize_rgb(Vec3(50, 205, 50)));
    Sphere branches1 = Sphere(5.0,  Vec3(pos_x+5.0, pos_y, -20.0 - 2.0), Vec3::zero(), normalize_rgb(Vec3(50, 235, 50)));
    Sphere branches2 = Sphere(5.0,  Vec3(pos_x, pos_y + 5.0, -20.0), Vec3::zero(), normalize_rgb(Vec3(50, 225, 50)));
    Sphere branches3 = Sphere(5.0,  Vec3(pos_x- 5.0, pos_y + 1.0, -20.0), Vec3::zero(), normalize_rgb(Vec3(50, 225, 70)));

    this->objects3d.push_back(std::make_shared<Cylinder>(trunk));
    this->objects3d.push_back(std::make_shared<Sphere>(branches));
    this->objects3d.push_back(std::make_shared<Sphere>(branches1));
    this->objects3d.push_back(std::make_shared<Sphere>(branches2));
    this->objects3d.push_back(std::make_shared<Sphere>(branches3));
}
