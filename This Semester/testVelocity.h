/***********************************************************************
 * Test File:
 *    Velocity
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Velocity test class
 ************************************************************************/
#pragma once

#include "unitTest.h"
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"

 /*********************************************
  * TEST VELOCITY
  * Unit tests for Velocity
  *********************************************/
class TestVelocity : public UnitTest
{
public:
    void run();

private:
    void constructor_default();
    void constructor_nonDefault();
    void getDX();
    void getDY();
    void getSpeed_zero();
    void getSpeed_right();
    void getSpeed_up();
    void getSpeed_left();
    void getSpeed_down();
    void getSpeed_diagonal();
    void setDX();
    void setDY();
    void set_up();
    void set_down();
    void set_right();
    void set_left();
    void set_diagonal();
    void addDX_zero();
    void addDX_value();
    void addDY_zero();
    void addDY_value();
    void add_stationary();
    void add_noTime();
    void add_moving1Second();
    void add_moving4Seconds();
    void addV_stationary();
    void addV_nothing();
    void addV_moving();

};