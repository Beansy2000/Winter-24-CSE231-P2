/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
* Normalize
* Recieves some amount of radians as a double.
* Truncates the radian value and expresses it in its simplest form. (0 < x < 2pi)
* Returns the normalized radians.
************************************/
double Angle::normalize(double rad) const
{
   rad = fmod(rad, M_PI * 2); // Sets rad as the remainder of radians / 2pi, which can be positive or negative.
   if (rad < 0)
      rad = rad + M_PI * 2; // Makes negative radians positive while preserving their position on the unit circle.
   return rad;
}
/************************************
* Degrees to Radians
* Recieves some amount of degrees as a double.
* Multiplies it by pi / 180 to get radians and normalizes it.
* Returns the normalized radians.
************************************/
double Angle::convertToRadians(double degrees) const
{
    double rad;
    rad = degrees * (M_PI / 180);
    rad = normalize(rad);
    return rad;
}

/************************************
* Radians to Degrees
* Recieves some amount of radians as a double.
* Normalizes the radians and multiplies them by 180 / pi to get degrees.
* Returns the normalized degrees.
************************************/
double Angle::convertToDegrees(double rad) const
{
    double degrees;
    degrees = normalize(rad);
    return degrees * (180 / M_PI);
}

/************************************
* Reverse
* Adjusts the angle by reversing its direction.
* Subtracts pi radians (180 degrees) from the current angle
* and normalizes the result to ensure the angle is in the range (0, 2pi).
************************************/
void Angle::reverse()
{
    this->radians = normalize(radians - M_PI);
}

/************************************
* Add
* Adds a given delta (in radians) to the current angle.
* After adding the delta, the result is normalized.
* Returns a reference to the updated Angle object.
************************************/
Angle& Angle::add(double delta)
{
    radians += delta;
    radians = normalize(radians);
    return *this;
}