#ifndef __SCREEN_CLASS__
#define __SCREEN_CLASS__

#include <SFML/Graphics.hpp>

class Main;

class Screen
{
	public:
		Screen(Main*);
		~Screen();
		void handleEvents() const;
	private:
		Main* main;
		sf::RenderWindow* window;
		sf::Color* backgroundColor;
};

#include "Main.hpp"

#endif
