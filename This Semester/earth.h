/***********************************************************************
 * Header File:
 *    EARTH
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Earth class
 ************************************************************************/
#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "physics.h"
#include "acceleration.h"

class Earth {
private:
	Velocity velocity;
	Position position;
	Angle angle;
	Physics physics;
	double angularVelocity;
	double radius;
public:
	Earth();

	float getRadius() const { return radius; }
	Position getPosition() const { return position; }

	void draw(ogstream& pgout) { pgout.drawEarth(position, angle.getRadians()); }
	void rotate(double td) { angle.setRadians(angle.getRadians() + -(2 * M_PI / 30) * (td / 86400)); }
};