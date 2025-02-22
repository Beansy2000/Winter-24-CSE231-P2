/***********************************************************************
 * Header File:
 *    TEST CrewDragon
 * Summary:
 *    The unit tests for the Crew Dragon
 ************************************************************************/
#pragma once
#include "unitTest.h"

#include "satelliteCrewDragon.h"
#include "satellite.h"
#include "uiDraw.h"
#include <cassert>  

#define _USE_MATH_DEFINES

using namespace std;

/***************************************************
 * Crew Dragon TEST
 * Test the Crew Dragon class
 ***************************************************/
class TestCrewDragon : public UnitTest
{
public:

    void run()
    {
        defaultConstructor();

        report("Crew Dragon");
    }
private:

    void defaultConstructor()
    {
        // SETUP
        CrewDragon c;
        float radius = c.getRadius();
        // Action

        //Test
        assertEquals(radius, 7.0);

        // TEARDOWN

    }

};

