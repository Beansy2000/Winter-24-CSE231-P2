/***********************************************************************
 * Header File:
 *    TEST Hubble
 * Summary:
 *    The unit tests for the Hubble
 ************************************************************************/
#pragma once
#include "unitTest.h"

#include "satelliteHubble.h"
#include "satellite.h"
#include "uiDraw.h"
#include <cassert>  

#define _USE_MATH_DEFINES

using namespace std;

/***************************************************
 * Hubble TEST
 * Test the Hubble class
 ***************************************************/
class TestHubble : public UnitTest
{
public:

    void run()
    {
        defaultConstructor();

        report("Hubble");
    }
private:

    void defaultConstructor()
    {
        // SETUP
        Hubble h;
        float radius = h.getRadius();
        // Action

        //Test
        assertEquals(radius, 10.0);

        // TEARDOWN

    }

};
