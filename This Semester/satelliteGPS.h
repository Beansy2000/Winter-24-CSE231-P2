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
	GPS(int i) : Satellite() {
		switch (i) {
		case 1:
			position.setMeters(0.0, 26560000.0);
			velocity.setDX(-3880.0);
			velocity.setDY(0.0);
			angle.setDegrees((double)0 * 60 + 90);
			break;
		case 2:
			position.setMeters(23001634.72, 13280000.0);
			velocity.setDX(-1940.0);
			velocity.setDY(3360.18);
			angle.setDegrees((double)1 * 60 + 90);
			break;
		case 3:
			position.setMeters(23001634.72, -13280000.0);
			velocity.setDX(1940.0);
			velocity.setDY(3360.18);
			angle.setDegrees((double)2 * 60 + 90);
			break;
		case 4:
			position.setMeters(0.0, -26560000.0);
			velocity.setDX(3880.0);
			velocity.setDY(0.0);
			angle.setDegrees((double)3 * 60 + 90);
			break;
		case 5:
			position.setMeters(-23001634.72, -13280000.0);
			velocity.setDX(1940.0);
			velocity.setDY(-3360.18);
			angle.setDegrees((double)4 * 60 + 90);
			break;
		case 6:
			position.setMeters(-23001634.72, 13280000.0);
			velocity.setDX(-1940.0);
			velocity.setDY(-3360.18);
			angle.setDegrees((double)5 * 60 + 90);
			break;
		}
		radius = 12.0 * position.getZoom();
		angularVelocity = -0.0069813;
		dead = false;
	}
	GPS() : Satellite() {
		position.setMeters(1, 1);
		velocity.setDX(0);
		velocity.setDY(0);
		radius = 12.0 * this->position.getZoom();
		angularVelocity = -0.0069813;
		dead = false;
	}
	void draw(ogstream& pgout) {
		if (!isDead()) {
			pgout.drawGPS(this->position, angle.getRadians());
		}
	}
	void destroy(Satellite& satellite) {

	}
};
