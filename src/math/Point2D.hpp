#ifndef __POINT2D_CLASS__
#define __POINT2D_CLASS__

#include <string>

#include <SFML/Graphics.hpp>

class Point2D
{
	public:
		Point2D(int, int);
		Point2D();

		int getX() const;
		int getY() const;

		void setX(int);
		void setY(int);

		sf::Vector2f getSFVec() const;
		std::string toString() const;
	private:
		int x, y;
};

#endif
