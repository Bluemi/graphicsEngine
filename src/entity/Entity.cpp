#include "Entity.hpp"

#include "../misc/Debug.hpp"

Entity::Entity()
{}

Entity::~Entity()
{}

Point2D* Entity::from3Dto2D(const Vec3D& vec, const Cam& cam) const
{
	
	Debug::warn("Entity::from3Dto2D(): TODO");
	return new Point2D();
}