/***********************************************************************
 * Header File:
 *    PHYSICS
 * Summary:
 *    Everything we need to know about a physics
 ************************************************************************/
#pragma once


#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class Physics {
public:
	double getAccelFromGravity(double x, double y);
	double getMetersAboveEarth(double x, double y);
	double getGravDirectionRadians(double x, double y);
	double getDDX(double acceleration, double radians);
	double getDDY(double acceleration, double radians);

private:
	double convertToDegrees(double radians);
	double convertToRadians(double degrees);

};