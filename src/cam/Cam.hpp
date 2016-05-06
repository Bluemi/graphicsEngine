#ifndef __CAM_CLASS__
#define __CAM_CLASS__

#include "../math/Vec3D.hpp"
#include "../entity/Entity.hpp"

class Cam : public Entity
{
	public:
		Cam(const Vec3D&);

		virtual const Vec3D& getPosition() const override;
		virtual const Vec3D& getFrontDirection() const;

	private:
		Vec3D position;
		Vec3D directionFront;
		Vec3D directionLeft;
		Vec3D directionTop;
};

#endif
