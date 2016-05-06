#include "Main.hpp"

#include <iostream>
#include <SFML/Window.hpp>

#include "../misc/Debug.hpp"

Main::Main()
{
	std::cout << " --- GraphicsEngine ---" << std::endl;
 	running = true;
	screen = new Screen(this);
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
		Debug::warnIf(screen == NULL, "Main::run(): screen == NULL");
		screen->handleEvents();
		if (clock.getElapsedTime().asMilliseconds() >= FRAME_RATE)
		{
			clock.restart();
			tick();
			render();
		}
	}
}

void Main::handleKeyPressEvent(const sf::Event& event) const
{
}

void Main::handleKeyReleaseEvent(const sf::Event& event) const
{
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
