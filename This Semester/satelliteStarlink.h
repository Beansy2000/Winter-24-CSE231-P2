/***********************************************************************
 * Header File:
 *    STARLINK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Hubble Satellite class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <random>


 /***************************************************
  * STARLINK : SATELLITE
  ***************************************************/
class Starlink : public Satellite {
public:
	Starlink();
	void draw(ogstream& pgout) { pgout.drawStarlink(position, angle.getRadians()); }
	void destroy(std::list<Satellite*>& satellites, Satellite* satellite);
};

/***************************************************
 * STARLINKBODY : SATELLITE
 ***************************************************/
class StarlinkBody : public Satellite {
public:
	StarlinkBody(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawStarlinkBody(position, angle.getRadians()); }
};

/***************************************************
 * STARLINKARRAY : SATELLITE
 ***************************************************/
class StarlinkArray : public Satellite {
public:
	StarlinkArray(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawStarlinkArray(position, angle.getRadians()); }
};