/***********************************************************************
 * Test File:
 *    SATELLITE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Satellite test class
 ************************************************************************/
#pragma once

#include "satellite.h"
#include "unitTest.h"


 /*********************************************
  * TEST SATELLITE
  *********************************************/
class TestSatellite : public UnitTest {
public:
	void run();
private:
	void defaultConstructor();
};