/***********************************************************************
 * Test File:
 *    SPUTNIK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Satellite test class
 ************************************************************************/
#pragma once

#include "satelliteSputnik.h"
#include "unitTest.h"
#include "position.h"
#include "velocity.h"

 /*********************************************
  * TEST SPUTNIK
  *********************************************/
class TestSputnik : public UnitTest {
public:
	void run();
private:
	void defaultConstructor();
};