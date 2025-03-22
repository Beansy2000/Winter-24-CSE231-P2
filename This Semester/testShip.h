#pragma once
/***********************************************************************
 * Test File:
 *    SHIP
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Hubble test class
 ************************************************************************/
#pragma once

#include "satelliteShip.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST SHIP
  *********************************************/
class testShip : public UnitTest {
public:
	void run() {
		defaultConstructor();
		turnLeft();
		turnRight();
		moveForward();
		report("Ship");
	}
private:
	void defaultConstructor() {
		// SETUP
		Ship s;
		Position p;
		Velocity v;

		// Action
		p.setPixelsX(-450);
		p.setPixelsY(450);
		v.setDXY(0.0, 0.0);

		// TEST
		assertUnit(s.getRadius() == 10 * s.getPosition().getZoom());
		assertUnit(s.isDead() == false);
		assertUnit(s.getAngularVelocity() == 0);
		assertUnit(s.getPosition() == p);
		assertUnit(s.getVelocity().getDX() == v.getDX());
		assertUnit(s.getVelocity().getDY() == v.getDY());
	}
	void turnLeft() {
		// SETUP
		Ship s;
		Angle a;

		// Action
		a.setRadians(s.getAngle() - 0.02);
		s.rotateLeft();

		// TEST
		assertUnit(s.getAngle() == a.getRadians());
	}
	void turnRight() {
		// SETUP
		Ship s;
		Angle a;

		// Action
		a.setRadians(s.getAngle() + 0.02);
		s.rotateRight();

		// TEST
		assertUnit(s.getAngle() == a.getRadians());
	}
	void moveForward() {
		// SETUP
		Ship s;
		Position p;

		// Action
		p.setMeters(s.getMetersX(), s.getMetersY());
		p.addPixelsX(sin(s.getAngle()));
		p.addPixelsY(cos(s.getAngle()));
		s.drive();

		// TEST
		assertUnit(s.isThrusting() == true);
		assertUnit(s.getPosition() == p);
	}
};