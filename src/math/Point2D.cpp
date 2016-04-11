#include "Point2D.hpp"

Point2D::Point2D(int ax, int ay)
	: x(ax), y(ay)
{}

Point2D::Point2D()
	: x(0), y(0)
{}

int Point2D::getX() const
{
	return x;
}

int Point2D::getY() const
{
	return y;
}
