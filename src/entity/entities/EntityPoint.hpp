#ifndef __ENTITYPOINT_CLASS__
#define __ENTITYPOINT_CLASS__

#include "../Entity.hpp"

class Cam;

class EntityPoint : public Entity
{
	public:
		virtual void render(const Cam&) const override;
};

#include "../../cam/Cam.hpp"

#endif
