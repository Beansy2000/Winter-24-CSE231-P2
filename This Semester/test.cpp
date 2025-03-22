/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testAcceleration.h"
#include "testAngle.h"
#include "testVelocity.h"
#include "testSatellite.h"
#include "testSputnik.h"
#include "testCrewDragon.h"
#include "testGPS.h"
#include "testHubble.h"
#include "testShip.h"
#include "testStarlink.h"
#include "testCollision.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestAcceleration().run();
   TestAngle().run();
   TestVelocity().run();
   TestSatellite().run();
   TestSputnik().run();
   TestCrewDragon().run();
   TestGPS().run();
   TestHubble().run();
   testShip().run();
   TestStarlink().run();
   TestCollision().run();
}
