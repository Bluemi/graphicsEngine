#ifndef __CAM_CLASS__
#define __CAM_CLASS__

#include "../math/Vec3D.hpp"
#include "../math/Point2D.hpp"
#include "../entity/Entity.hpp"

class Cam : public Entity
{
	public:
		Cam(const Vec3D&);

		const Vec3D& getPosition() const override;
		const Vec3D& getDirectionFront() const;
		const Vec3D& getDirectionLeft() const;
		const Vec3D& getDirectionTop() const;
		Vec3D* getRotDirectionTop() const;
		float getXViewRange() const;
		float getYViewRange() const;

		void reactToMouseMove(int, int);

	private:
		void calcLeftDirection();

		// members
		Vec3D position;
		Vec3D directionFront;
		Vec3D directionLeft;
		Vec3D directionTop;

		int xScreenRange;
		int yScreenRange;
		float tele;
};

#endif
