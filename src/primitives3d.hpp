#ifndef PRIMITIVES3D_HPP
#define PRIMITIVES3D_HPP


#include "Object3d.hpp"

class Vec3;


class Cube : public Object3d
{
private:
	float length;
public:
	inline Cube(float length, Vec3 position, Vec3 rotation, Vec3 color) 
    : length(length),
    Object3d(position, rotation, color) {}

	void render() override;
};



class Cylinder : public Object3d
{
private:
	float height;
	float radius;
public:
	inline Cylinder(float height, float radius, Vec3 position, Vec3 rotation, Vec3 color) 
    : height(height), radius(radius),
    Object3d(position, rotation, color) {}

	void render() override;
};



class Sphere : public Object3d
{
private:
	float radius;
public:
	inline Sphere(float radius, Vec3 position, Vec3 rotation, Vec3 color) 
    : radius(radius),
    Object3d(position, rotation, color) {}

	void render() override;
};

class Rectangle : public Object3d
{
private:
	float height;
	float length;

public:
    inline Rectangle(float height, float length, Vec3 position, Vec3 rotation, Vec3 color) 
    : height(height), length(length), 
	Object3d(position, rotation, color) {}

    void render() override;
};


#endif // PRIMITIVES3D_HPP