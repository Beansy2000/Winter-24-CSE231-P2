/***********************************************************************
 * Test File:
 *    HUBBLE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Hubble test class
 ************************************************************************/
#pragma once

#include "satelliteHubble.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST HUBBLE
  *********************************************/
class TestHubble : public UnitTest {
public:
	void run();
private:
	void defaultConstructor();
};