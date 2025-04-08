/***********************************************************************
 * Test File:
 *    Angle
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Angle test class
 ************************************************************************/
#pragma once

#include "angle.h"
#include "unitTest.h"
 /*******************************
   * TEST ANGLE
   * A friend class for Angle which contains the Angle unit tests
   ********************************/
class TestAngle : public UnitTest
{
public:
    void run();

private:
    void defaultConstructor();
    void setUp();
    void setDown();
    void setRight();
    void setLeft();
    void reverse();
    void setRadians_noNormalize();
    void setRadians_negative();
    void setRadians_oneLap();
    void setRadians_sixLaps();
    void setRadians_negativeThreeQuarters();
    void setRadians_negativeOneLap();
    void setRadians_negativeSixLaps();
    void setDegrees_noNormalize();
    void setDegrees_negative();
    void setDegrees_oneLap();
    void setDegrees_sixLaps();
    void setDegrees_negativeThreeQuarters();
    void setDegrees_negativeOneLap();
    void setDegrees_negativeSixLaps();
    void add_0();
    void add_value();
    void add_positiveLap();
    void add_negativeLap();
    void setDXY_up();
    void setDXY_right();
    void setDXY_left();
    void setDXY_diagonal();
    void getDegrees_0();
    void getDegrees_270();
    void getRadians_0();
    void getRadians_270();
    void getDx_up();
    void getDx_down();
    void getDx_left();
    void getDx_right();
    void getDx_diagonal();
    void getDy_up();
    void getDy_down();
    void getDy_left();
    void getDy_right();
    void getDy_diagonal();
};