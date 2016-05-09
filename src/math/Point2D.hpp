#ifndef __POINT2D_CLASS__
#define __POINT2D_CLASS__

class Point2D
{
	public:
		Point2D(int, int);
		Point2D();

		int getX() const;
		int getY() const;

		void setX(int);
		void setY(int);
	private:
		int x, y;
};

#endif
