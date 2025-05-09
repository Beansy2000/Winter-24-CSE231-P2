/***********************************************************************
 * Source File:
 *    ANGLE
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
 * ANGLE : NORMALIZE
 ************************************/
double Angle::normalize(double radians) const
{
	// Adjust the angle for values less than 0 or greater than or equal to 2*PI
	if (radians >= (M_PI * 2.0))
	{
		// Subtract 2*PI until the angle is less than 2*PI
		double multiples = floor(radians / (M_PI * 2.0));
		return radians - ((M_PI * 2.0) * multiples);
	}
	else if (radians < 0.0)
	{
		// Add 2*PI until the angle is greater than 0
		double multiples = ceil(-radians / (M_PI * 2.0));
		return (M_PI * 2.0) * multiples + radians;
	}

	return radians;
}

