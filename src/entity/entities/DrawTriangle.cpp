#include "DrawTriangle.hpp"

#include "../../misc/Debug.hpp"

DrawTriangle::DrawTriangle(const Vec3D& p1, const Vec3D& p2, const Vec3D& p3)
	: point1(p1), point2(p2), point3(p3)
{
	Debug::warn("DrawTriangle::DrawTriangle(): TODO");
}

void DrawTriangle::render(const Cam& cam) const
{
	Debug::warn("DrawTriangle::render(): TODO");
}
