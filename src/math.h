#ifndef MATH_H
#define MATH_H


const float PI = 3.14159265f;


class Vec3
{
public:
	float x;
	float y;
	float z;

	inline Vec3(float x, float y, float z)
		: x(x), y(y), z(z) {}
};




#endif // MATH_H