#pragma once
/***********************************************************************
 * Test File:
 *    SHIP
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Hubble test class
 ************************************************************************/
#pragma once

#include "satelliteShip.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST SHIP
  *********************************************/
class TestShip : public UnitTest {
public:
	void run();
private:
	void defaultConstructor();
	void turnLeft();
	void turnRight();
	void moveForward();
};