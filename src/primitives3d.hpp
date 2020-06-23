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



class Object8points : public Object3d
{
private:
	std::array<Vec3, 8> points;

public:
	// Start drawing points from (0,0,0), and move them with set_position() or move()
	/*	Order of points:
	*	lower base	upper base
	* 	2-----3		6-----7
	*	|     |		|	  |
	*	0-----1		4-----5
	*/
	inline Object8points(std::array<Vec3, 8> points, Vec3 position, Vec3 rotation, Vec3 color)
		: points(points),
		Object3d(position, rotation, color) {}

	void render() override;

	inline std::array<Vec3, 8> get_points() { return points; }
};




#endif // PRIMITIVES3D_HPP