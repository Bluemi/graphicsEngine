#include "Plane.hpp"

#include "../../misc/Debug.hpp"
#include "../../math/Point2D.hpp"
#include "../../core/Main.hpp"

Plane::Plane(const Vec3D& p1, const Vec3D& p2, const Vec3D& p3, const sf::Color c)
	: point1(p1), point2(p2), point3(p3), color(c)
{}

void Plane::render(const Cam& cam) const
{
	Point2D p1 = from3Dto2D(point1, cam);
	Point2D p2 = from3Dto2D(point2, cam);
	Point2D p3 = from3Dto2D(point3, cam);

	sf::ConvexShape convex;

	convex.setPointCount(3);

	convex.setPoint(0, p1.getSFVec());
	convex.setPoint(1, p2.getSFVec());
	convex.setPoint(2, p3.getSFVec());

	convex.setFillColor(color);

	Main::getScreen()->renderShape(convex);
}

Vec3D Plane::getPosition() const
{
	return Vec3D(	(point1.getX() + point2.getX() + point3.getX())/3.f,
			(point1.getY() + point2.getY() + point3.getY())/3.f,
			(point1.getZ() + point2.getZ() + point3.getZ())/3.f);
}

void Plane::setPosition(const Vec3D&)
{
	Debug::warn("Plane::setPosition(): TODO");
}
