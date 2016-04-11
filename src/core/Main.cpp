#include "Main.hpp"

#include <iostream>

Main::Main()
{
	std::cout << " --- GraphicsEngine ---" << std::endl;
	screen = new Screen();
	run();
}

Main::~Main()
{
	delete screen;
}

void Main::run()
{
	sf::Clock clock;
	clock.restart();

	while (running)
	{
		if (clock.getElapsedTime().asMilliseconds() >= FRAME_RATE)
		{
			clock.restart();
			tick();
			render();
		}
	}
}

void Main::tick()
{
	
}

void Main::render()
{
	
}

void Main::exit()
{
	running = false;
}
