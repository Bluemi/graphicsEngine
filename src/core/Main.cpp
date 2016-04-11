#include "Main.hpp"

#include <iostream>

Main::Main()
{
	std::cout << " --- GraphicsEngine ---" << std::endl;
	run();
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
