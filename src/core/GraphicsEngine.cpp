#include "GraphicsEngine.hpp"

#include <functional>

#include "../misc/Debug.hpp"
#include "../entity/entities/Plane.hpp"
#include "../core/Screen.hpp"

GraphicsEngine::GraphicsEngine()
{
	// Initiate cams
	cams.push_back(Cam());
	activeCam = cams[0];
	initiateEntities();
}

GraphicsEngine::~GraphicsEngine()
{
	for (Entity* e : entities)
	{
		delete e;
	}
}

void GraphicsEngine::handleKeyPressEvent(const sf::Event& event)
{
	if (isCamKeyEvent(event))
	{
		activeCam.handleKeyPressEvent(event);
	}
}

void GraphicsEngine::handleKeyReleaseEvent(const sf::Event& event)
{
	if (isCamKeyEvent(event))
	{
		activeCam.handleKeyReleaseEvent(event);
	}
}

void GraphicsEngine::handleMouseMoveEvent(const sf::Event& event)
{
	// Umrechnen von event -> Point2D
	activeCam.handleMouseMoveEvent(Point2D(event.mouseMove.x - Screen::standartMousePosition.x, -(event.mouseMove.y - Screen::standartMousePosition.y)));
}

bool GraphicsEngine::isCamKeyEvent(const sf::Event& event) const
{
	switch (event.key.code)
	{
		case sf::Keyboard::W:
		case sf::Keyboard::A:
		case sf::Keyboard::S:
		case sf::Keyboard::D:
		case sf::Keyboard::Space:
		case sf::Keyboard::LControl:
		case sf::Keyboard::LShift:
		case sf::Keyboard::E:
			return true;
		default:
		{
			return false;
		}
	}
}

void GraphicsEngine::render()
{
	for (Entity* e : entities)
	{
		e->calculateDistanceToCam(getActiveCam());
	}

	std::sort(entities.begin(), entities.end(), distanceComp);

/*
	Debug::test("\nPostSort");

	for (Entity* e : entities)
	{
		Debug::test("\t" + e->toString());
	}
*/

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i]->render(getActiveCam());
	}
}

void GraphicsEngine::tick()
{
	/*
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i]->tick();
	}
	*/
	activeCam.tick();

	// sort entities
	
}

void GraphicsEngine::initiateEntities()
{
	entities.push_back(new Plane(
					Vec3D(0.f, 0.f, 0.f),
					Vec3D(0.f, 0.f, 1.f),
					Vec3D(0.f, 1.f, 1.f),
					sf::Color(100, 100, 100)));
	entities.push_back(new Plane(
					Vec3D(0.f, 0.f, 0.f),
					Vec3D(0.f, 1.f, 0.f),
					Vec3D(0.f, 1.f, 1.f),
					sf::Color(100, 100, 100)));
	entities.push_back(new Plane(
					Vec3D(1.f, 0.f, 0.f),
					Vec3D(1.f, 0.f, 1.f),
					Vec3D(1.f, 1.f, 1.f),
					sf::Color(200, 200, 200)));
	entities.push_back(new Plane(
					Vec3D(1.f, 0.f, 0.f),
					Vec3D(1.f, 1.f, 0.f),
					Vec3D(1.f, 1.f, 1.f),
					sf::Color(200, 200, 200)));
	entities.push_back(new Plane(
					Vec3D(0.f, 0.f, 1.f),
					Vec3D(1.f, 0.f, 1.f),
					Vec3D(1.f, 1.f, 1.f),
					sf::Color(130, 130, 130)));
	entities.push_back(new Plane(
					Vec3D(0.f, 0.f, 1.f),
					Vec3D(0.f, 1.f, 1.f),
					Vec3D(1.f, 1.f, 1.f),
					sf::Color(130, 130, 130)));
}

const Cam& GraphicsEngine::getActiveCam()
{
	return activeCam;
}
