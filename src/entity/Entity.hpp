#ifndef __ENTITY_CLASS__
#define __ENTITY_CLASS__

class Vec3D;
class Point2D;
class Cam;

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		virtual Vec3D getPosition() const = 0;
		virtual void render(const Cam&) const = 0;
		// virtual std::vector<std::string> getPossibleCommands;

		Point2D* from3Dto2D(const Vec3D&, const Cam&) const;
	protected:
		virtual void setPosition(const Vec3D&) = 0;
};

#include "../math/Vec3D.hpp"
#include "../math/Point2D.hpp"
#include "../cam/Cam.hpp"

#endif
