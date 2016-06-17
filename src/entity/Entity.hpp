#ifndef __ENTITY_CLASS__
#define __ENTITY_CLASS__

#include <string>

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

		Point2D from3Dto2D(const Vec3D&, const Cam&) const;

		void calculateDistanceToCam(const Cam&);
		float getDistanceToCam() const;

		virtual std::string toString() const;
	protected:
		virtual void setPosition(const Vec3D&) = 0;
	private:
		float distanceToCam;
};

bool distanceComp(Entity* e1, Entity* e2);


#include "../math/Vec3D.hpp"
#include "../math/Point2D.hpp"
#include "../cam/Cam.hpp"

#endif
