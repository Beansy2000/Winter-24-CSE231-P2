/***********************************************************************
 * Source File:
 *    TEST CREWDRAGON
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Crew Dragon
 ************************************************************************/
#pragma once

#include "testGPS.h"

 /*************************************
  * TESTGPS : RUN
  *************************************/
void TestGPS::run() {
	defaultConstructor();
	Constructor1();
	Constructor2();
	Constructor3();
	Constructor4();
	Constructor5();
	Constructor6();
	report("GPS");
}

/*************************************
 * TESTGPS : DEFAULT CONSTRUCTOR
 *************************************/
void TestGPS::defaultConstructor() {
	// SETUP
	GPS g;
	Position p;
	Velocity v;

	// Action
	p.setMeters(1, 1);
	v.setDXY(0.0, 0.0);

	// TEST
	assertUnit(g.getRadius() == 12 * g.getPosition().getZoom());
	assertUnit(g.isDead() == false);
	assertUnit(g.getAngularVelocity() == -0.0069813);
	assertUnit(g.getPosition() == p);
	assertUnit(g.getVelocity().getDX() == v.getDX());
	assertUnit(g.getVelocity().getDY() == v.getDY());
}

/*************************************
 * TESTGPS : CONSTRUCTOR
 *************************************/
void TestGPS::Constructor1() {
	// SETUP
	GPS g(1);
	Position p;
	Velocity v;

	// Action
	p.setMeters(0.0, 26560000.0);
	v.setDXY(-3880.0, 0.0);

	// TEST
	assertUnit(g.getRadius() == 12 * g.getPosition().getZoom());
	assertUnit(g.isDead() == false);
	assertUnit(g.getAngularVelocity() == -0.0069813);
	assertUnit(g.getPosition() == p);
	assertUnit(g.getVelocity().getDX() == v.getDX());
	assertUnit(g.getVelocity().getDY() == v.getDY());
}

/*************************************
 * TESTGPS : CONSTRUCTOR
 *************************************/
void TestGPS::Constructor2() {
	// SETUP
	GPS g(2);
	Position p;
	Velocity v;

	// Action
	p.setMeters(23001634.72, 13280000.0);
	v.setDXY(-1940.0, 3360.18);

	// TEST
	assertUnit(g.getRadius() == 12 * g.getPosition().getZoom());
	assertUnit(g.isDead() == false);
	assertUnit(g.getAngularVelocity() == -0.0069813);
	assertUnit(g.getPosition() == p);
	assertUnit(g.getVelocity().getDX() == v.getDX());
	assertUnit(g.getVelocity().getDY() == v.getDY());
}

/*************************************
 * TESTGPS : CONSTRUCTOR
 *************************************/
void TestGPS::Constructor3() {
	// SETUP
	GPS g(3);
	Position p;
	Velocity v;

	// Action
	p.setMeters(23001634.72, -13280000.0);
	v.setDXY(1940.0, 3360.18);

	// TEST
	assertUnit(g.getRadius() == 12 * g.getPosition().getZoom());
	assertUnit(g.isDead() == false);
	assertUnit(g.getAngularVelocity() == -0.0069813);
	assertUnit(g.getPosition() == p);
	assertUnit(g.getVelocity().getDX() == v.getDX());
	assertUnit(g.getVelocity().getDY() == v.getDY());
}

/*************************************
 * TESTGPS : CONSTRUCTOR
 *************************************/
void TestGPS::Constructor4() {
	// SETUP
	GPS g(4);
	Position p;
	Velocity v;

	// Action
	p.setMeters(0.0, -26560000.0);
	v.setDXY(3880.0, 0.0);

	// TEST
	assertUnit(g.getRadius() == 12 * g.getPosition().getZoom());
	assertUnit(g.isDead() == false);
	assertUnit(g.getAngularVelocity() == -0.0069813);
	assertUnit(g.getPosition() == p);
	assertUnit(g.getVelocity().getDX() == v.getDX());
	assertUnit(g.getVelocity().getDY() == v.getDY());
}

/*************************************
 * TESTGPS : CONSTRUCTOR
 *************************************/
void TestGPS::Constructor5() {
	// SETUP
	GPS g(5);
	Position p;
	Velocity v;

	// Action
	p.setMeters(-23001634.72, -13280000.0);
	v.setDXY(1940.0, -3360.18);

	// TEST
	assertUnit(g.getRadius() == 12 * g.getPosition().getZoom());
	assertUnit(g.isDead() == false);
	assertUnit(g.getAngularVelocity() == -0.0069813);
	assertUnit(g.getPosition() == p);
	assertUnit(g.getVelocity().getDX() == v.getDX());
	assertUnit(g.getVelocity().getDY() == v.getDY());
}

/*************************************
 * TESTGPS : CONSTRUCTOR
 *************************************/
void TestGPS::Constructor6() {
	// SETUP
	GPS g(6);
	Position p;
	Velocity v;

	// Action
	p.setMeters(-23001634.72, 13280000.0);
	v.setDXY(-1940.0, -3360.18);

	// TEST
	assertUnit(g.getRadius() == 12 * g.getPosition().getZoom());
	assertUnit(g.isDead() == false);
	assertUnit(g.getAngularVelocity() == -0.0069813);
	assertUnit(g.getPosition() == p);
	assertUnit(g.getVelocity().getDX() == v.getDX());
	assertUnit(g.getVelocity().getDY() == v.getDY());
}