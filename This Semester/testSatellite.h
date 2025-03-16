/***********************************************************************
 * Test File:
 *    SATELLITE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Satellite test class
 ************************************************************************/
#pragma once

#include "satellite.h"
#include "unitTest.h"


 /*********************************************
  * TEST SATELLITE
  *********************************************/
class TestSatellite : public UnitTest {
public:
	void run() {
		defaultConstructor();
		report("Satellite");
	}
private:
	void defaultConstructor() {
		// SETUP
		Satellite s;

		// TEST
		assertUnit(s.getRadius() == 0);
		assertUnit(s.isDead() == true);
		assertUnit(s.getAngularVelocity() == 0);
	}
};