/***********************************************************************
 * Source File:
 *    TEST SPUTNIK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Sputnik
 ************************************************************************/
#pragma once

#include "testSputnik.h"

 /*************************************
  * TESTSPUTNIK : RUN
  *************************************/
void TestSputnik::run() {
	defaultConstructor();
	report("Sputnik");
}

/*************************************
 * TESTSPUTNIK : DEFAULT CONSTRUCTOR
 *************************************/
void TestSputnik::defaultConstructor() {
	// SETUP
	Sputnik s;
	Position p;
	Velocity v;

	// Action
	p.setMeters(-36515095.13, 21082000.0);
	v.setDXY(2050.0, 2684.68);

	// TEST
	assertUnit(s.getRadius() == 4.0 * s.getPosition().getZoom());
	assertUnit(s.isDead() == false);
	assertUnit(s.getAngularVelocity() == 0.03);
	assertUnit(s.getPosition() == p);
	assertUnit(s.getVelocity().getDX() == v.getDX());
	assertUnit(s.getVelocity().getDY() == v.getDY());
}