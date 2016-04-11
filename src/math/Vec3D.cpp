#include "Vec3D.hpp"

Vec3D::Vec3D(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

float Vec3D::getX() const
{
	return x;
}

float Vec3D::getY() const
{
	return y;
}

float Vec3D::getZ() const
{
	return z;
}

