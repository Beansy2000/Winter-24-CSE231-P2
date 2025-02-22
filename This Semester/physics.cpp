#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159
#include "physics.h"

const double EARTH_RADIUS = 6378000.0;


	double Physics::convertToDegrees(double radians)
	{
		return radians / (M_PI * 2.0) * 360.0;
	}

	double Physics::convertToRadians(double degrees)
	{
		return degrees / 360.0 * (M_PI * 2.0);
	}

	double Physics::getMetersAboveEarth(double x, double y) {
		/*
		* Assuming the position of the earth is x:0 and y:0 in meters, calculate the
		* distance of the satellite from the earth.
		*
		* Returns meters
		*/

		return sqrt(x * x + y * y) - EARTH_RADIUS;
	}

	double Physics::getAccelFromGravity(double x, double y) {
		return 9.80665 * pow((6378000 / (6378000 + getMetersAboveEarth(x, y))), 2);
	}

	double Physics::getGravDirectionRadians(double x, double y) {
		if (y > 0 && x < 0) // Top Left Quadrant
			return abs(atan2(-y, -x)) + 1.57079632;
		else if (y < 0 && x < 0) // Bottom Left Quadrant
			return 1.57079632 - atan2(-y, -x);
		else if (y < 0 && x > 0) // Bottom Right Quadrant
			return -atan2(-y, -x) + 1.57079632;
		else if (y > 0 && x > 0) // Top Right Quadrant
			return abs(atan2(-y, -x)) + 1.57079632;
		return 3.14159;
	}

	double Physics::getDDX(double acceleration, double radians) {
		return acceleration * cos(radians);
	}

	double Physics::getDDY(double acceleration, double radians) {
		return acceleration * sin(radians);
	}
