/***********************************************************************
 * Source File:
 *    TEST STARLINK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Starlink
 ************************************************************************/
#pragma once

#include "testStarlink.h"

 /*************************************
  * TESTSTARLINK : RUN
  *************************************/
void TestStarlink::run() {
	defaultConstructor();
	report("Starlink");
}

/*************************************
 * TESTSTARLINK : DEFAULT CONSTRUCTOR
 *************************************/
void TestStarlink::defaultConstructor() {
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