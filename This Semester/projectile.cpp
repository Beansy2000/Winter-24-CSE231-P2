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
	// Gravitational Acceleration
	//double acceleration = physics.getAccelFromGravity(position.getMetersX(), position.getMetersY());

	//// Direction of Gravity in Radians
	//double gravDirection = physics.getGravDirectionRadians(position.getMetersX(), position.getMetersY());

	//// Change velocity with Gravity
	//pDemo->ptShip.addPixelsY(cos(pDemo->ptShip.getAngle()));
	//pDemo->ptShip.addPixelsX(sin(pDemo->ptShip.getAngle()));
	//double ddx = physics.getDDX(acceleration, gravDirection);
	//double ddy = physics.getDDY(acceleration, gravDirection);
	double ddx = sin(angle.getRadians());
	double ddy = cos(angle.getRadians());

	// Update velocity with Acceleration
	velocity.setDX(velocity.getDX() + ddx * time);
	velocity.setDY(velocity.getDY() + ddy * time);

	// Update position
	position.setMetersX(position.getMetersX() + velocity.getDX() * time);
	position.setMetersY(position.getMetersY() + velocity.getDY() * time);
	expirationTimer--;
}
void Projectile::kill() {

}