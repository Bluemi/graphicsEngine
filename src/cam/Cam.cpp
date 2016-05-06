#include "Cam.hpp"

Cam::Cam(const Vec3D& pos)
	: position(pos), directionFront(), directionLeft(), directionTop()
{}

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

const Vec3D& Cam::getTopDirection() const
{
	return directionTop;
}

void Cam::reactToMouseMove(int x, int y)
{
	
}

void Cam::calcDirections()
{
}
