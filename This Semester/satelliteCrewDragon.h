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
	CrewDragon() : Satellite() {
		fragmentNum = 2;
		partNum = 3;
		position.setMeters(0.0, 8000000);
		velocity.setDX(-7900.0);
		velocity.setDY(0.0);
		radius = 7 * position.getZoom();
		angularVelocity = -0.01;
		dead = false;
	}

	void draw(ogstream& pgout) {
		if (!isDead()) {
			pgout.drawCrewDragon(this->position, angle.getRadians());
		}
	}
};
