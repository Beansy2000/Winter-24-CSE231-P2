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
	Earth() {
		position.setMeters(0.0, 0.0);
		velocity.setDXY(0.0, 0.0);
		radius = 6378;
		angularVelocity = -(2 * M_PI / 30) * (24 * 60 / 86400);
		angle.setRadians(0.0040469023027);
	}

	float getRadius() const { return radius; }
	Position getPosition() const { return position; }

	void draw(ogstream& pgout) {
		pgout.drawEarth(position, angle.getRadians());
	}
	void rotate(double td) {
		angle.setRadians(angle.getRadians() + -(2 * M_PI / 30) * (td / 86400));
	}
};