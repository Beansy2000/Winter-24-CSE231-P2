/***********************************************************************
 * Source File:
 *    TEST CREWDRAGON
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Crew Dragon
 ************************************************************************/
#pragma once

#include "testCrewDragon.h"

 /*************************************
  * TESTCREWDRAGON : RUN
  *************************************/
void TestCrewDragon::run() {
	defaultConstructor();
	report("Crew Dragon");
}

/*************************************
 * TESTCREWDRAGON : CONSTRUCTOR
 *************************************/
void TestCrewDragon::defaultConstructor() {
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