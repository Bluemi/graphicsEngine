#ifndef __VEC3D_CLASS__
#define __VEC3D_CLASS__

#include <string>

class Vec3D
{
	public:
		Vec3D(float, float, float);
		Vec3D();

		// getter
		float getX() const;
		float getY() const;
		float getZ() const;

		// setter
		void setX(float);
		void setY(float);
		void setZ(float);

		void set(const Vec3D&);

		// actions
		void normalize();

		// calc
		void addWith(const Vec3D&);
		void scaleWith(const float);

		// info
		float getMagnitude() const;
		std::string toString() const;
		static float getDistanceToFlat(const Vec3D&, const Vec3D&, const Vec3D&);
		static float dotProduct(const Vec3D& vec1, const Vec3D& vec2);
		static Vec3D vectorProduct(const Vec3D& vec1, const Vec3D& vec2);
		static float getDistance(const Vec3D&, const Vec3D&);

		bool equal(const Vec3D&);
	private:
		float x, y, z;
};

Vec3D operator+(const Vec3D& vec1, const Vec3D& vec2);
Vec3D operator-(const Vec3D& vec1, const Vec3D& vec2);

#endif
