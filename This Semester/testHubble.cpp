/***********************************************************************
 * Source File:
 *    TEST HUBBLE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Hubble
 ************************************************************************/
#pragma once

#include "testHubble.h"

 /*************************************
  * TESTHUBBLE : RUN
  *************************************/
void TestHubble::run() {
	defaultConstructor();
	report("Hubble");
}

/*************************************
 * TESTHUBBLE : DEFAULT CONSTRUCTOR
 *************************************/
void TestHubble::defaultConstructor() {
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