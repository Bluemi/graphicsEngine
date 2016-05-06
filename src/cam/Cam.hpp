#ifndef __CAM_CLASS__
#define __CAM_CLASS__

#include "../math/Vec3D.hpp"
#include "../entity/Entity.hpp"

class Cam : public Entity
{
	public:
		Cam(const Vec3D&);

		const Vec3D& getPosition() const override;
		const Vec3D& getFrontDirection() const;
		const Vec3D& getLeftDirection() const;
		const Vec3D& getTopDirection() const;

		void reactToMouseMove(int, int);

	private:
		void calcLeftDirection();

		// members
		Vec3D position;
		Vec3D directionFront;
		Vec3D directionLeft;
		Vec3D directionTop;
};

#endif
