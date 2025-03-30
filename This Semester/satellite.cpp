/***********************************************************************
 * Source File:
 *    SATELLITE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for satellites
 ************************************************************************/
#pragma once
#include "projectile.h" // Now the full definition of Projectile is available
#include "satellite.h"

/*************************************
 * SATELLITE : MOVE
 *************************************/
void Satellite::move(float time) {
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
	angle.add(angularVelocity);
}


#include "projectile.h" // Now the full definition of Projectile is available

void Satellite::destroy(Projectile& projectile) {
	// Implement destruction logic here
}
