#ifndef __GRAPHICSENGINE_CLASS__
#define __GRAPHICSENGINE_CLASS__

#include <vector>

#include <SFML/Window.hpp>

#include "../entity/Entity.hpp"

class GraphicsEngine
{
	public:
		GraphicsEngine();
		~GraphicsEngine();

		void render();
		void handleKeyPressEvent(const sf::Event&);
	private:
		std::vector<Entity*> entities;
		std::vector<Cam> cams;

		Cam activeCam;

		const Cam& getActiveCam();
		void initiateEntities();
};

#endif
