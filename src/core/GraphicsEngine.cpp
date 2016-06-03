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

void GraphicsEngine::initiateEntities()
{
	entities.push_back(new Plane(
					Vec3D(2.f, 0.f, 0.f),
					Vec3D(3.f, 1.f, 3.f),
					Vec3D(3.f, -1.f, 1.f)));
}

void GraphicsEngine::render()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i]->render(getActiveCam());
	}
}

const Cam& GraphicsEngine::getActiveCam()
{
	return activeCam;
}
