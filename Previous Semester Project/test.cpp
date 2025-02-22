/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testAngle.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testAcceleration.h"
#include "testGps.h"
#include "testCrewDragon.h"
#include "testHubble.h"
#include "testSputnik.h"
#include "testStarlink.h"


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
   TestAngle().run();
   TestAcceleration().run();
   TestVelocity().run();
   TestGps().run();
   TestCrewDragon().run();
   TestHubble().run();
   TestSputnik().run();
   TestStarlink().run();
}
