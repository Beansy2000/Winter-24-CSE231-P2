/***********************************************************************
 * Source File:
 *    TEST SHIP
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Ship
 ************************************************************************/
#pragma once

#include "testShip.h"

 /*************************************
  * TESTSHIP : RUN
  *************************************/
void TestShip::run() {
	defaultConstructor();
	turnLeft();
	turnRight();
	moveForward();
	report("Ship");
}

/*************************************
 * TESTSHIP : DEFAULT CONSTRUCTOR
 *************************************/
void TestShip::defaultConstructor() {
	// SETUP
	Ship s;
	Position p;
	Velocity v;

	// Action
	p.setPixelsX(-450);
	p.setPixelsY(450);
	v.setDXY(0.0, 0.0);

	// TEST
	assertUnit(s.getRadius() == 10 * s.getPosition().getZoom());
	assertUnit(s.isDead() == false);
	assertUnit(s.getAngularVelocity() == 0);
	assertUnit(s.getPosition() == p);
	assertUnit(s.getVelocity().getDX() == v.getDX());
	assertUnit(s.getVelocity().getDY() == v.getDY());
}

/*************************************
 * TESTSHIP : TURN LEFT
 *************************************/
void TestShip::turnLeft() {
	// SETUP
	Ship s;
	Angle a;

	// Action
	a.setRadians(s.getAngle() - 0.04);
	s.rotateLeft();

	// TEST
	assertUnit(s.getAngle() == a.getRadians());
}

/*************************************
 * TESTSHIP : TURN RIGHT
 *************************************/
void TestShip::turnRight() {
	// SETUP
	Ship s;
	Angle a;

	// Action
	a.setRadians(s.getAngle() + 0.04);
	s.rotateRight();

	// TEST
	assertUnit(s.getAngle() == a.getRadians());
}

/*************************************
 * TESTSHIP : MOVE FORWARD
 *************************************/
void TestShip::moveForward() {
	// SETUP
	Ship s;
	Position p;

	// Action
	p.setMeters(s.getMetersX(), s.getMetersY());
	p.addPixelsX(sin(s.getAngle())*2);
	p.addPixelsY(cos(s.getAngle())*2);
	s.drive();

	// TEST
	assertUnit(s.isThrusting() == true);
	assertUnit(s.getPosition() == p);
}