#ifndef __GRAPHICSENGINE_CLASS__
#define __GRAPHICSENGINE_CLASS__

#include <vector>

#include "../entity/Entity.hpp"

class GraphicsEngine
{
	public:
		GraphicsEngine();
		~GraphicsEngine();
	private:
		std::vector<Entity> entities;
};

#endif
