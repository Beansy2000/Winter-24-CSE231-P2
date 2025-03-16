/***********************************************************************
 * Test File:
 *    CREWDRAGON
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Crew Dragon test class
 ************************************************************************/
#pragma once

#include "satelliteCrewDragon.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST CREWDRAGON
  *********************************************/
class TestCrewDragon : public UnitTest {
public:
	void run() {
		defaultConstructor();
		report("Crew Dragon");
	}
private:
	void defaultConstructor() {
		// SETUP
		CrewDragon c;
		Position p;
		Velocity v;

		// Action
		p.setMeters(0.0, 8000000);
		v.setDXY(-7900.0, 0.0);

		// TEST
		assertUnit(c.getRadius() == 7 * c.getPosition().getZoom());
		assertUnit(c.isDead() == false);
		assertUnit(c.getAngularVelocity() == -0.01);
		assertUnit(c.getPosition() == p);
		assertUnit(c.getVelocity().getDX() == v.getDX());
		assertUnit(c.getVelocity().getDY() == v.getDY());
	}
};