/***********************************************************************
 * Header File:
 *    SATELLITE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for satellites
 ************************************************************************/
#pragma once

#include <iostream>
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "physics.h"
#include "acceleration.h"
#include "uiDraw.h"
#include "uiInteract.h"


enum SatelliteType {
	sGPS, HUBBLE, STARLINK, SPUTNIK, CREWDRAGON, PART, FRAGMENT
};

class Satellite {
protected:
    // Variables inherited by Satellite classes.
	Velocity velocity;
	Position position;
	Physics physics;
	Angle angle;
	double angularVelocity = 0;
	bool dead = true;
	double radius = 0;

public:
	// Default constructor
	Satellite(double radius = 0.0, double angularVelocity = 0.0) : angularVelocity(angularVelocity), dead(true), radius(radius) {}
	
	// VARIABLES
	// Get protected variables
	Velocity getVelocity() const { return velocity; }
	Position getPosition() const { return position; }
	Physics getPhysics() const { return physics; }
	double getAngle() const { return angle.getRadians(); }
	double getAngularVelocity() const { return angularVelocity; }
	bool isDead() const { return dead; }
	float getRadius() const { return radius; }

	// Get internal variables
	double getMetersX() { return position.getMetersX(); }
	double getMetersY() { return position.getMetersY(); }
	double getDX() { return velocity.getDX(); }
	double getDY() { return velocity.getDY(); }

	// Setters
	void setMetersX(double metersX) { position.setMetersX(metersX); }
	void setMetersY(double metersY) { position.setMetersY(metersY); }
	void setMeters(double mX, double mY) { position.setMeters(mX, mY); }
	void setDX(double dX) { velocity.setDX(dX); }
	void setDY(double dY) { velocity.setDY(dY); }
	void setAngle(float radians) { angle.setRadians(radians); }
	void kill() { dead = true; }

	// METHODS
	virtual void draw(ogstream& gout) {}
	virtual void destroy(Satellite& satellite) {}
	void move(float time);
};
