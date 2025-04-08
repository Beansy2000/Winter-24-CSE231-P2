/***********************************************************************
 * Header File:
 *    SPUTNIK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Sputnik Satellite class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h"

/***************************************************
  * SPUTNIK : SATELLITE
***************************************************/

class Sputnik : public Satellite {
public:
	Sputnik();
	void draw(ogstream& pgout) { pgout.drawSputnik(position, angle.getRadians()); }
	void destroy(std::list<Satellite*>& satellites, Satellite* satellite);
};