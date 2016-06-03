#include "Cam.hpp"

#include "../misc/Debug.hpp"
#include "../core/Screen.hpp"

Cam::Cam(const Vec3D& pos)
	: position(pos), directionFront(1.f, 0.f, 0.f), directionTop(0.f, 0.f, 1.f), tele(30.f)
{
	calcLeftDirection();
}

Cam::Cam()
	: position(), directionFront(1.f, 0.f, 0.f), directionTop(0.f, 0.f, 1.f), tele(30.f)
{
	calcLeftDirection();
}

Vec3D Cam::getPosition() const
{
	return position;
}

const Vec3D& Cam::getDirectionFront() const
{
	return directionFront;
}

const Vec3D& Cam::getDirectionLeft() const
{
	return directionLeft;
}

// directionTop sollte immer gleich (0,0,1) sein
const Vec3D& Cam::getDirectionTop() const
{
	return directionTop;
}

Vec3D Cam::getRotDirectionTop() const
{
	Vec3D vec = Vec3D::vectorProduct(getDirectionFront(), getDirectionLeft());
	vec.normalize();
	return vec;
}

float Cam::getXViewRange() const
{
	return tele;
}

float Cam::getYViewRange() const
{
	return tele * ((float)Screen::getScreenSize().getY()/(float)Screen::getScreenSize().getX());
}

void Cam::reactToMouseMove(int x, int y)
{
	
}

void Cam::render(const Cam&) const
{
	Debug::warn("Cam::render(): TODO");
}

void Cam::setPosition(const Vec3D&)
{
	Debug::warn("Cam::setPosition(): TODO");
}

// Berechnet 'directionLeft' aus 'FrontDirection'
void Cam::calcLeftDirection()
{
	directionLeft.set(Vec3D::vectorProduct(getDirectionTop(), getDirectionFront()));
}
