/***********************************************************************
 * Header File:
 *    TEST Starlink
 * Summary:
 *    The unit tests for the Starlink
 ************************************************************************/
#pragma once
#include "unitTest.h"

#include "satelliteStarlink.h"
#include "satellite.h"
#include "uiDraw.h"
#include <cassert>  

#define _USE_MATH_DEFINES

using namespace std;

/***************************************************
 * Starlink TEST
 * Test the Starlink class
 ***************************************************/
class TestStarlink : public UnitTest
{
public:

    void run()
    {
        defaultConstructor();

        report("Starlink");
    }
private:

    void defaultConstructor()
    {
        // SETUP
        Starlink s;
        float radius = s.getRadius();
        // Action

        //Test
        assertEquals(radius, 6.0);

        // TEARDOWN

    }

};

