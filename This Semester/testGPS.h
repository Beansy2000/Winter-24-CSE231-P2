/***********************************************************************
 * Test File:
 *    GPS
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Crew Dragon test class
 ************************************************************************/
#pragma once

#include "satelliteGPS.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST GPS
  *********************************************/
class TestGPS : public UnitTest {
public:
	void run();
private:
	void defaultConstructor();
	void Constructor1();
	void Constructor2();
	void Constructor3();
	void Constructor4();
	void Constructor5();
	void Constructor6();
};