#ifndef OBJECT3D_H
#define OBJECT3D_H


#include "math.h"

class Object3d
{
private:
	Vec3 position;


public:
	inline Object3d(Vec3 position) : position(position) {};

	virtual void render() = 0;

	inline Vec3 get_position() { return position; }
	inline void set_position(Vec3 set) { position = set; }
};


#endif // OBJECT3D_H