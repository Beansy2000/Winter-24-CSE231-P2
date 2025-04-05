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
#include "random"

 /***************************************************
  * HUBBLE : SATELLITE
  ***************************************************/
//class Hubble : public Satellite {
//public:
//	Hubble() : Satellite() {
//		fragmentNum = 0;
//		partNum = 4;
//		position.setMeters(0.0, -42164000.0);
//		velocity.setDX(3100);
//		velocity.setDY(0.0);
//		radius = 10.0 * position.getZoom();
//		angularVelocity = 0;
//		dead = false;
//	}
//	Hubble(double dx, double dy) : Satellite() {
//		int fragmentNum = 0;
//		int partNum = 4;
//		position.setMeters(dx, -dy);
//		velocity.setDX(3100);
//		velocity.setDY(0.0);
//		radius = 10.0 * position.getZoom();
//		angularVelocity = 0;
//		dead = false;
//	}
//	void draw(ogstream& pgout) {
//		if (!isDead()) {
//			pgout.drawHubble(position, angle.getRadians());
//		}
//	}
//};





 /***************************************************
  * Hubble : SATELLITE
  ***************************************************/
class Hubble : public Satellite {
public:
	Hubble();
	Hubble(double dx, double dy);
	void draw(ogstream& pgout) { pgout.drawHubble(position, angle.getRadians()); }
	void destroy(std::list<Satellite*>& satellites, Satellite* satellite);
};

/***************************************************
 * HubbleBODY : SATELLITE
 ***************************************************/
class HubbleRight : public Satellite {
public:
	HubbleRight(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawHubbleRight(position, angle.getRadians()); }
};

class HubbleLeft : public Satellite {
public:
	HubbleLeft(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawHubbleLeft(position, angle.getRadians()); }
};

class HubbleComputer : public Satellite {
public:
	HubbleComputer(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawHubbleComputer(position, angle.getRadians()); }
};

class HubbleTelescope : public Satellite {
public:
	HubbleTelescope(Satellite* satellite);
	void draw(ogstream& pgout) { pgout.drawHubbleTelescope(position, angle.getRadians()); }
};