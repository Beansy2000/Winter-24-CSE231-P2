/***********************************************************************
 * Source File:
 *    TEST ANGLE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Angle
 ************************************************************************/
#pragma once

#include "testAngle.h"

 /*************************************
  * TESTANGLE : RUN
  *************************************/
void TestAngle::run() {
    defaultConstructor();
    setUp();
    setDown();
    setRight();
    setLeft();
    reverse();
    setRadians_noNormalize();
    setDegrees_noNormalize();
    getDegrees_0();
    getDegrees_270();
    getRadians_0();
    getRadians_270();
    add_0();
    add_value();
    setRadians_negative();
    setRadians_oneLap();
    setRadians_sixLaps();
    setRadians_negativeThreeQuarters();
    setRadians_negativeOneLap();
    setRadians_negativeSixLaps();
    setDegrees_negative();
    setDegrees_oneLap();
    setDegrees_sixLaps();
    setDegrees_negativeThreeQuarters();
    setDegrees_negativeOneLap();
    setDegrees_negativeSixLaps();
    add_positiveLap();
    add_negativeLap();
    getDx_up();
    getDx_down();
    getDx_left();
    getDx_right();
    getDx_diagonal();
    getDy_up();
    getDy_down();
    getDy_left();
    getDy_right();
    getDy_diagonal();
    setDXY_up();
    setDXY_right();
    setDXY_left();
    setDXY_diagonal();

    report("Angle");
}


/*****************************************************************
 *****************************************************************
 * CONSTRUCTOR
 *****************************************************************
 *****************************************************************/


 /*********************************************
  * name:    DEFAULT CONSTRUCTOR
  * input:   nothing
  * output:  zero
  *********************************************/
void TestAngle::defaultConstructor()
{  // setup
   // exercise
    Angle a;
    // verify
    assertUnit(a.getRadians() == 0.0);
}  // teardown

/*****************************************************************
 *****************************************************************
 * SETTERS
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    SET UP
  * input:   nothing
  * output:  0 degrees
  *********************************************/
void TestAngle::setUp()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setUp();
    // verify
    assertEquals(a.getRadians(), 0.0);
}  // teardown

/*********************************************
 * name:    SET DOWN
 * input:   nothing
 * output:  180 degrees
 *********************************************/
void TestAngle::setDown()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDown();
    // verify
    assertEquals(a.getRadians(), M_PI);
}  // teardown

/*********************************************
 * name:    SET RIGHT
 * input:   nothing
 * output:  90 degrees
 *********************************************/
void TestAngle::setRight()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRight();
    // verify
    assertEquals(a.getRadians(), M_PI_2);
}  // teardown

/*********************************************
 * name:    SET LEFT
 * input:   nothing
 * output:  270 degrees
 *********************************************/
void TestAngle::setLeft()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setLeft();
    // verify
    assertEquals(a.getRadians(), M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    REVERSE
 * input:   90
 * output:  270 degrees
 *********************************************/
void TestAngle::reverse()
{  // setup
    Angle a;
    a.setRadians(M_PI_2); // 90 degrees
    // exercise
    a.reverse();
    // verify
    assertEquals(a.getRadians(), M_PI_2 + M_PI);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NO NORMALIZATION
 * input:   45 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_noNormalize()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRadians(0.785398);
    // verify
    assertEquals(a.getRadians(), 0.785398);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE
 * input:   -90
 * output:  270 degrees
 *********************************************/
void TestAngle::setRadians_negative()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRadians(-M_PI_2);
    // verify
    assertEquals(a.getRadians(), M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    SET RADIANS - ONE LAP
 * input:   45 + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_oneLap()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRadians(0.785398 + (M_PI * 2.0));
    // verify
    assertEquals(a.getRadians(), 0.785398);
}  // teardown

/*********************************************
 * name:    SET RADIANS - SIX LAP
 * input:   45 + (6 x 360) degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_sixLaps()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRadians(0.785398 + (M_PI * 2.0) * 6.0);
    // verify
    assertEquals(a.getRadians(), 0.785398);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE 3/4
 * input:   -270 degrees
 * output:  90 degrees
 *********************************************/
void TestAngle::setRadians_negativeThreeQuarters()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRadians(-M_PI - M_PI_2);
    // verify
    assertEquals(a.getRadians(), M_PI_2);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE ONE LAP
 * input:   -45 - 360 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setRadians_negativeOneLap()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRadians(-0.785398 - (M_PI * 2.0));
    // verify
    assertEquals(a.getRadians(), 5.49779);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE SIX LAP
 * input:   -45 - 360*6 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setRadians_negativeSixLaps()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setRadians(-0.785398 - (M_PI * 2.0) * 6.0);
    // verify
    assertEquals(a.getRadians(), 5.49779);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NO NORMALIZATION
 * input:   45 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setDegrees_noNormalize()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDegrees(45.0);
    // verify
    assertEquals(a.getRadians(), 0.785398);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE
 * input:   -90
 * output:  270 degrees
 *********************************************/
void TestAngle::setDegrees_negative()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDegrees(-90.0);
    // verify
    assertEquals(a.getRadians(), M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    SET DEGREES - ONE LAP
 * input:   45 + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setDegrees_oneLap()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDegrees(45.0 + 360.0);
    // verify
    assertEquals(a.getRadians(), 0.785398);
}  // teardown

/*********************************************
 * name:    SET DEGREES - SIX LAP
 * input:   45 + (6 x 360) degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setDegrees_sixLaps()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDegrees(45.0 + 360.0 * 6.0);
    // verify
    assertEquals(a.getRadians(), 0.785398);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE 3/4
 * input:   -270 degrees
 * output:  90 degrees
 *********************************************/
void TestAngle::setDegrees_negativeThreeQuarters()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDegrees(-270.0);
    // verify
    assertEquals(a.getRadians(), M_PI_2);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE ONE LAP
 * input:   -45 - 360 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setDegrees_negativeOneLap()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDegrees(-45.0 - 360.0);
    // verify
    assertEquals(a.getRadians(), 5.49779);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE SIX LAP
 * input:   -45 - 360*6 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setDegrees_negativeSixLaps()
{  // setup
    Angle a;
    a.setRadians(-99.9);
    // exercise
    a.setDegrees(-45.0 - 360.0 * 6.0);
    // verify
    assertEquals(a.getRadians(), 5.49779);
}  // teardown

/*****************************************************************
 *****************************************************************
 * ADD
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    ADD ZERO
  * input:   (45 degrees) 0
  * output:  45 degrees
  *********************************************/
void TestAngle::add_0()
{  // setup
    Angle a;
    a.setRadians(0.785398);
    double r = 0.0;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.getRadians(), 0.785398);
    assertEquals(r, 0.0);
}  // teardown

/*********************************************
 * name:    ADD VALUE
 * input:   (45 degrees) 180 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::add_value()
{  // setup
    Angle a;
    a.setRadians(0.785398);
    double r = M_PI;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.getRadians(), 0.785398 + M_PI);
    assertEquals(r, M_PI);
}  // teardown

/*********************************************
 * name:    ADD POSITIVE ONE LAP
 * input:   (45 degrees) 180 + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::add_positiveLap()
{  // setup
    Angle a;
    a.setRadians(0.785398);
    double r = M_PI + M_PI * 2.0;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.getRadians(), 0.785398 + M_PI);
    assertEquals(r, M_PI + M_PI * 2.0);
}  // teardown

/*********************************************
 * name:    ADD NEGATIVE ONE LAP
 * input:   (45 degrees) -90 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::add_negativeLap()
{  // setup
    Angle a;
    a.setRadians(0.785398);
    double r = -M_PI_2;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.getRadians(), 5.49779);
    assertEquals(r, -M_PI_2);
}  // teardown

/*********************************************
 * name:    SET DX, DY  UP
 * input:   dx=0 dy=1
 * output:  0 degrees
 *********************************************/
void TestAngle::setDXY_up()
{  // setup
    Angle a;
    a.setRadians(1.234567);
    double dx = 0.0;
    double dy = 1.0;

    // exercise
    a.setDXY(dx, dy);

    // verify
    assertEquals(a.getRadians(), 0.0);
}  // teardown


/*********************************************
 * name:    SET DX DY  RIGHT
 * input:   dx=4 dy=0
 * output:  90 degrees
 *********************************************/
void TestAngle::setDXY_right()
{  // setup
    Angle a;
    a.setRadians(1.234567);
    double dx = 4.0;
    double dy = 0.0;

    // exercise
    a.setDXY(dx, dy);

    // verify
    assertEquals(a.getRadians(), 1.5708);
}  // teardown

/*********************************************
 * name:    SET DX DY  LEFT
 * input:   dx=-0.01 dy=0
 * output:  270 degrees
 *********************************************/
void TestAngle::setDXY_left()
{  // setup
    Angle a;
    a.setRadians(1.234567);
    double dx = -0.01;
    double dy = 0.0;

    // exercise
    a.setDXY(dx, dy);

    // verify
    assertEquals(a.getRadians(), 4.71239);
}  // teardown

/*********************************************
 * name:    SET DX DY  DIAGONAL
 * input:   dx= 5.0 dy=8.6602
 * output:  30 degrees
 *********************************************/
void TestAngle::setDXY_diagonal()
{  // setup
    Angle a;
    a.setRadians(1.234567);
    double dx = 5.0;
    double dy = 8.6602;

    // exercise
    a.setDXY(dx, dy);

    // verify
    assertEquals(a.getRadians(), M_PI / 6.0);
}  // teardown


/*****************************************************************
 *****************************************************************
 * GETTERS
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    GET DEGREES - 0
  * input:   0 degrees
  * output:  0 degrees
  *********************************************/
void TestAngle::getDegrees_0()
{  // setup
    Angle a;
    a.setRadians(0.0);
    double d = -99.9;
    // exercise
    d = a.getDegrees();
    // verify
    assertEquals(d, 0.0);
    assertEquals(a.getRadians(), 0.0);
}  // teardown

/*********************************************
 * name:    GET DEGREES - 270
 * input:   270 degrees
 * output:  270 degrees
 *********************************************/
void TestAngle::getDegrees_270()
{  // setup
    Angle a;
    a.setRadians(M_PI + M_PI_2);
    double d = -99.9;
    // exercise
    d = a.getDegrees();
    // verify
    assertEquals(d, 270.0);
    assertEquals(a.getRadians(), M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    GET RADIANS - 0
 * input:   0 degrees
 * output:  0 degrees
 *********************************************/
void TestAngle::getRadians_0()
{  // setup
    Angle a;
    a.setRadians(0.0);
    double r = -99.9;
    // exercise
    r = a.getRadians();
    // verify
    assertEquals(r, 0.0);
    assertEquals(a.getRadians(), 0.0);
}  // teardown

/*********************************************
 * name:    GET RADIANS - 270
 * input:   270 degrees
 * output:  270 degrees
 *********************************************/
void TestAngle::getRadians_270()
{  // setup
    Angle a;
    a.setRadians(M_PI + M_PI_2);
    double r = -99.9;
    // exercise
    r = a.getRadians();
    // verify
    assertEquals(r, M_PI + M_PI_2);
    assertEquals(a.getRadians(), M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    GET DX - UP
 * input:   0 degrees
 * output:  0
 *********************************************/
void TestAngle::getDx_up()
{  // setup
    Angle a;
    a.setRadians(0.0);
    double dx = -99.9;
    // exercise
    dx = a.getDx();
    // verify
    assertEquals(dx, 0.0);
    assertEquals(a.getRadians(), 0.0);
}  // teardown

/*********************************************
 * name:    GET DX - DOWN
 * input:   180 degrees
 * output:  0
 *********************************************/
void TestAngle::getDx_down()
{  // setup
    Angle a;
    a.setRadians(M_PI);
    double dx = -99.9;
    // exercise
    dx = a.getDx();
    // verify
    assertEquals(dx, 0.0);
    assertEquals(a.getRadians(), M_PI);
}  // teardown


/*********************************************
 * name:    GET DX - LEFT
 * input:   270 degrees
 * output:  -1
 *********************************************/
void TestAngle::getDx_left()
{  // setup
    Angle a;
    a.setRadians(4.71239);
    double dx = -99.9;
    // exercise
    dx = a.getDx();
    // verify
    assertEquals(dx, -1.0);
    assertEquals(a.getRadians(), 4.71239);
}  // teardown

/*********************************************
 * name:    GET DX - RIGHT
 * input:   90 degrees
 * output:  1
 *********************************************/
void TestAngle::getDx_right()
{  // setup
    Angle a;
    a.setRadians(1.5708);
    double dx = -99.9;
    // exercise
    dx = a.getDx();
    // verify
    assertEquals(dx, 1.0);
    assertEquals(a.getRadians(), 1.5708);
}  // teardown

/*********************************************
 * name:    GET DX - DIAGONAL
 * input:   30 degrees
 * output:  0.5
 *********************************************/
void TestAngle::getDx_diagonal()
{  // setup
    Angle a;
    a.setRadians(M_PI / 6.0); // 30 degrees
    double dx = -99.9;
    // exercise
    dx = a.getDx();
    // verify
    assertEquals(dx, 0.5);
    assertEquals(a.getRadians(), M_PI / 6.0);
}  // teardown


/*********************************************
 * name:    GET DY - UP
 * input:   0 degrees
 * output:  1
 *********************************************/
void TestAngle::getDy_up()
{  // setup
    Angle a;
    a.setRadians(0.0);
    double dy = -99.9;
    // exercise
    dy = a.getDy();
    // verify
    assertEquals(dy, 1.0);
    assertEquals(a.getRadians(), 0.0);
}  // teardown

/*********************************************
 * name:    GET DY - DOWN
 * input:   180 degrees
 * output:  -1
 *********************************************/
void TestAngle::getDy_down()
{  // setup
    Angle a;
    a.setRadians(M_PI);
    double dy = -99.9;
    // exercise
    dy = a.getDy();
    // verify
    assertEquals(dy, -1.0);
    assertEquals(a.getRadians(), M_PI);
}  // teardown


/*********************************************
 * name:    GET DY - LEFT
 * input:   270 degrees
 * output:  0
 *********************************************/
void TestAngle::getDy_left()
{  // setup
    Angle a;
    a.setRadians(4.71239);
    double dy = -99.9;
    // exercise
    dy = a.getDy();
    // verify
    assertEquals(dy, 0.0);
    assertEquals(a.getRadians(), 4.71239);
}  // teardown

/*********************************************
 * name:    GET DY - RIGHT
 * input:   90 degrees
 * output:  0
 *********************************************/
void TestAngle::getDy_right()
{  // setup
    Angle a;
    a.setRadians(1.5708);
    double dy = -99.9;
    // exercise
    dy = a.getDy();
    // verify
    assertEquals(dy, 0.0);
    assertEquals(a.getRadians(), 1.5708);
}  // teardown

/*********************************************
 * name:    GET DY - DIAGONAL
 * input:   30 degrees
 * output:  0.5
 *********************************************/
void TestAngle::getDy_diagonal()
{  // setup
    Angle a;
    a.setRadians(M_PI / 6.0); // 30 degrees
    double dy = -99.9;
    // exercise
    dy = a.getDy();
    // verify
    assertEquals(dy, 0.866025);
    assertEquals(a.getRadians(), M_PI / 6.0);
}  // teardown