#include "Cam.hpp"

#include "../misc/Debug.hpp"
#include "../core/Screen.hpp"

const float Cam::DEFAULT_ROTATION_SPEED = 0.001f;
const float Cam::DEFAULT_VIEW_RANGE_X = 0.52f;
const float Cam::DEFAULT_DRAG = 0.98f;
const float Cam::DEFAULT_ACCELERATION = 0.2f;
const float Cam::FAST_ACCELERATION = 0.4f;

Cam::Cam(const Vec3D& pos)
	: position(pos), directionFront(1.f, 0.f, 0.f), directionTop(0.f, 0.f, 1.f), tele(DEFAULT_VIEW_RANGE_X)
{
	calcLeftDirection();
}

Vec3D Cam::getPosition() const
{
	return position;
}

const Vec3D& Cam::getDirectionFront() const
{
	return directionFront;
}

const Vec3D& Cam::getDirectionLeft() const
{
	return directionLeft;
}

// directionTop sollte immer gleich (0,0,1) sein
const Vec3D& Cam::getDirectionTop() const
{
	return directionTop;
}

const Vec3D& Cam::getSpeed() const
{
	return speed;
}

Vec3D Cam::getRotDirectionTop() const
{
	Vec3D vec = Vec3D::vectorProduct(getDirectionFront(), getDirectionLeft());
	vec.normalize();
	return vec;
}

float Cam::getXViewRange() const
{
	return tele;
}

float Cam::getYViewRange() const
{
	return tele * ((float)Screen::getScreenSize().getY()/(float)Screen::getScreenSize().getX());
}

void Cam::handleKeyPressEvent(const sf::Event& event)
{
	switch (event.key.code)
	{
		case sf::Keyboard::W:
			isMovingFront = true;
			break;
		case sf::Keyboard::A:
			isMovingLeft = true;
			break;
		case sf::Keyboard::S:
			isMovingBack = true;
			break;
		case sf::Keyboard::D:
			isMovingRight = true;
			break;
		case sf::Keyboard::Space:
			isMovingUp = true;
			break;
		case sf::Keyboard::LControl:
			isMovingDown = true;
			break;
		case sf::Keyboard::LShift:
			isMovingFast = true;
			break;
		case sf::Keyboard::E:
			isFocusingPoint = true;
			break;
		default:
			Debug::warn("Cam::handleKeyPressEvent(): Unknown KeyPressEvent");
	}
}

void Cam::handleKeyReleaseEvent(const sf::Event& event)
{
	switch (event.key.code)
	{
		case sf::Keyboard::W:
			isMovingFront = false;
			break;
		case sf::Keyboard::S:
			isMovingBack = false;
			break;
		case sf::Keyboard::A:
			isMovingLeft = false;
			break;
		case sf::Keyboard::D:
			isMovingRight = false;
			break;
		case sf::Keyboard::Space:
			isMovingUp = false;
			break;
		case sf::Keyboard::LControl:
			isMovingDown = false;
			break;
		case sf::Keyboard::LShift:
			isMovingFast = false;
			break;
		case sf::Keyboard::E:
			isFocusingPoint = false;
			break;
		default:
			Debug::warn("Cam::handleKeyReleaseEvent(): Unknown KeyReleaseEvent");
	}
}

void Cam::handleMouseMoveEvent(const Point2D& mouseMove)
{
	float mouseXMove = (float)(mouseMove.getX() * DEFAULT_ROTATION_SPEED);
	float mouseYMove = (float)(mouseMove.getY() * DEFAULT_ROTATION_SPEED);
	directionFront.rotateZ(mouseXMove);
	directionFront.rotateUpDown(mouseYMove);
	directionFront.normalize();
	calcLeftDirection();
}

void Cam::updateSpeed()
{
	Vec3D tmpFront(getDirectionFront());
	Vec3D tmpLeft(getDirectionLeft());
	Vec3D tmpUp(getDirectionTop());

	float acceleration = 0.f;

	if (isMovingFast)
	{
		acceleration = FAST_ACCELERATION;
	}
	else
	{
		acceleration = DEFAULT_ACCELERATION;
	}

	if (!(isMovingFront && isMovingBack)) // Wenn er nicht gleichzeitig W und S drückt
	{
		if (isMovingFront)
		{
			tmpFront.scaleWith(acceleration);
			speed.addWith(tmpFront);
		}
		if (isMovingBack)
		{
			tmpFront.scaleWith(-acceleration);
			speed.addWith(tmpFront);
		}
	}
	if (!(isMovingLeft && isMovingRight)) // Wenn er nicht gleichzeitig A und D drückt
	{
		if (isMovingLeft)
		{
			tmpLeft.scaleWith(-acceleration);
			speed.addWith(tmpLeft);
		}
		if (isMovingRight)
		{
			tmpLeft.scaleWith(acceleration);
			speed.addWith(tmpLeft);
		}
	}
	if (!(isMovingUp && isMovingDown)) // Wenn er nicht gleichzeitig Space und LControl drückt
	{
		if (isMovingUp)
		{
			tmpUp.scaleWith(acceleration);
			speed.addWith(tmpUp);
		}
		if (isMovingDown)
		{
			tmpUp.scaleWith(-acceleration);
			speed.addWith(tmpUp);
		}
	}
}

void Cam::tick()
{
	updateSpeed();
	position.addWith(speed);
	speed.scaleWith(DEFAULT_DRAG);
	if (isFocusingPoint)
	{
		directionFront.set(Vec3D() - getPosition());
		directionFront.normalize();
		calcLeftDirection();
	}
}

void Cam::render(const Cam&) const
{
	Debug::warn("Cam::render(): TODO");
}

void Cam::setPosition(const Vec3D&)
{
	Debug::warn("Cam::setPosition(): TODO");
}

// Berechnet 'directionLeft' aus 'FrontDirection'
void Cam::calcLeftDirection()
{
	directionLeft.set(Vec3D::vectorProduct(getDirectionTop(), getDirectionFront()));
}
