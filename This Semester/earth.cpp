/***********************************************************************
 * Source File:
 *    EARTH
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Earth
 ************************************************************************/
#pragma once

#include "earth.h"

 /*************************************
  * EARTH : CONSTRUCTOR
  *************************************/
Earth::Earth() {
	position.setMeters(0.0, 0.0);
	velocity.setDXY(0.0, 0.0);
	radius = 53 * position.getZoom();
	angularVelocity = -(2 * M_PI / 30) * (24 * 60 / 86400);
	angle.setRadians(0.0040469023027);
}