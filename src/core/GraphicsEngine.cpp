#include "GraphicsEngine.hpp"

#include "../misc/Debug.hpp"
#include "../entity/entities/Plane.hpp"

GraphicsEngine::GraphicsEngine()
{
	// Initiate cams
	cams.push_back(Cam());
	activeCam = cams[0];
	initiateEntities();
}

GraphicsEngine::~GraphicsEngine()
{}

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

bool GraphicsEngine::isCamKeyEvent(const sf::Event& event) const
{
	switch (event.key.code)
	{
		case sf::Keyboard::W:
		{
			return true;
		}
		case sf::Keyboard::A:
		{
			return true;
		}
		case sf::Keyboard::S:
		{
			return true;
		}
		case sf::Keyboard::D:
		{
			return true;
		}
		case sf::Keyboard::Space:
		{
			return true;
		}
		case sf::Keyboard::LControl:
		{
			return true;
		}
		case sf::Keyboard::LShift:
		{
			return true;
		}
		default:
		{
			return false;
		}
	}
}

void GraphicsEngine::render()
{
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
	}*/
	activeCam.tick();
}

void GraphicsEngine::initiateEntities()
{
	entities.push_back(new Plane(
					Vec3D(2.f, 0.f, 0.f),
					Vec3D(3.f, 1.f, 3.f),
					Vec3D(3.f, -1.f, 1.f)));
}

const Cam& GraphicsEngine::getActiveCam()
{
	return activeCam;
}
