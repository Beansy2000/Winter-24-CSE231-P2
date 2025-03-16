/***********************************************************************
 * Test File:
 *    HUBBLE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Hubble test class
 ************************************************************************/
#pragma once

#include "satelliteHubble.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST HUBBLE
  *********************************************/
class TestHubble : public UnitTest {
public:
	void run() {
		defaultConstructor();
		report("Hubble");
	}
private:
	void defaultConstructor() {
		// SETUP
		Hubble h;
		Position p;
		Velocity v;

		// Action
		p.setMeters(0.0, -42164000.0);
		v.setDXY(3100, 0.0);

		// TEST
		assertUnit(h.getRadius() == 10 * h.getPosition().getZoom());
		assertUnit(h.isDead() == false);
		assertUnit(h.getAngularVelocity() == 0);
		assertUnit(h.getPosition() == p);
		assertUnit(h.getVelocity().getDX() == v.getDX());
		assertUnit(h.getVelocity().getDY() == v.getDY());
	}
};