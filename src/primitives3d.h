#ifndef PRIMITIVES3D_H
#define PRIMITIVES3D_H


#include "Object3d.h"

class Vec3;


class Cube : public Object3d
{
private:
	float length;


public:
	inline Cube(float length, Vec3 position) : length(length), Object3d(position) {}

	void render();


};




#endif // PRIMITIVES3D_H