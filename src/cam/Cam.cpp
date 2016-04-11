#include "Cam.hpp"

Cam::Cam(const Vec3D& pos)
	: position(pos), directionFront()
{}

const Vec3D& Cam::getPosition() const
{
	return position;
}

const Vec3D& Cam::getFrontDirection() const
{
	return directionFront;
}
