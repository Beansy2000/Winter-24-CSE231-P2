/***********************************************************************
 * Test File:
 *    Satellite
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Satellite test class
 ************************************************************************/
#pragma once

#include "satelliteSputnik.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST SATELLITE
  * Unit tests for Acceleration
  *********************************************/
class TestSputnik : public UnitTest {
public:
	void run() {
		defaultConstructor();
		report("Satellite");
	}
private:
	void defaultConstructor() {
		// SETUP
		Sputnik s;
		Position p;
		Velocity v;

		// Action
		p.setMeters(-36515095.13, 21082000.0);
		v.setDXY(2050, 2684);

		// TEST
		assertUnit(s.getRadius() == 4.0 * s.getPosition().getZoom());
		assertUnit(s.isDead() == false);
		assertUnit(s.getAngularVelocity() == 1);
		assertUnit(s.getPosition() == p);
		assertUnit(s.getVelocity().getDX() == v.getDX());
		assertUnit(s.getVelocity().getDY() == v.getDY());
	}
};