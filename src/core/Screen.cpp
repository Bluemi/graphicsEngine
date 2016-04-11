#include "Screen.hpp"

Screen::Screen()
{
	window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "GraphicsEngine", sf::Style::Fullscreen);
	backgroundColor = new sf::Color(20,20,30,255);
	window->clear(*backgroundColor);
	window->display();
	window->setMouseCursorVisible(false);
	window->setVisible(true);
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
