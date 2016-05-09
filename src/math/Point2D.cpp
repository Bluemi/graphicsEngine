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

void Point2D::setX(int argx)
{
	x = argx;
}

void Point2D::setY(int argy)
{
	y = argy;
}
