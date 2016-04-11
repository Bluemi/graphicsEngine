#ifndef __ENTITY_CLASS__
#define __ENTITY_CLASS__

#include "../math/Vec3D.hpp"

class Entity
{
	public:
		Entity();
		virtual Vec3D* getPosition() const = 0;
	protected:
		virtual void setPosition(const Vec3D&) = 0;
};

#endif
