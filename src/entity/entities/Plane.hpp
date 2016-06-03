#ifndef __PLANE_CLASS__
#define __PLANE_CLASS__

#include "../Entity.hpp"
#include "../../math/Vec3D.hpp"

class Cam;

class Plane : public Entity
{
	public:
		Plane(const Vec3D& p1, const Vec3D& p2, const Vec3D& p3);
		void render(const Cam& cam) const override;
		Vec3D getPosition();
	private:
		Vec3D point1;
		Vec3D point2;
		Vec3D point3;
};

#include "../../cam/Cam.hpp"

#endif
