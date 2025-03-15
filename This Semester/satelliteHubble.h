/***********************************************************************
 * Header File:
 *    Hubble
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
class Hubble : public Satellite {
public:
	Hubble() : Satellite() {
		position.setMeters(-36515095.13, 21082000.0);
		velocity.setDX(2050);
		velocity.setDY(2684);
		radius = 4.0 * position.getZoom();
		angularVelocity = .001;
		dead = false;
	}
	void draw(ogstream& pgout) {
		pgout.drawHubble(position, angle.getRadians());
	}
	void destroy(Satellite& satellite) {

	}
	void move(float time) override;
};
