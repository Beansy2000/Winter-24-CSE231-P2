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


 /***************************************************
  * STARLINK : SATELLITE
  ***************************************************/
class Starlink : public Satellite {
public:
	Starlink() : Satellite() {
		position.setMeters(0.0, -13020000.0);
		velocity.setDX(5800);
		velocity.setDY(0);
		radius = 6 * position.getZoom();
		angularVelocity = -0.008;
		dead = false;
	}
	void draw(ogstream& pgout) {
		if (!isDead()) {
			pgout.drawStarlink(position, angle.getRadians());
		}
	}
	void destroy(Satellite& satellite) {

	}
};
