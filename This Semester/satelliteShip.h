/***********************************************************************
 * Header File:
 *    SHIP
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
  * SHIP : SATELLITE
  ***************************************************/
class Ship : public Satellite {
public:
	bool drawThrust = false;
	Ship() : Satellite() {
		position.setPixelsX(-450);
		position.setPixelsY(450);
		velocity.setDX(0);
		velocity.setDY(0);
		radius = 10 * position.getZoom();
		angularVelocity = 0;
		dead = false;
	}
	bool isThrusting() { return drawThrust; }
	void addPixelsY(double dy) { position.addPixelsY(dy); }
	void addPixelsX(double dx) { position.addPixelsX(dx); }
	void rotateLeft() { angle.setRadians(angle.getRadians() - 0.02); }
	void rotateRight() { angle.setRadians(angle.getRadians() + 0.02); }
	void drive() { 
		position.addPixelsX(sin(angle.getRadians()));
		position.addPixelsY(cos(angle.getRadians()));
		drawThrust = true;
	}
	void draw(ogstream& pgout) {
		if (!isDead()) {
			pgout.drawShip(position, angle.getRadians(), drawThrust);
		}
	}
	void move(float time) override {}
	//void input(const Interface* pUI);
};
