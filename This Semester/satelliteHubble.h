/***********************************************************************
 * Header File:
 *    HUBBLE
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
  * HUBBLE : SATELLITE
  ***************************************************/
class Hubble : public Satellite {
public:
	Hubble() : Satellite() {
		position.setMeters(0.0, -42164000.0);
		velocity.setDX(3100);
		velocity.setDY(0.0);
		radius = 10.0 * position.getZoom();
		angularVelocity = 0;
		dead = false;
	}
	Hubble(double dx, double dy) : Satellite() {
		position.setMeters(dx, -dy);
		velocity.setDX(3100);
		velocity.setDY(0.0);
		radius = 10.0 * position.getZoom();
		angularVelocity = 0;
		dead = false;
	}
	void draw(ogstream& pgout) {
		if (!isDead()) {
			pgout.drawHubble(position, angle.getRadians());
		}
	}
	void destroy(Satellite& satellite) {

	}
};
