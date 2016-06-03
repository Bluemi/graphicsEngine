#include "Plane.hpp"

#include "../../misc/Debug.hpp"

Plane::Plane(const Vec3D& p1, const Vec3D& p2, const Vec3D& p3)
	: point1(p1), point2(p2), point3(p3)
{
	Debug::warn("Plane::Plane(): TODO");
}

void Plane::render(const Cam& cam) const
{
	Debug::warn("Plane::render(): TODO");
}
