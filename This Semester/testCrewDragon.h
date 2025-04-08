/***********************************************************************
 * Test File:
 *    CREWDRAGON
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Crew Dragon test class
 ************************************************************************/
#pragma once

#include "satelliteCrewDragon.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST CREWDRAGON
  *********************************************/
class TestCrewDragon : public UnitTest {
public:
	void run();
private:
	void defaultConstructor();
};