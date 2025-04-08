/***********************************************************************
 * Source File:
 *    TEST COLLISION
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Collision
 ************************************************************************/
#pragma once

#include "testCollision.h"

 /*************************************
  * TESTCOLLISION : RUN
  *************************************/
void TestCollision::run() {
	TwoNoCollision();
	SatEarthNoCollision();
	SatProjectileNoCollision();
	TwoCollision();
	SatEarthCollision();
	SatProjectileCollision();

	report("Collision");
}

Collision c;
// Test Cases:
// Two Satellites | No Collision
// Two Satellites | Overlap
// One Satellite | Earth | No Collision
// One Satellite | Earth | Collision
// One Satellite | Projectile | No Collision
// One Satellite | Projectile | Collision
// 

/*****************************************************************
 *****************************************************************
 * No Collision
 *****************************************************************
 *****************************************************************/


 /*********************************************
  * name:    TWO NO COLLISION
  * input:   GPS(1), GPS(2)
  * output:  false
  *********************************************/
void TestCollision::TwoNoCollision() {
	Satellite* sat1 = new GPS(1);
	Satellite* sat2 = new GPS(2);
	assertUnit(c.IsColliding(*sat1, *sat2) != true);
}


/*********************************************
 * name:    SAT EARTH NO COLLISION
 * input:   GPS(1), Earth
 * output:  false
 *********************************************/
void TestCollision::SatEarthNoCollision() {
	Satellite* sat = new GPS(1);
	Earth* earth = new Earth;
	assertUnit(c.IsColliding(*sat, *earth) != true);
}


/*********************************************
 * name:    SAT PROJECTILE NO COLLISION
 * input:   GPS(1), Projectile(0.0, 0.0)
 * output:  false
 *********************************************/
void TestCollision::SatProjectileNoCollision() {
	Satellite* sat = new GPS(1);
	Projectile* projectile = new Projectile(0.0, 0.0);
	assertUnit(c.IsColliding(*sat, *projectile) != true);
}


/*********************************************
 * name:    TWO COLLISION
 * input:   GPS(1), GPS(1)
 * output:  true
 *********************************************/
void TestCollision::TwoCollision() {
	Satellite* sat1 = new GPS(1);
	Satellite* sat2 = new GPS(1);
	assertUnit(c.IsColliding(*sat1, *sat2) == true);
}


/*********************************************
 * name:    SAT EARTH COLLISION
 * input:   Hubble(0.0, 0.0), Earth
 * output:  false
 *********************************************/
void TestCollision::SatEarthCollision() {
	Satellite* sat = new Hubble(0.0, 0.0);
	Earth* earth = new Earth;
	assertUnit(c.IsColliding(*sat, *earth) == true);
}


/*********************************************
 * name:    SAT PROJECTILE NO COLLISION
 * input:   Hubble(100.0, 100.0), Projectile(100.0, 100.0)
 * output:  false
 *********************************************/
void TestCollision::SatProjectileCollision() {
	Satellite* sat = new Hubble(100.0, 100.0);
	Projectile* projectile = new Projectile(100.0, 100.0);
	assertUnit(c.IsColliding(*sat, *projectile) == true);
}