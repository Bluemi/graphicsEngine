#include "Main.hpp"

#include <iostream>
#include <SFML/Window.hpp>

Main::Main()
{
	std::cout << " --- GraphicsEngine ---" << std::endl;
	screen = new Screen();
	run();
}

Main::~Main()
{
	delete screen;
	std::cout << " ---      END       ---" << std::endl;
}

void Main::run()
{
	sf::Clock clock;
	clock.restart();

	while (running)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::End) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			exit();
			break;
		}
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
