#include "Entity.hpp"

#include <cmath>

#include "../misc/Debug.hpp"
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
Point2D* Entity::from3Dto2D(const Vec3D& vec, const Cam& cam) const
{
	float betaDif = Vec3D::getDistanceToFlat(cam.getPosition(), cam.getDirectionLeft(), vec); // Der Abstand von verticalFlat zu vec
	Vec3D* rotTopDir = cam.getRotDirectionTop();
	float gammaDif = Vec3D::getDistanceToFlat(cam.getPosition(), *rotTopDir, vec); // Der Abstand von horizontalFlat zu vec
	delete rotTopDir;
	float distanceToPoint = Vec3D::getDistance(cam.getPosition(), vec);

	float beta = asin(betaDif/distanceToPoint);
	float gamma = asin(gammaDif/distanceToPoint);

	int x = (int)(Screen::getScreenSize().getX()/2.f) + ((beta*2.f / cam.getXViewRange()) * Screen::getScreenSize().getX()/2.f);
	int y = (int)(Screen::getScreenSize().getY()/2.f) + ((gamma*2.f / cam.getYViewRange()) * Screen::getScreenSize().getY()/2.f);

	Debug::warn("Entity::from3Dto2D(): TODO");
	return new Point2D(x, y);
}
