#include "Container.hpp"

Container::~Container()
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}

void Container::render(const Cam& cam) const
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->render(cam);
	}
}
