#ifndef __SCREEN_CLASS__
#define __SCREEN_CLASS__

#include <SFML/Graphics.hpp>

#include "../math/Point2D.hpp"

class Main;

class Screen
{
	public:
		Screen(Main*);
		~Screen();

		static const Point2D& getScreenSize();
		void handleEvents() const;
		void renderShape(const sf::Shape&);

		void display();
		void clear();
	private:
		Main* main;
		sf::RenderWindow* window;
		sf::Color* backgroundColor;
};

#include "Main.hpp"

#endif
