#ifndef __CAM_CLASS__
#define __CAM_CLASS__

#include "../math/Vec3D.hpp"
#include "../math/Point2D.hpp"
#include "../entity/Entity.hpp"

class Cam : public Entity
{
	public:
		// Constructor
		Cam(const Vec3D& = Vec3D());

		// Vecs
		Vec3D getPosition() const override;
		const Vec3D& getDirectionFront() const;
		const Vec3D& getDirectionLeft() const;
		const Vec3D& getDirectionTop() const;
		const Vec3D& getSpeed() const;
		Vec3D getRotDirectionTop() const;

		// ViewRange
		float getXViewRange() const;
		float getYViewRange() const;

		// Events
		void reactToMouseMove(int, int);
		void handleKeyPressEvent(const sf::Event&);
		void handleKeyReleaseEvent(const sf::Event&);

		void render(const Cam&) const override;
		void tick();
		void setPosition(const Vec3D&) override;

		static const float DEFAULT_VIEW_RANGE_X;
		static const float DEFAULT_DRAG;
		static const float DEFAULT_ACCELERATION;
		static const float FAST_ACCELERATION;
	private:
		void calcLeftDirection();
		void updateSpeed();

		// Vecs
		Vec3D position;
		Vec3D directionFront;
		Vec3D directionLeft;
		Vec3D directionTop;
		Vec3D speed;

		bool isMovingUp = false;
		bool isMovingDown = false;
		bool isMovingLeft = false;
		bool isMovingRight = false;
		bool isMovingFront = false;
		bool isMovingBack = false;
		bool isMovingFast = false; // shift is pressed

		// ViewRange
		float tele;
};

#endif
