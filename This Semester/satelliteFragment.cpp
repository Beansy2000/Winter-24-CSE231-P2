/***********************************************************************
 * Source File:
 *    FRAGMENT
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for fragments
 ************************************************************************/
#pragma once

#include "satelliteFragment.h"

 /*************************************
  * SATELLITE : MOVE
  *************************************/
void Fragment::move(float time) {
	Satellite::move(time);
	// Update expiration timer
	expirationTimer--;
}