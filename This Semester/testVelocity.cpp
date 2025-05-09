/***********************************************************************
 * Source File:
 *    TEST VELOCITY
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Testing Velocity
 ************************************************************************/
#pragma once

#include "testVelocity.h"

 /*************************************
  * TESTVELOCITY : RUN
  *************************************/
void TestVelocity::run() {
    constructor_default();
    constructor_nonDefault();
    getDX();
    getDY();
    getSpeed_up();
    getSpeed_down();
    getSpeed_left();
    getSpeed_right();
    getSpeed_diagonal();
    setDX();
    setDY();
    set_up();
    set_down();
    set_left();
    set_right();
    set_diagonal();
    addDX_zero();
    addDX_value();
    addDY_zero();
    addDY_value();
    add_stationary();
    add_noTime();
    add_moving4Seconds();
    add_moving1Second();
    addV_stationary();
    addV_nothing();
    addV_moving();

    report("Velocity");
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
void TestVelocity::constructor_default()
{  // setup
   // exercise
    Velocity v;

    // verify
    assertEquals(v.getDX(), 0.0);
    assertEquals(v.getDY(), 0.0);
}  // teardown

/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   2.3, 4.5
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::constructor_nonDefault()
{  // setup
    double dx = 2.3;
    double dy = 4.5;

    // exercise
    Velocity v(dx, dy);

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 4.5);
    assertEquals(dx, 2.3);
    assertEquals(dy, 4.5);
}  // teardown

/*****************************************************************
 *****************************************************************
 * GETTERS
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    GET DX
  * input:   (2.3, 4.5)
  * output:  2.3
  *********************************************/
void TestVelocity::getDX()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    double dx = 99.9;

    // exercise
    dx = v.getDX();

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 4.5);
    assertEquals(dx, 2.3);
}  // teardown

/*********************************************
 * name:    GET DY
 * input:   (2.3, 4.5)
 * output:  4.5
 *********************************************/
void TestVelocity::getDY()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    double dy = 99.9;

    // exercise
    dy = v.getDY();

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 4.5);
    assertEquals(dy, 4.5);
}  // teardown

/*********************************************
 * name:    GET SPEED ZERO
 * input:   (0.0, 0.0)
 * output:  0.0
 *********************************************/
void TestVelocity::getSpeed_zero()
{  // setup
    Velocity v;
    v.setDX(0.0);
    v.setDY(0.0);
    double s = 99.9;

    // exercise
    s = v.getSpeed();

    // verify
    assertEquals(v.getDX(), 0.0);
    assertEquals(v.getDY(), 0.0);
    assertEquals(s, 0.0);
}  // teardown

/*********************************************
 * name:    GET SPEED RIGHT
 * input:   (2.3, 0.0)
 * output:  2.3
 *********************************************/
void TestVelocity::getSpeed_right()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(0.0);
    double s = 99.9;

    // exercise
    s = v.getSpeed();

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 0.0);
    assertEquals(s, 2.3);
}  // teardown

/*********************************************
 * name:    GET SPEED UP
 * input:   (0.0, 4.5)
 * output:  4.5
 *********************************************/
void TestVelocity::getSpeed_up()
{  // setup
    Velocity v;
    v.setDX(0.0);
    v.setDY(4.5);
    double s = 99.9;

    // exercise
    s = v.getSpeed();

    // verify
    assertEquals(v.getDX(), 0.0);
    assertEquals(v.getDY(), 4.5);
    assertEquals(s, 4.5);
}  // teardown

/*********************************************
 * name:    GET SPEED LEFT
 * input:   (-2.3, 0.0)
 * output:  2.3
 *********************************************/
void TestVelocity::getSpeed_left()
{  // setup
    Velocity v;
    v.setDX(-2.3);
    v.setDY(0.0);
    double s = 99.9;

    // exercise
    s = v.getSpeed();

    // verify
    assertEquals(v.getDX(), -2.3);
    assertEquals(v.getDY(), 0.0);
    assertEquals(s, 2.3);
}  // teardown

/*********************************************
 * name:    GET SPEED DOWN
 * input:   (0.0, -4.5)
 * output:  4.5
 *********************************************/
void TestVelocity::getSpeed_down()
{  // setup
    Velocity v;
    v.setDX(0.0);
    v.setDY(-4.5);
    double s = 99.9;

    // exercise
    s = v.getSpeed();

    // verify
    assertEquals(v.getDX(), 0.0);
    assertEquals(v.getDY(), -4.5);
    assertEquals(s, 4.5);
}  // teardown

/*********************************************
 * name:    GET SPEED DIAGONAL
 * input:   (3.0, -4.0)
 * output:  5.0
 *********************************************/
void TestVelocity::getSpeed_diagonal()
{  // setup
    Velocity v;
    v.setDX(3.0);
    v.setDY(-4.0);
    double s = 99.9;

    // exercise
    s = v.getSpeed();

    // verify
    assertEquals(v.getDX(), 3.0);
    assertEquals(v.getDY(), -4.0);
    assertEquals(s, 5.0);
}  // teardown

/*****************************************************************
 *****************************************************************
 * SETTERS
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    SET DX
  * input:   (99.9, 88.8) -1.1
  * output:  (-1.1, 88.8)
  *********************************************/
void TestVelocity::setDX()
{  // setup
    Velocity v;
    v.setDX(99.9);
    v.setDY(88.8);
    double dx = -1.1;

    // exercise
    v.setDX(dx);

    // verify
    assertEquals(v.getDX(), -1.1);
    assertEquals(v.getDY(), 88.8);
    assertEquals(dx, -1.1);
}  // teardown

/*********************************************
 * name:    SET DY
 * input:   (99.9, 88.8) -1.1
 * output:  (99.9, -1.1)
 *********************************************/
void TestVelocity::setDY()
{  // setup
    Velocity v;
    v.setDX(99.9);
    v.setDY(88.8);
    double dy = -1.1;

    // exercise
    v.setDY(dy);

    // verify
    assertEquals(v.getDX(), 99.9);
    assertEquals(v.getDY(), -1.1);
    assertEquals(dy, -1.1);
}  // teardown

/*********************************************
 * name:    SET UP
 * input:   (-99.9, -88.8) 0 degreess, 3.3
 * output:  (0.0, 3.3)
 *********************************************/
void TestVelocity::set_up()
{  // setup
    Velocity v;
    v.setDX(-99.9);
    v.setDY(-88.8);
    Angle angle;
    angle.setRadians(0.0); // up
    double magnitude = 3.3;

    // exercise
    v.set(angle, magnitude);

    // verify
    assertEquals(v.getDX(), 0.0);
    assertEquals(v.getDY(), 3.3);
    assertEquals(angle.getRadians(), 0.0);
    assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET DOWN
 * input:   (-99.9, -88.8) 180 degreess, 3.3
 * output:  (0.0, -3.3)
 *********************************************/
void TestVelocity::set_down()
{  // setup
    Velocity v;
    v.setDX(-99.9);
    v.setDY(-88.8);
    Angle angle;
    angle.setRadians(M_PI); // DOWN
    double magnitude = 3.3;

    // exercise
    v.set(angle, magnitude);

    // verify
    assertEquals(v.getDX(), 0.0);
    assertEquals(v.getDY(), -3.3);
    assertEquals(angle.getRadians(), M_PI);
    assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET RIGHT
 * input:   (-99.9, -88.8) 90 degreess, 3.3
 * output:  (3.3, 0.0)
 *********************************************/
void TestVelocity::set_right()
{  // setup
    Velocity v;
    v.setDX(-99.9);
    v.setDY(-88.8);
    Angle angle;
    angle.setRadians(M_PI_2); // RIGHT
    double magnitude = 3.3;

    // exercise
    v.set(angle, magnitude);

    // verify
    assertEquals(v.getDX(), 3.3);
    assertEquals(v.getDY(), 0.0);
    assertEquals(angle.getRadians(), M_PI_2);
    assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET LEFT
 * input:   (-99.9, -88.8) 270 degreess, 3.3
 * output:  (-3.3, 0.0)
 *********************************************/
void TestVelocity::set_left()
{  // setup
    Velocity v;
    v.setDX(-99.9);
    v.setDY(-88.8);
    Angle angle;
    angle.setRadians(M_PI_2 + M_PI); // LEFT
    double magnitude = 3.3;

    // exercise
    v.set(angle, magnitude);

    // verify
    assertEquals(v.getDX(), -3.3);
    assertEquals(v.getDY(), 0.0);
    assertEquals(angle.getRadians(), M_PI_2 + M_PI);
    assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET DIAGONAL
 * input:   (-99.9, -88.8) ~57 degreess, 1.0
 * output:  (0.84, 0.54)
 *********************************************/
void TestVelocity::set_diagonal()
{  // setup
    Velocity v;
    v.setDX(-99.9);
    v.setDY(-88.8);
    Angle angle;
    angle.setRadians(1.0); // up and right somewhat
    double magnitude = 1.0;

    // exercise
    v.set(angle, magnitude);

    // verify
    assertEquals(v.getDX(), 0.8414);
    assertEquals(v.getDY(), 0.5403);
    assertEquals(angle.getRadians(), 1.0);
    assertEquals(magnitude, 1.0);
}

/*****************************************************************
 *****************************************************************
 * ADD
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    ADD DX  zero
  * input:   (2.3, 4.5) 0.0
  * output:  (2.3, 4.5)
  *********************************************/
void TestVelocity::addDX_zero()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    double dx = 0.0;

    // exercise
    v.addDX(dx);

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 4.5);
    assertEquals(dx, 0.0);
}  // teardown

/*********************************************
 * name:    ADD DX  VALUE
 * input:   (2.3, 4.5) 4.1
 * output:  (6.4, 4.5)
 *********************************************/
void TestVelocity::addDX_value()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    double dx = 4.1;

    // exercise
    v.addDX(dx);

    // verify
    assertEquals(v.getDX(), 6.4);
    assertEquals(v.getDY(), 4.5);
    assertEquals(dx, 4.1);
}  // teardown

/*********************************************
 * name:    ADD DY  zero
 * input:   (2.3, 4.5) 0.0
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::addDY_zero()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    double dy = 0.0;

    // exercise
    v.addDY(dy);

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 4.5);
    assertEquals(dy, 0.0);
}  // teardown

/*********************************************
 * name:    ADD DY  VALUE
 * input:   (2.3, 4.5) 4.1
 * output:  (2.3, 8.6)
 *********************************************/
void TestVelocity::addDY_value()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    double dy = 4.1;

    // exercise
    v.addDY(dy);

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 8.6);
    assertEquals(dy, 4.1);
}  // teardown

/*********************************************
 * name:    ADD  STATIONARY
 * input:   v=(2.3, 4.5) a=(0.0, 0.0) t=0.0
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::add_stationary()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    Acceleration a;
    a.setDDX(0.0);
    a.setDDY(0.0);
    double t = 0.0;

    // exercise
    v.add(a, t);

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 4.5);
    assertEquals(a.getDDX(), 0.0);
    assertEquals(a.getDDY(), 0.0);
    assertEquals(t, 0.0);
}  // teardown

/*********************************************
 * name:    ADD  TIME IS ZERO
 * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=0.0
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::add_noTime()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    Acceleration a;
    a.setDDX(6.0);
    a.setDDY(7.0);
    double t = 0.0;

    // exercise
    v.add(a, t);

    // verify
    assertEquals(v.getDX(), 2.3);
    assertEquals(v.getDY(), 4.5);
    assertEquals(a.getDDX(), 6.0);
    assertEquals(a.getDDY(), 7.0);
    assertEquals(t, 0.0);
}  // teardown

/*********************************************
 * name:    ADD  ONE SECOND
 * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=1.0
 * output:  (8.3, 11.5)
 *********************************************/
void TestVelocity::add_moving1Second()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    Acceleration a;
    a.setDDX(6.0);
    a.setDDY(7.0);
    double t = 1.0;

    // exercise
    v.add(a, t);

    // verify
    assertEquals(v.getDX(), 8.3);  // 2.3 + 6.0*1
    assertEquals(v.getDY(), 11.5); // 4.5 + 7.0*1
    assertEquals(a.getDDX(), 6.0);
    assertEquals(a.getDDY(), 7.0);
    assertEquals(t, 1.0);
}  // teardown

/*********************************************
 * name:    ADD  FOUR SECONDS
 * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=4.0
 * output:  (14.3, 24.5)
 *********************************************/
void TestVelocity::add_moving4Seconds()
{  // setup
    Velocity v;
    v.setDX(2.3);
    v.setDY(4.5);
    Acceleration a;
    a.setDDX(3.0);
    a.setDDY(5.0);
    double t = 4.0;

    // exercise
    v.add(a, t);

    // verify
    assertEquals(v.getDX(), 14.3); // 2.3 + 3.0*4
    assertEquals(v.getDY(), 24.5); // 4.5 + 5.0*4
    assertEquals(a.getDDX(), 3.0);
    assertEquals(a.getDDY(), 5.0);
    assertEquals(t, 4.0);
}  // teardown

/*********************************************
 * name:    ADD  STATIONARY
 * input:   vLHS=(0, 0) vRHS=(2.3, 4.5)
 * output:  vLHS=(2.3, 4.5)
 *********************************************/
void TestVelocity::addV_stationary()
{
    // setup
    Velocity vLHS(0.0, 0.0);
    Velocity vRHS(2.3, 4.5);
    // exercise
    vLHS.add(vRHS);
    // verify
    assertEquals(vLHS.getDX(), 2.3);
    assertEquals(vLHS.getDY(), 4.5);
    // teardown
}

/*********************************************
 * name:    ADD  NOTHING
 * input:   vLHS=(2.3, 4.5) vRHS=(0, 0)
 * output:  vLHS=(2.3, 4.5)
 *********************************************/
void TestVelocity::addV_nothing()
{
    // setup
    Velocity vLHS(2.3, 4.5);
    Velocity vRHS(0.0, 0.0);
    // exercise
    vLHS.add(vRHS);
    // verify
    assertEquals(vLHS.getDX(), 2.3);
    assertEquals(vLHS.getDY(), 4.5);
    // teardown
}

/*********************************************
 * name:    ADD  MOVING
 * input:   vLHS=(2.3, 4.5) vRHS=(100, 200)
 * output:  vLHS=(102.3, 204.5)
 *********************************************/
void TestVelocity::addV_moving()
{
    // setup
    Velocity vLHS(2.3, 4.5);
    Velocity vRHS(100, 200);
    // exercise
    vLHS.add(vRHS);
    // verify
    assertEquals(vLHS.getDX(), 102.3);
    assertEquals(vLHS.getDY(), 204.5);
    // teardown
}