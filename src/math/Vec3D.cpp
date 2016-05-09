#include "Vec3D.hpp"

#include <cmath>

#include "../misc/Converter.hpp"

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

void Vec3D::setX(float argx)
{
	x = argx;
}

void Vec3D::setY(float argy)
{
	y = argy;
}

void Vec3D::setZ(float argz)
{
	z = argz;
}

void Vec3D::normalize()
{
	float m = getMagnitude();
	if (m == 0)
	{
		return;
	}
	setX(getX() / m);
	setY(getY() / m);
	setZ(getZ() / m);
}

float Vec3D::getMagnitude() const
{
	return (float)sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

std::string Vec3D::getString() const
{
	return "(" + Converter::floatToString(getX()) + "|" + Converter::floatToString(getY()) + "|" + Converter::floatToString(getZ()) + ")";
}

bool Vec3D::equal(const Vec3D& vec)
{
	return (vec.getX() == getX()) && (vec.getY() == getY()) && (vec.getZ() == getZ()); 
}

float Vec3D::dotProduct(const Vec3D& vec1, const Vec3D& vec2)
{
	return  vec1.getX() * vec2.getX() +
		vec1.getY() * vec2.getY() +
		vec1.getZ() * vec2.getZ();
}

Vec3D* Vec3D::vectorProduct(const Vec3D& a, const Vec3D& b)
{
	Vec3D* vec = new Vec3D();
	vec->setX(a.getY() * b.getZ() - a.getZ() * b.getY());
	vec->setY(a.getZ() * b.getX() - a.getX() * b.getZ());
	vec->setZ(a.getX() * b.getY() - a.getY() * b.getX());
	return vec;
}

float Vec3D::getDistance(const Vec3D& vec1, const Vec3D& vec2)
{
	Vec3D* vec = vec1 - vec2;
	float f = vec->getMagnitude();
	delete vec;
	return f;
}

float Vec3D::getDistanceToFlat(const Vec3D& flatPos, const Vec3D& flatNormVec, const Vec3D& point)
{
	Vec3D* vec = point - flatPos; // Der Vektor von floatPos zu point
	Vec3D normalizedFloatNormVec = Vec3D(flatNormVec);
	normalizedFloatNormVec.normalize();
	float f = dotProduct(normalizedFloatNormVec, *vec);
	delete vec;
	return f;
}

Vec3D* operator+(const Vec3D& vec1, const Vec3D& vec2)
{
	return new Vec3D(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY(), vec1.getZ() + vec2.getZ());
}

Vec3D* operator-(const Vec3D& vec1, const Vec3D& vec2)
{
	return new Vec3D(vec1.getX() - vec2.getX(), vec1.getY() - vec2.getY(), vec1.getZ() - vec2.getZ());
}
