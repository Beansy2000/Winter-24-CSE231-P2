/***********************************************************************
 * Source File:
 *    SHIP
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Ship
 ************************************************************************/
#pragma once

#include "satelliteShip.h"

 /***************************************************
  * SHIP : CONSTRUCTOR
  ***************************************************/
Ship::Ship() {
	position.setPixelsX(-450);
	position.setPixelsY(450);
	velocity.setDX(0);
	velocity.setDY(0);
	radius = 10 * position.getZoom();
	angularVelocity = 0;
	dead = false;
}

/***************************************************
 * SHIP : DRIVE
 ***************************************************/
void Ship::drive() {
	position.addPixelsX(sin(angle.getRadians())*2);
	position.addPixelsY(cos(angle.getRadians())*2);
	drawThrust = true;
}