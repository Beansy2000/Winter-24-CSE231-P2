/***********************************************************************
 * Test File:
 *    STARLINK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Satellite test class
 ************************************************************************/
#pragma once

#include "satelliteStarlink.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST STARLINK
  *********************************************/
class TestStarlink : public UnitTest {
public:
	void run();
private:
	void defaultConstructor();
};