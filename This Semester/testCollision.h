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
   * TEST COLLISION
   ********************************/
class TestCollision : public UnitTest {
public:
	void run();

private:
	void TwoNoCollision();
	void SatEarthNoCollision();
	void SatProjectileNoCollision();
	void TwoCollision();
	void SatEarthCollision();
	void SatProjectileCollision();
};