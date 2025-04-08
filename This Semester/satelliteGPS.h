/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The GPS Satellite class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h"


 /***************************************************
  * GPS : SATELLITE
  ***************************************************/
class GPS : public Satellite {
public:
	GPS(int i);
	GPS();
	void draw(ogstream& pgout) { pgout.drawGPS(this->position, angle.getRadians()); }
	void destroy(std::list<Satellite*>& satellites, Satellite* satellite);
};

/***************************************************
 * GPSCENTER : SATELLITE
 ***************************************************/
class GPSCenter : public Satellite {
public:
	GPSCenter(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawGPSCenter(this->position, angle.getRadians()); }
};

/***************************************************
 * GPSCENTER : SATELLITE
 ***************************************************/
class GPSLeft : public Satellite {
public:
	GPSLeft(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawGPSLeft(this->position, angle.getRadians()); }
};

/***************************************************
 * GPSCENTER : SATELLITE
 ***************************************************/
class GPSRight : public Satellite {
public:
	GPSRight(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawGPSRight(this->position, angle.getRadians()); }
};

