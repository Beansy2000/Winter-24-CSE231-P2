/***********************************************************************
 * Source File:
 *    SPUTNIK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Sputnik
 ************************************************************************/
#pragma once

#include "satelliteSputnik.h"

 /*************************************
  * SPUTNIK : CONSTRUCTOR
  *************************************/
Sputnik:: Sputnik() {
	fragmentNum = 4;
	partNum = 0;
	position.setMeters(-36515095.13, 21082000.0);
	velocity.setDX(2050.0);
	velocity.setDY(2684.68);
	radius = 4.0 * position.getZoom();
	angularVelocity = 0.03;
	dead = false;
}

/*************************************
 * SPUTNIK : DESTROY
 *************************************/
void Sputnik::destroy(std::list<Satellite*>& satellites, Satellite* satellite) {
	throw std::runtime_error("Sputnik makes no parts");
}
