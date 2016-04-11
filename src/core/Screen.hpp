#ifndef __SCREEN_CLASS__
#define __SCREEN_CLASS__

#include <SFML/Graphics.hpp>

class Screen
{
	public:
		Screen();
		~Screen();
	private:
		sf::RenderWindow* window;
		sf::Color* backgroundColor;
};

#endif
