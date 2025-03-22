/***********************************************************************
 * Test File:
 *    Collision
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Collision test class
 ************************************************************************/
#pragma once

#include "collision.h"
#include "satellite.h"
#include "satelliteGPS.h"
#include "satelliteHubble.h"
#include "projectile.h"
#include "earth.h"
#include "unitTest.h"
 /*******************************
   * TEST Collision
   ********************************/
class TestCollision : public UnitTest {
public:
	void run() {
		TwoNoCollision();
		SatEarthNoCollision();
		SatProjectileNoCollision();
		TwoCollision();
		SatEarthCollision();
		SatProjectileCollision();

		report("Collision");
	}

private:
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
	void TwoNoCollision() {
		Satellite* sat1 = new GPS(1);
		Satellite* sat2 = new GPS(2);
		assertUnit(c.IsColliding(*sat1, *sat2) != true);
	}


	/*********************************************
	 * name:    SAT EARTH NO COLLISION
	 * input:   GPS(1), Earth
	 * output:  false
	 *********************************************/
	void SatEarthNoCollision() {
		Satellite* sat = new GPS(1);
		Earth* earth = new Earth;
		assertUnit(c.IsColliding(*sat, *earth) != true);
	}


	/*********************************************
	 * name:    SAT PROJECTILE NO COLLISION
	 * input:   GPS(1), Projectile(0.0, 0.0)
	 * output:  false
	 *********************************************/
	void SatProjectileNoCollision() {
		Satellite* sat = new GPS(1);
		Projectile* projectile = new Projectile(0.0, 0.0);
		assertUnit(c.IsColliding(*sat, *projectile) != true);
	}


	/*********************************************
	 * name:    TWO COLLISION
	 * input:   GPS(1), GPS(1)
	 * output:  true
	 *********************************************/
	void TwoCollision() {
		Satellite* sat1 = new GPS(1);
		Satellite* sat2 = new GPS(1);
		assertUnit(c.IsColliding(*sat1, *sat2) == true);
	}


	/*********************************************
	 * name:    SAT EARTH COLLISION
	 * input:   Hubble(0.0, 0.0), Earth
	 * output:  false
	 *********************************************/
	void SatEarthCollision() {
		Satellite* sat = new Hubble(0.0, 0.0);
		Earth* earth = new Earth;
		assertUnit(c.IsColliding(*sat, *earth) == true);
	}


	/*********************************************
	 * name:    SAT PROJECTILE NO COLLISION
	 * input:   Hubble(100.0, 100.0), Projectile(100.0, 100.0)
	 * output:  false
	 *********************************************/
	void SatProjectileCollision() {
		Satellite* sat = new Hubble(100.0, 100.0);
		Projectile* projectile = new Projectile(100.0, 100.0);
		assertUnit(c.IsColliding(*sat, *projectile) == true);
	}
};