/***********************************************************************
 * Header File:
 *    CREWDRAGON
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The CrewDragon Satellite class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h"


 /***************************************************
  * CREWDRAGON : SATELLITE
  ***************************************************/
class CrewDragon : public Satellite {
public:
	CrewDragon();
	void draw(ogstream& pgout) { pgout.drawCrewDragon(this->position, angle.getRadians()); }
	void destroy(std::list<Satellite*>& satellites, Satellite* satellite);
};

/***************************************************
 * CREWDRAGONCENTER : SATELLITE
 ***************************************************/
class CrewDragonCenter : public Satellite {
public:
	CrewDragonCenter(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawCrewDragonCenter(this->position, angle.getRadians()); }
};

/***************************************************
 * CREWDRAGONLEFT : SATELLITE
 ***************************************************/
class CrewDragonLeft : public Satellite {
public:
	CrewDragonLeft(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawCrewDragonLeft(this->position, angle.getRadians()); }
};

/***************************************************
 * CREWDRAGONRIGHT : SATELLITE
 ***************************************************/
class CrewDragonRight : public Satellite {
public:
	CrewDragonRight(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawCrewDragonRight(this->position, angle.getRadians()); }
};
