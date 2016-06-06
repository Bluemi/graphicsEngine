#ifndef __SCREEN_CLASS__
#define __SCREEN_CLASS__

#include <SFML/Graphics.hpp>

class Point2D;
class Main;

class Screen
{
	public:
		Screen(Main*);
		~Screen();

		static const Point2D& getScreenSize();
		static const sf::Vector2i& getStandartMousePosition();
		void handleEvents() const;
		void renderShape(const sf::Shape&);

		void display();
		void clear();

		void setHasToKeepMousePosition(bool);
		static const sf::Vector2i standartMousePosition;
	private:
		Main* main;
		sf::RenderWindow* window;
		sf::Color* backgroundColor;

		bool hasToKeepMousePosition;
		void keepMousePosition() const;
};

#include "Main.hpp"
#include "../math/Point2D.hpp"

#endif
