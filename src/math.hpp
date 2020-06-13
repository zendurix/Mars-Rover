#ifndef MATH_HPP
#define MATH_HPP


const float PI = 3.14159265f;


class Vec3
{
public:
	float x;
	float y;
	float z;

	inline Vec3(float x, float y, float z)
		: x(x), y(y), z(z) {}

	inline Vec3 operator + (Vec3 vec)
	{
		return Vec3(this->x += vec.x, this->y += vec.y, this->z += vec.z);
	}
	inline Vec3 operator - (Vec3 vec)
	{
		return Vec3(this->x -= vec.x, this->y -= vec.y, this->z -= vec.z);
	}
	inline void operator += (Vec3 vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z =- vec.z;
	}
	inline void operator -= (Vec3 vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
	}

	inline static Vec3 zero() { return Vec3(0, 0, 0); }
};

class Vec2
{
public:
	float x;
	float y;

	inline Vec2(float x, float y)
		: x(x), y(y) {}
	
	inline static Vec2 zero() { return Vec2(0, 0); }
};



inline void normalize_rgb(Vec3* rgb)
{
    rgb->x /= 255.0;
    rgb->y /= 255.0;
    rgb->z /= 255.0;
}



#endif // MATH_HPP