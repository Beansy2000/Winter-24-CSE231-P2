/***********************************************************************
 * Header File:
 *    PROJECTILE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for projectiles
 ************************************************************************/
#pragma once
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "physics.h"
#include "acceleration.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"

class Projectile {
	Velocity velocity;
	Position position;
	Physics physics;
	Angle angle;
	double radius = 1;
public:
	Projectile(Satellite& ptShip) {
		velocity = ptShip.getVelocity();
		position = ptShip.getPosition();
		physics = ptShip.getPhysics();
		angle.setRadians(ptShip.getAngle());
		position.setPixelsX(position.getPixelsX() + sin(angle.getRadians())*18);
		position.setPixelsY(position.getPixelsY() + cos(angle.getRadians())*18);
	}
	Projectile(double dx, double dy) {
		position.setMeters(dx, dy);
	}

	bool isDead = true;
	int expirationTimer = (10 * 60);

	float getRadius() const { return radius; }
	Position getPosition() const { return position; }

	void draw(ogstream& pgout) {
		pgout.drawProjectile(position);
	}
	void kill();
	void move(float time);
};