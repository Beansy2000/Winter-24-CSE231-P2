/***********************************************************************
 * Test File:
 *    STARLINK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Satellite test class
 ************************************************************************/
#pragma once

#include "satelliteStarlink.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST STARLINK
  *********************************************/
class TestStarlink : public UnitTest {
public:
	void run() {
		defaultConstructor();
		report("Starlink");
	}
private:
	void defaultConstructor() {
		// SETUP
		Starlink s;
		Position p;
		Velocity v;

		// Action
		p.setMeters(0.0, -13020000.0);
		v.setDXY(5800, 0);

		// TEST
		assertUnit(s.getRadius() == 6 * s.getPosition().getZoom());
		assertUnit(s.isDead() == false);
		assertUnit(s.getAngularVelocity() == -0.008);
		assertUnit(s.getPosition() == p);
		assertUnit(s.getVelocity().getDX() == v.getDX());
		assertUnit(s.getVelocity().getDY() == v.getDY());
	}
};