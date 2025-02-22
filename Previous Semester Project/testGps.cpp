/***********************************************************************
 * Source File:
 *    TEST GPS
 * Summary:
 *    The unit tests for a Gps satellite
 ************************************************************************/

#pragma once
#include "unitTest.h"

#include "testGps.h"
#include "satelliteGps.h"
#include "satellite.h"
#include "uiDraw.h"
#include <cassert>  

#define _USE_MATH_DEFINES

using namespace std;

 /*************************************

  **************************************/
void TestGps::defaultConstructor()
{
    // SETUP
    Gps g = Gps(1);
    float radius = g.getRadius();
    // Action

    //Test
    assertEquals(radius , 12.0);

    // TEARDOWN

}
