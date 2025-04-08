/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for projectiles
 ************************************************************************/
#pragma once

#include "projectile.h"

 /*************************************
  * PROJECTILE : MOVE
  *************************************/
void Projectile::move(float time) {
	double ddx = sin(angle.getRadians());
	double ddy = cos(angle.getRadians());

	// Update velocity with Acceleration
	velocity.setDX(velocity.getDX() + ddx * time);
	velocity.setDY(velocity.getDY() + ddy * time);

	// Update position
	position.setMetersX(position.getMetersX() + velocity.getDX() * time * 10);
	position.setMetersY(position.getMetersY() + velocity.getDY() * time * 10);
	expirationTimer--;
}

/*************************************
 * PROJECTILE : CONSTRUCTOR
 *************************************/
Projectile::Projectile(Satellite& ptShip) {
	position = ptShip.getPosition();
	angle.setRadians(ptShip.getAngle());
	velocity.setDX(ptShip.getVelocity().getDX() + sin(angle.getRadians()) * (24 / 60 * 30));
	velocity.setDY(ptShip.getVelocity().getDY() + cos(angle.getRadians()) * (24 / 60 * 30));
	physics = ptShip.getPhysics();
	position.setPixelsX(position.getPixelsX() + sin(angle.getRadians()) * 18);
	position.setPixelsY(position.getPixelsY() + cos(angle.getRadians()) * 18);
}