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
	double radius = 1 * position.getZoom();
	int expirationTimer = (10 * 60);
public:
	Projectile(Satellite& ptShip);
	Projectile(double dx, double dy) { position.setMeters(dx, dy); }

	bool isDead = true;
	bool isExpired() const { return expirationTimer <= 0; }

	float getRadius() const { return radius; }
	Position getPosition() const { return position; }
	double getDegrees() const { return angle.getDegrees(); }

	void draw(ogstream& pgout) { pgout.drawProjectile(position); }
	void move(float time);
};