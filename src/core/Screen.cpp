#include "Screen.hpp"

#include <SFML/Window.hpp>

#include "../misc/Debug.hpp"
#include "../misc/Converter.hpp"

const sf::Vector2i Screen::standartMousePosition(500, 500);

Screen::Screen(Main* m)
	: hasToKeepMousePosition(true)
{
	main = m;
	window = new sf::RenderWindow(sf::VideoMode(getScreenSize().getX(), getScreenSize().getY()), "GraphicsEngine", sf::Style::Fullscreen);
	backgroundColor = new sf::Color(20,20,30,255);
	window->clear(*backgroundColor);
	window->display();
	window->setMouseCursorVisible(false);
	window->setVisible(true);
	sf::Mouse::setPosition(standartMousePosition);
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
			case sf::Event::MouseMoved:
			{
				if (hasToKeepMousePosition)
				{
					main->handleMouseMoveEvent(event);
					keepMousePosition();
				}
				else
				{
					main->handleMouseMoveEvent(event);
				}
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

void Screen::clear()
{
	window->clear(*backgroundColor);
}

void Screen::display()
{
	window->display();
}

void Screen::renderShape(const sf::Shape& shape)
{
	window->draw(shape);
}

const Point2D& Screen::getScreenSize()
{
	static Point2D p(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
	return p;
}

void Screen::setHasToKeepMousePosition(bool k)
{
	hasToKeepMousePosition = k;
}

void Screen::keepMousePosition() const
{
	// Maus nur bewegen, wenn sie nicht schon auf der richtigen Position ist (sonst endlosschleife ;)
	if (!((sf::Mouse::getPosition().x == standartMousePosition.x) && sf::Mouse::getPosition().y == standartMousePosition.y))
	{
		sf::Mouse::setPosition(standartMousePosition);
	}
}
