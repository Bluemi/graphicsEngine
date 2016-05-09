#include "Screen.hpp"

#include <SFML/Window.hpp>

#include "../misc/Debug.hpp"
#include "../misc/Converter.hpp"

extern Point2D Screen::screenSize;

Screen::Screen(Main* m)
{
	main = m;
	window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "GraphicsEngine", sf::Style::Fullscreen);
	backgroundColor = new sf::Color(20,20,30,255);
	window->clear(*backgroundColor);
	window->display();
	window->setMouseCursorVisible(false);
	window->setVisible(true);

	screenSize.setX(window->getSize().x);
	screenSize.setY(window->getSize().y);
}

Screen::~Screen()
{
	delete window;
	window = NULL;
	delete backgroundColor;
	backgroundColor = NULL;
	delete backgroundColor;
	backgroundColor = NULL;
}

void Screen::handleEvents() const
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
			{
				Debug::warn("Screen::handleEvents(): CloseEvent triggered");
				break;
			}
			case sf::Event::KeyPressed:
			{
				main->handleKeyPressEvent(event);
				break;
			}
			case sf::Event::KeyReleased:
			{
				main->handleKeyReleaseEvent(event);
				break;
			}
			default:
			{
				//Debug::warn("Screen::handleEvents(): other Event triggered");
				break;
			}
		}
	}
}

const Point2D& Screen::getScreenSize()
{
	return screenSize;
}
