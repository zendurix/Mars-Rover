#ifndef OBJECT3D_H
#define OBJECT3D_H


#include "math.h"

class Object3d
{
protected:
    // x y z coordinates (0, 0, 0) is scene center
	Vec3 position;
    // Rotation angles for x y z axes
    Vec3 rotation;
    // RGB color
    Vec3 color;


public:
	inline Object3d(Vec3 position, Vec3 rotation, Vec3 color) 
    : position(position), rotation(rotation), color(color) {};

    // Overload this to write specific render function for each 3d object
	virtual void render() = 0;



	inline Vec3 get_position() { return position; }
	inline Vec3 get_rotation() { return rotation; }
	inline Vec3 get_color()    { return color; }

	inline void set_position(Vec3 set) { position = set; }
	inline void set_rotation(Vec3 set) { rotation = set; }
	inline void set_color(Vec3 set)    { color = set; }
};



class ComplexObject3d
{
protected:
    // x y z coordinates (0, 0, 0) is scene center
	Vec3 position;
    // Rotation angles for x y z axes
    Vec3 rotation;
    // RGB color
    Vec3 color;

	std::vector<std::shared_ptr<Object3d>> objects3d;

public:



	inline Vec3 get_position() { return position; }
	inline Vec3 get_rotation() { return rotation; }
	inline Vec3 get_color()    { return color; }

	inline std::vector<std::shared_ptr<Object3d>> get_objects3d() { return objects3d; }

	inline void set_position(Vec3 set) { position = set; }
	inline void set_rotation(Vec3 set) { rotation = set; }
	inline void set_color(Vec3 set)    { color = set; }
};


#endif // OBJECT3D_H