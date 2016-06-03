#ifndef __GRAPHICSENGINE_CLASS__
#define __GRAPHICSENGINE_CLASS__

#include <vector>

#include "../entity/Entity.hpp"

class GraphicsEngine
{
	public:
		GraphicsEngine();
		~GraphicsEngine();

		void render();
	private:
		std::vector<Entity*> entities;
		std::vector<Cam> cams;

		Cam activeCam;

		const Cam& getActiveCam();
		void initiateEntities();
};

#endif
