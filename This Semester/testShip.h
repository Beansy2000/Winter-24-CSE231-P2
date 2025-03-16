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
};