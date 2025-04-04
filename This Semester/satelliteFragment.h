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
	Fragment(Satellite* satPrimary, Satellite* satSecondary) : Satellite() {
		std::random_device seed;
		std::mt19937 gen{ seed() };
		std::uniform_int_distribution<> fragOffset{ 1, 8 };
		position.setPixelsX(satPrimary->getPosition().getPixelsX() + 2 * fragOffset(gen));
		position.setPixelsY(satPrimary->getPosition().getPixelsY() + 2 * fragOffset(gen));
		std::uniform_int_distribution<> velocityOffset{ 5, 9 };
		velocity.setDX(satPrimary->getDX() + velocityOffset(gen));
		velocity.setDY(satPrimary->getDY() + velocityOffset(gen));
		std::uniform_int_distribution<> angleOffset;
		if (satPrimary->getDegrees() > satSecondary->getDegrees()) {
			std::uniform_int_distribution<> angleOffset{ (int)satSecondary->getDegrees(), (int)satPrimary->getDegrees() };
		}
		else {
			std::uniform_int_distribution<> angleOffset{ (int)satPrimary->getDegrees(), (int)satSecondary->getDegrees() };
		}
		angle.setDegrees(angleOffset(gen));
		radius = 2 * position.getZoom();
		angularVelocity = -0.01;
		dead = false;
	}
	Fragment(Satellite* satPrimary, Projectile* projectile) : Satellite() {
		std::random_device seed;
		std::mt19937 gen{ seed() };
		std::uniform_int_distribution<> fragOffset{ 1, 8 };
		position.setPixelsX(satPrimary->getPosition().getPixelsX() + 2 * fragOffset(gen));
		position.setPixelsY(satPrimary->getPosition().getPixelsY() + 2 * fragOffset(gen));
		std::uniform_int_distribution<> velocityOffset{ 5, 9 };
		velocity.setDX(satPrimary->getDX() + velocityOffset(gen));
		velocity.setDY(satPrimary->getDY() + velocityOffset(gen));
		std::uniform_int_distribution<> angleOffset;
		if (satPrimary->getDegrees() > projectile->getDegrees()) {
			std::uniform_int_distribution<> angleOffset{ (int)projectile->getDegrees(), (int)satPrimary->getDegrees() };
		}
		else {
			std::uniform_int_distribution<> angleOffset{ (int)satPrimary->getDegrees(), (int)projectile->getDegrees() };
		}
		angle.setDegrees(angleOffset(gen));
		radius = 2 * position.getZoom();
		angularVelocity = -0.01;
		dead = false;
	}
	bool canDie() const { return expirationTimer < (FRAGMENTEXPIRATIONTIME - 5); }
	bool isExpired() const { return expirationTimer <= 0; }
	void draw(ogstream& pgout) {
		if (!isDead()) {
			pgout.drawFragment(this->position, angle.getRadians());
		}
	}
	void move(float time);
};
