/***********************************************************************
 * Source File:
 *    FRAGMENT
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for fragments
 ************************************************************************/
#pragma once

#include "satelliteFragment.h"

 /*************************************
  * SATELLITE : MOVE
  *************************************/
void Fragment::move(float time) {
	Satellite::move(time);
	// Update expiration timer
	expirationTimer--;
}

/*************************************
 * SATELLITE : CONSTRUCTOR
 *************************************/
Fragment::Fragment(Satellite* satPrimary, Satellite* satSecondary) {
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_int_distribution<> fragOffset{ 2, 8 };
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

/*************************************
 * SATELLITE : CONSTRUCTOR
 *************************************/
Fragment::Fragment(Satellite* satPrimary, Projectile* projectile) {
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_int_distribution<> fragOffset{ 2, 8 };
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