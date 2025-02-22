/***********************************************************************
 * Header File:
 *    TEST GPS
 * Summary:
 *    The unit tests for the Gps satellite
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

 /***************************************************
  * GPS TEST
  * Test the Gps class
  ***************************************************/
class TestGps : public UnitTest
{
public:

    void run()
    {
        //defaultConstructor();

        report("Gps");
    }
private:

    void defaultConstructor();
};
