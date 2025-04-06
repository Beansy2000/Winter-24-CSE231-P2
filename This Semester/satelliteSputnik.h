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


// /***************************************************
//  * SPUTNIK : SATELLITE
//  ***************************************************/
//class Sputnik : public Satellite {
//public:
//	Sputnik() : Satellite() {
//		fragmentNum = 4;
//		partNum = 0;
//		position.setMeters(-36515095.13, 21082000.0);
//		velocity.setDX(2050.0);
//		velocity.setDY(2684.68);
//		radius = 4.0 * position.getZoom();
//		angularVelocity = 0.03;
//		dead = false;
//	}
//	void draw(ogstream& pgout) {
//		if (!isDead()) {
//			pgout.drawSputnik(position, angle.getRadians());
//		}
//	}
//};

/***************************************************
  * SPUTNIK : SATELLITE
***************************************************/

class Sputnik : public Satellite {
public:
	Sputnik();
	void draw(ogstream& pgout) { pgout.drawSputnik(position, angle.getRadians()); }
	void destroy(std::list<Satellite*>& satellites, Satellite* satellite);
};