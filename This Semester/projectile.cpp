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
	position.setMetersX(position.getMetersX() + velocity.getDX() * time);
	position.setMetersY(position.getMetersY() + velocity.getDY() * time);
	expirationTimer--;
}
void Projectile::kill() {

}