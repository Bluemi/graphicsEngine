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
		void tick();
		void handleKeyPressEvent(const sf::Event&);
		void handleKeyReleaseEvent(const sf::Event&);
	private:
		std::vector<Entity*> entities;
		std::vector<Cam> cams;

		Cam activeCam;

		bool isCamKeyEvent(const sf::Event&) const;
		const Cam& getActiveCam();
		void initiateEntities();
};

#endif
