/***********************************************************************
 * Header File:
 *    TEST Sputnik
 * Summary:
 *    The unit tests for the Sputnik
 ************************************************************************/
#pragma once
#include "unitTest.h"

#include "satelliteSputnik.h"
#include "satellite.h"
#include "uiDraw.h"
#include <cassert>  

#define _USE_MATH_DEFINES

using namespace std;

/***************************************************
 * Sputnik TEST
 * Test the Sputnik class
 ***************************************************/
class TestSputnik : public UnitTest
{
public:

    void run()
    {
        defaultConstructor();

        report("Sputnik");
    }
private:

    void defaultConstructor()
    {
        // SETUP
        Sputnik s;
        float radius = s.getRadius();
        // Action

        //Test
        assertEquals(radius, 4.0);

        // TEARDOWN

    }

};