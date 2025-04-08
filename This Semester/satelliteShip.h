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
	Ship();
	bool isThrusting() { return drawThrust; }
	void addPixelsY(double dy) { position.addPixelsY(dy); }
	void addPixelsX(double dx) { position.addPixelsX(dx); }
	void rotateLeft() { angle.setRadians(angle.getRadians() - 0.04); }
	void rotateRight() { angle.setRadians(angle.getRadians() + 0.04); }
	void drive();
	void draw(ogstream& pgout) { pgout.drawShip(position, angle.getRadians(), drawThrust); }
	void move(float time) override {}
	//void input(const Interface* pUI);
};
