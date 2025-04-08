/***********************************************************************
 * Test File:
 *    Acceleration
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Acceleration test class
 ************************************************************************/
#pragma once

#include "unitTest.h"
#include "acceleration.h"
#include "angle.h"

 /*********************************************
  * TEST ACCELERATION
  * Unit tests for Acceleration
  *********************************************/
class TestAcceleration : public UnitTest
{
public:
    void run();

private:
    void constructor_default();
    void constructor_nonDefault();
    void getDDX();
    void getDDY();
    void setDDX();
    void setDDY();
    void set_up();
    void set_down();
    void set_right();
    void set_left();
    void set_diagonal();
    void addDDX_zero();
    void addDDX_value();
    void addDDY_zero();
    void addDDY_value();
    void add_zeroZero();
    void add_valueZero();
    void add_zeroValue();
    void add_valueValue();
};