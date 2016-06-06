#include "Vec3D.hpp"

#include <cmath>

#include "../misc/Converter.hpp"
#include "../misc/Debug.hpp"

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

void Vec3D::set(const Vec3D& v)
{
	setX(v.getX());
	setY(v.getY());
	setZ(v.getZ());
}

// actions
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
// Rotation
void Vec3D::rotateX(float a)
{
	float yBackup = getY();
	float zBackup = getZ();
	setY(yBackup*cos(a) - zBackup*sin(a));
	setZ(yBackup*sin(a) + zBackup*cos(a));
}

void Vec3D::rotateY(float a)
{
	double xBackup = getX();
	double zBackup = getZ();
	setX(xBackup * cos(a) + zBackup * sin(a));
	setZ(xBackup * -sin(a) + zBackup * cos(a));
}

void Vec3D::rotateZ(float a)
{
	double xBackup = getX();
	double yBackup = getY();
	setX(xBackup*cos(a) - yBackup*sin(a));
	setY(xBackup*sin(a) + yBackup*cos(a));
}

void Vec3D::rotateUpDown(float a)
{
	Vec3D around = Vec3D::vectorProduct(*this, Vec3D(0,0,1));
	rotateAround(a, around);
}

// Lässt den Vektor this um die Ursprungsgrade mit dem Übergebenen Richtungsvektor rotieren
void Vec3D::rotateAround(float a, const Vec3D& vec)
{
	float xBackup = getX();
	float yBackup = getY();
	float zBackup = getZ();
	setX((xBackup * (vec.getX() * vec.getX() * (1 - cos(a)) + cos(a))) + /**/ 
		(yBackup * (vec.getX() * vec.getY() * (1 - cos(a)) - vec.getZ() * sin(a))) + /**/ 
		(zBackup * (vec.getX() * vec.getZ() * (1 - cos(a)) + vec.getY() * sin(a))));

	setY((xBackup * (vec.getY() * vec.getX() * (1 - cos(a)) + vec.getZ() * sin(a))) + /**/ 
		(yBackup * (vec.getY() * vec.getY() * (1 - cos(a)) + cos(a))) + /**/ 
		(zBackup * (vec.getY() * vec.getZ() * (1 - cos(a)) - vec.getX() * sin(a))));

	setZ((xBackup * (vec.getZ() * vec.getX() * (1 - cos(a)) - vec.getY() * sin(a))) + /**/
		(yBackup * (vec.getZ() * vec.getY() * (1 - cos(a)) + vec.getX() * sin(a))) + /**/
		(zBackup * (vec.getZ() * vec.getZ() * (1 - cos(a)) + cos(a))));
	
}

void Vec3D::addWith(const Vec3D& vec)
{
	x += vec.getX();
	y += vec.getY();
	z += vec.getZ();
}

void Vec3D::scaleWith(const float f)
{
	x *= f;
	y *= f;
	z *= f;
}

float Vec3D::getMagnitude() const
{
	return (float)sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

std::string Vec3D::toString() const
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

Vec3D Vec3D::vectorProduct(const Vec3D& a, const Vec3D& b)
{
	Vec3D vec;
	vec.setX(a.getY() * b.getZ() - a.getZ() * b.getY());
	vec.setY(a.getZ() * b.getX() - a.getX() * b.getZ());
	vec.setZ(a.getX() * b.getY() - a.getY() * b.getX());
	return vec;
}

float Vec3D::getDistance(const Vec3D& vec1, const Vec3D& vec2)
{
	Vec3D vec = vec1 - vec2;
	float f = vec.getMagnitude();
	return f;
}

float Vec3D::getDistanceToFlat(const Vec3D& flatPos, const Vec3D& flatNormVec, const Vec3D& point)
{
	Vec3D vec = point - flatPos; // Der Vektor von floatPos zu point
	Vec3D normalizedFloatNormVec(flatNormVec);
	normalizedFloatNormVec.normalize();
	float f = dotProduct(normalizedFloatNormVec, vec);
	return f;
}

Vec3D operator+(const Vec3D& vec1, const Vec3D& vec2)
{
	return Vec3D(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY(), vec1.getZ() + vec2.getZ());
}

Vec3D operator-(const Vec3D& vec1, const Vec3D& vec2)
{
	return Vec3D(vec1.getX() - vec2.getX(), vec1.getY() - vec2.getY(), vec1.getZ() - vec2.getZ());
}
