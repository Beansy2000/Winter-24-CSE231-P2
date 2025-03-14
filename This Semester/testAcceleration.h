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
    void run()
    {
        constructor_default();
        constructor_nonDefault();
        getDDX();
        getDDY();
        setDDX();
        setDDY();
        set_up();
        set_down();
        set_left();
        set_right();
        set_diagonal();
        addDDX_zero();
        addDDX_value();
        addDDY_zero();
        addDDY_value();
        add_zeroZero();
        add_valueZero();
        add_zeroValue();
        add_valueValue();

        report("Acceleration");
    }

private:


    /*****************************************************************
     *****************************************************************
     * CONSTRUCTOR
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    DEFAULT CONSTRUCTOR
      * input:   nothing
      * output:  zeros
      *********************************************/
    void constructor_default()
    {  // setup
       // exercise
        Acceleration a;

        // verify
        assertEquals(a.getDDX(), 0.0);
        assertEquals(a.getDDY(), 0.0);
    }  // teardown

    /*********************************************
     * name:    NON-DEFAULT CONSTRUCTOR
     * input:   2.3, 4.5
     * output:  (2.3, 4.5)
     *********************************************/
    void constructor_nonDefault()
    {  // setup
        double ddx = 2.3;
        double ddy = 4.5;
        // exercise
        Acceleration a(ddx, ddy);

        // verify
        assertEquals(a.getDDX(), 2.3);
        assertEquals(a.getDDY(), 4.5);
        assertEquals(ddx, 2.3);
        assertEquals(ddy, 4.5);
    }  // teardown


    /*****************************************************************
     *****************************************************************
     * GETTERS
     *****************************************************************
     *****************************************************************/


     /*********************************************
      * name:    GET DDX
      * input:   (2.3, 4.5)
      * output:  2.3
      *********************************************/
    void getDDX()
    {  // setup
        Acceleration a;
        a.setDDX(2.3);
        a.setDDY(4.5);
        double ddx = 99.9;

        // exercise
        ddx = a.getDDX();

        // verify
        assertEquals(a.getDDX(), 2.3);
        assertEquals(a.getDDY(), 4.5);
        assertEquals(ddx, 2.3);
    }  // teardown

    /*********************************************
     * name:    GET DDY
     * input:   (2.3, 4.5)
     * output:  4.5
     *********************************************/
    void getDDY()
    {  // setup
        Acceleration a;
        a.setDDX(2.3);
        a.setDDY(4.5);
        double ddy = 99.9;

        // exercise
        ddy = a.getDDY();

        // verify
        assertEquals(a.getDDX(), 2.3);
        assertEquals(a.getDDY(), 4.5);
        assertEquals(ddy, 4.5);
    }  // teardown


    /*****************************************************************
     *****************************************************************
     * SETTERS
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    SET DDX
      * input:   (-99.9, -88.8) 11.1
      * output:  (11.1, -88.8)
      *********************************************/
    void setDDX()
    {  // setup
        Acceleration a;
        a.setDDX(-99.9);
        a.setDDY(-88.8);

        // exercise
        a.setDDX(11.1);

        // verify
        assertEquals(a.getDDX(), 11.1);
        assertEquals(a.getDDY(), -88.8);
    }

    /*********************************************
     * name:    SET DDX
     * input:   (-99.9, -88.8) 11.1
     * output:  (-99.9, 11.1)
     *********************************************/
    void setDDY()
    {  // setup
        Acceleration a;
        a.setDDX(-99.9);
        a.setDDY(-88.8);

        // exercise
        a.setDDY(11.1);

        // verify
        assertEquals(a.getDDX(), -99.9);
        assertEquals(a.getDDY(), 11.1);
    }

    /*********************************************
     * name:    SET UP
     * input:   (-99.9, -88.8) 0 degrees, 3.3
     * output:  (0.0, 3.3)
     *********************************************/
    void set_up()
    {  // setup
        Acceleration a;
        a.setDDX(-99.9);
        a.setDDY(-88.8);
        Angle angle;
        angle.setRadians(0.0); // up
        double magnitude = 3.3;

        // exercise
        a.set(angle, magnitude);

        // verify
        assertEquals(a.getDDX(), 0.0);
        assertEquals(a.getDDY(), 3.3);
        assertEquals(angle.getRadians(), 0.0);
        assertEquals(magnitude, 3.3);
    }

    /*********************************************
     * name:    SET DOWN
     * input:   (-99.9, -88.8) 180 degrees, 3.3
     * output:  (0.0, -3.3)
     *********************************************/
    void set_down()
    {  // setup
        Acceleration a;
        a.setDDX(-99.9);
        a.setDDY(-88.8);
        Angle angle;
        angle.setRadians(M_PI); // DOWN
        double magnitude = 3.3;

        // exercise
        a.set(angle, magnitude);

        // verify
        assertEquals(a.getDDX(), 0.0);
        assertEquals(a.getDDY(), -3.3);
        assertEquals(angle.getRadians(), M_PI);
        assertEquals(magnitude, 3.3);
    }

    /*********************************************
     * name:    SET RIGHT
     * input:   (-99.9, -88.8) 90 degrees, 3.3
     * output:  (3.3, 0.0)
     *********************************************/
    void set_right()
    {  // setup
        Acceleration a;
        a.setDDX(-99.9);
        a.setDDY(-88.8);
        Angle angle;
        angle.setRadians(M_PI_2); // RIGHT
        double magnitude = 3.3;

        // exercise
        a.set(angle, magnitude);

        // verify
        assertEquals(a.getDDX(), 3.3);
        assertEquals(a.getDDY(), 0.0);
        assertEquals(angle.getRadians(), M_PI_2);
        assertEquals(magnitude, 3.3);
    }

    /*********************************************
     * name:    SET LEFT
     * input:   (-99.9, -88.8) 270 degrees, 3.3
     * output:  (3.3, 0.0)
     *********************************************/
    void set_left()
    {  // setup
        Acceleration a;
        a.setDDX(-99.9);
        a.setDDY(-88.8);
        Angle angle;
        angle.setRadians(M_PI_2 + M_PI); // RIGHT
        double magnitude = 3.3;

        // exercise
        a.set(angle, magnitude);

        // verify
        assertEquals(a.getDDX(), -3.3);
        assertEquals(a.getDDY(), 0.0);
        assertEquals(angle.getRadians(), M_PI_2 + M_PI);
        assertEquals(magnitude, 3.3);
    }

    /*********************************************
     * name:    SET DIAGONAL
     * input:   (-99.9, -88.8) 57 degrees, 1.0
     * output:  (0.84, 0.54)
     *********************************************/
    void set_diagonal()
    {  // setup
        Acceleration a;
        a.setDDX(-99.9);
        a.setDDY(-88.8);
        Angle angle;
        angle.setRadians(1.0); // up and right somewhat
        double magnitude = 1.0;

        // exercise
        a.set(angle, magnitude);

        // verify
        assertEquals(a.getDDX(), 0.8414);
        assertEquals(a.getDDY(), 0.5403);
        assertEquals(angle.getRadians(), 1.0);
        assertEquals(magnitude, 1.0);
    }

    /*****************************************************************
     *****************************************************************
     * SETTERS
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    ADD DDX ZERO
      * input:   a=(2.3, 4.5) ddx=0.0
      * output:  a=(2.3, 4.5)
      *********************************************/
    void addDDX_zero()
    {  // setup
        Acceleration a;
        a.setDDX(2.3);
        a.setDDY(4.5);

        // exercise
        a.addDDX(0.0);

        // verify
        assertEquals(a.getDDX(), 2.3);
        assertEquals(a.getDDY(), 4.5);
    }  // teardown

    /*********************************************
     * name:    ADD DDX 4.1
     * input:   a=(2.3, 4.5) ddx=4.1
     * output:  a=(6.4, 4.5)
     *********************************************/
    void addDDX_value()
    {  // setup
        Acceleration a;
        a.setDDX(2.3);
        a.setDDY(4.5);

        // exercise
        a.addDDX(4.1);

        // verify
        assertEquals(a.getDDX(), 6.4);
        assertEquals(a.getDDY(), 4.5);
    }  // teardown


    /*********************************************
     * name:    ADD DDY ZERO
     * input:   a=(2.3, 4.5) ddy=0.0
     * output:  a=(2.3, 4.5)
     *********************************************/
    void addDDY_zero()
    {  // setup
        Acceleration a;
        a.setDDX(2.3);
        a.setDDY(4.5);

        // exercise
        a.addDDY(0.0);

        // verify
        assertEquals(a.getDDX(), 2.3);
        assertEquals(a.getDDY(), 4.5);
    }  // teardown

    /*********************************************
     * name:    ADD DDY 4.1
     * input:   a=(2.3, 4.5) ddy=4.1
     * output:  a=(2.3, 8.6)
     *********************************************/
    void addDDY_value()
    {  // setup
        Acceleration a;
        a.setDDX(2.3);
        a.setDDY(4.5);

        // exercise
        a.addDDY(4.1);

        // verify
        assertEquals(a.getDDX(), 2.3);
        assertEquals(a.getDDY(), 8.6);
    }  // teardown

    /*********************************************
     * name:    ADD NOTHING TO NOTHING
     * input:   aLHS=(0.0, 0.0) aRHS=(0.0, 0.0)
     * output:  aLHS=(0.0, 0.0)
     *********************************************/
    void add_zeroZero()
    {  // setup
        Acceleration a;
        a.setDDX(0.0);
        a.setDDY(0.0);

        Acceleration b;
        b.setDDX(0.0);
        b.setDDY(0.0);

        // exercise
        a.add(b);

        // verify
        assertEquals(a.getDDX(), 0.0);
        assertEquals(a.getDDY(), 0.0);
    }  // teardown

    /*********************************************
     * name:    ADD NOTHING TO A VALUE
     * input:   aLHS=(1.1, 2.2) aRHS=(0.0, 0.0)
     * output:  aLHS=(1.1, 2.2)
     *********************************************/
    void add_valueZero()
    {  // setup
        Acceleration a;
        a.setDDX(1.1);
        a.setDDY(2.2);

        Acceleration b;
        b.setDDX(0.0);
        b.setDDY(0.0);

        // exercise
        a.add(b);

        // verify
        assertEquals(a.getDDX(), 1.1);
        assertEquals(a.getDDY(), 2.2);
    }  // teardown

    /*********************************************
     * name:    ADD A VALUE TO NOTHING
     * input:   aLHS=(0.0, 0.0) aRHS=(4.4, 7.7)
     * output:  aLHS=(4.4, 7.7)
     *********************************************/
    void add_zeroValue()
    {  // setup
        Acceleration a;
        a.setDDX(0.0);
        a.setDDY(0.0);

        Acceleration b;
        b.setDDX(4.4);
        b.setDDY(7.7);

        // exercise
        a.add(b);

        // verify
        assertEquals(a.getDDX(), 4.4);
        assertEquals(a.getDDY(), 7.7);
    }  // teardown

    /*********************************************
     * name:    ADD A VALUE TO ANOTHER VALUE
     * input:   aLHS=(1.1, 2.2) aRHS=(4.4, 7.7)
     * output:  aLHS=(5.5, 9.9)
     *********************************************/
    void add_valueValue()
    {  // setup
        Acceleration a;
        a.setDDX(1.1);
        a.setDDY(2.2);

        Acceleration b;
        b.setDDX(4.4);
        b.setDDY(7.7);

        // exercise
        a.add(b);

        // verify
        assertEquals(a.getDDX(), 5.5);
        assertEquals(a.getDDY(), 9.9);
    }  // teardown

};