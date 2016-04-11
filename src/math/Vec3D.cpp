#include "Vec3D.hpp"

Vec3D::Vec3D(float x, float y, float z)
	: x(x), y(y), z(z)
{}

Vec3D::Vec3D()
	: x(0.f), y(0.f), z(0.f)
{}

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

