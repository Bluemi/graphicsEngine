#include "Entity.hpp"

#include <cmath>

#include "../misc/Debug.hpp"
#include "../misc/Converter.hpp"
#include "../core/Screen.hpp"

Entity::Entity()
{}

Entity::~Entity()
{}

/*
	viewVec		sei der Vector von Cam.Position zu 'vec'
	verticalFlat	sei die Ebene durch Cam.Pos und dem Normalenvector Cam.leftDirection
	rotTopDir	sei der Vector, der sich durch Kreuzprodukt von Cam.leftDirection und Cam.FrontDirection ergibt
	horizontalFlat	sei die Ebene durch Cam.Pos und dem Normalenvector rotTopDir
	beta		sei der Winkel zwischen Cam.dirFront und viewVec in x-Richtung
	gamma		sei der Winkel zwischen Cam.dirFront und viewVec in y-Richtung
*/
Point2D Entity::from3Dto2D(const Vec3D& vec, const Cam& cam) const
{
	float betaDif = Vec3D::getDistanceToFlat(cam.getPosition(), cam.getDirectionLeft(), vec); // Der Abstand von verticalFlat zu vec
	Vec3D rotTopDir = cam.getRotDirectionTop();
	float gammaDif = Vec3D::getDistanceToFlat(cam.getPosition(), rotTopDir, vec); // Der Abstand von horizontalFlat zu vec
	float distanceToPoint = Vec3D::getDistance(cam.getPosition(), vec);

	float beta = asin(betaDif/distanceToPoint);
	float gamma = asin(gammaDif/distanceToPoint);

	float ssx = Screen::getScreenSize().getX();
	float ssy = Screen::getScreenSize().getY();

	int x = (int)(ssx/2.f) + ((beta / cam.getXViewRange()) * ssx);
	int y = (int)(ssy/2.f) - ((gamma / cam.getYViewRange()) * ssy);

	return Point2D(x, y);
}

float Entity::getDistanceToCam() const { return distanceToCam; }

std::string Entity::toString() const
{
	return "[distanceToCam=" + Converter::floatToString(distanceToCam) + "]";
}

void Entity::calculateDistanceToCam(const Cam& cam)
{
	distanceToCam = (cam.getPosition() - getPosition()).getMagnitude();
}

bool distanceComp(Entity* e1, Entity* e2)
{
	return e1->getDistanceToCam() > e2->getDistanceToCam();
}
