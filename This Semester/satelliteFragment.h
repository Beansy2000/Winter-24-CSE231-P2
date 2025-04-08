/***********************************************************************
 * Header File:
 *    FRAGMENT
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Fragment Satellite class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "projectile.h"
#include <iostream>
#include <random>
#define FRAGMENTEXPIRATIONTIME 2 * 60

 /***************************************************
  * FRAGMENT : SATELLITE
  ***************************************************/
class Fragment : public Satellite {
private:
	int expirationTimer = (FRAGMENTEXPIRATIONTIME);
public:
	Fragment(Satellite* satPrimary, Satellite* satSecondary);
	Fragment(Satellite* satPrimary, Projectile* projectile);
	bool canDie() const { return expirationTimer < (FRAGMENTEXPIRATIONTIME - 5); }
	bool isExpired() const { return expirationTimer <= 0; }
	void draw(ogstream& pgout) { pgout.drawFragment(this->position, angle.getRadians()); }
	void move(float time);
};
