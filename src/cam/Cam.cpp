#include "Cam.hpp"

#include "../misc/Debug.hpp"

Cam::Cam(const Vec3D& pos)
	: position(pos), directionFront(1.f, 0.f, 0.f), directionLeft(), directionTop(0.f, 0.f, 1.f)
{
	calcLeftDirection();
}

const Vec3D& Cam::getPosition() const
{
	return position;
}

const Vec3D& Cam::getFrontDirection() const
{
	return directionFront;
}

const Vec3D& Cam::getLeftDirection() const
{
	return directionLeft;
}

// directionTop sollte immer gleich (0,0,1) sein
const Vec3D& Cam::getTopDirection() const
{
	return directionTop;
}

void Cam::reactToMouseMove(int x, int y)
{
	
}

// Berechnet 'directionLeft' aus 'FrontDirection'
void Cam::calcLeftDirection()
{
	//Vec3D* vec = Vec3D::getCrossProduct
	// TODO
}
