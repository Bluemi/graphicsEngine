#include "Screen.hpp"

Screen::Screen()
{
	window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Graphics-Engine", sf::Style::Fullscreen);
}
