#ifndef __CONTAINER_CLASS__
#define __CONTAINER_CLASS__

#include <vector>

#include "../Entity.hpp"

class Cam;

class Container : public Entity
{
	public:
		virtual ~Container();
		virtual void render(const Cam&) const override;

	private:
		std::vector<Entity*> components;
};

#include "../../cam/Cam.hpp"

#endif
