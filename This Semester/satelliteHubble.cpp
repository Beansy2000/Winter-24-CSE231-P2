#include "satelliteHubble.h"


/***********************************************************************
 * Source File:
 *    SPUTNIK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Sputnik
 ************************************************************************/
#pragma once

#include "satelliteSputnik.h"

 /*************************************
  * SATELLITE : MOVE
  *************************************/
void Hubble::move(float time) {
	// Gravitational Acceleration
	double acceleration = physics.getAccelFromGravity(position.getMetersX(), position.getMetersY());

	// Direction of Gravity in Radians
	double gravDirection = physics.getGravDirectionRadians(position.getMetersX(), position.getMetersY());

	// Change velocity with Gravity
	double ddx = physics.getDDX(acceleration, gravDirection);
	double ddy = physics.getDDY(acceleration, gravDirection);

	// Update velocity with Acceleration
	velocity.setDX(velocity.getDX() + ddx * time);
	velocity.setDY(velocity.getDY() + ddy * time);

	// Update position
	position.setMetersX(position.getMetersX() + velocity.getDX() * time);
	position.setMetersY(position.getMetersY() + velocity.getDY() * time);

	// Rotate
	angle.add(angularVelocity * time);
}