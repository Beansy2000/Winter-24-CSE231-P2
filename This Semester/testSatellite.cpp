/***********************************************************************
 * Source File:
 *    TEST POSITION
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Satellite
 ************************************************************************/
#pragma once

#include "testSatellite.h"

 /*************************************
  * TESTSATELLITE : RUN
  *************************************/
void TestSatellite::run() {
	defaultConstructor();
	report("Satellite");
}

/*************************************
 * TESTSATELLITE : DEFAULT CONSTRUCTOR
 *************************************/
void TestSatellite::defaultConstructor() {
	// SETUP
	Satellite s;

	// TEST
	assertUnit(s.getRadius() == 0);
	assertUnit(s.isDead() == true);
	assertUnit(s.getAngularVelocity() == 0);
}