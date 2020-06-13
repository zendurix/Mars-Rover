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

class Vec2
{
public:
	float x;
	float y;

	inline Vec2(float x, float y)
		: x(x), y(y) {}
};



#endif // MATH_H