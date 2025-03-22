/***********************************************************************
 * Source File:
 *    COLLISION
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for collision
 ************************************************************************/
#pragma once

#include "collision.h"

/*************************************
 * COLLISION : CHECKFORCOLLISION SATELLITE TO SATELLITE
 *************************************/
bool Collision::IsColliding(Satellite& satelliteA, Satellite& satelliteB) {
	float distX = satelliteA.getPosition().getMetersX() - satelliteB.getPosition().getMetersX();
	float distY = satelliteA.getPosition().getMetersY() - satelliteB.getPosition().getMetersY();

	float distance = sqrt((distX * distX) + (distY * distY));
	if (distance <= satelliteA.getRadius() + satelliteB.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************
 * COLLISION : CHECKFORCOLLISION PROJECTILE TO SATELLITE
 *************************************/
bool Collision::IsColliding(Satellite& satellite, Projectile& projectile) {
	float distX = satellite.getPosition().getMetersX() - projectile.getPosition().getMetersX();
	float distY = satellite.getPosition().getMetersY() - projectile.getPosition().getMetersY();

	float distance = sqrt((distX * distX) + (distY * distY));
	if (distance <= satellite.getRadius() + projectile.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************
 * COLLISION : CHECKFORCOLLISION SATELLITE TO EARTH
 *************************************/
bool Collision::IsColliding(Satellite& satellite, Earth& earth) {
	float distX = satellite.getPosition().getMetersX() - earth.getPosition().getMetersX();
	float distY = satellite.getPosition().getMetersY() - earth.getPosition().getMetersY();

	float distance = sqrt((distX * distX) + (distY * distY));
	if (distance <= satellite.getRadius() + earth.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}