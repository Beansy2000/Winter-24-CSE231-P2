/***********************************************************************
 * Source File:
 *    STARLINK
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Starlink
 ************************************************************************/
#pragma once

#include "satelliteStarlink.h"
#include <list>

 /*************************************
  * STARLINK : CONSTRUCTOR
  *************************************/
Starlink::Starlink() {
	fragmentNum = 2;
	partNum = 2;
	position.setMeters(0.0, -13020000.0);
	velocity.setDX(5800);
	velocity.setDY(0);
	radius = 6 * position.getZoom();
	angularVelocity = -0.008;
	dead = false;
}

 /*************************************
  * STARLINK : DESTROY
  *************************************/
void Starlink::destroy(std::list<Satellite*>& satellites, Satellite* satellite) {
 	satellites.push_back(new StarlinkBody(satellite));
    satellites.push_back(new StarlinkArray(satellite));
}

/*************************************
 * STARLINKBODY : CONSTRUCTOR
 *************************************/
StarlinkBody::StarlinkBody(Satellite* satellite) {
	fragmentNum = 3;
	partNum = 0;
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_int_distribution<> partOffset{ 1, 8 };
	position.setPixelsX(satellite->getPosition().getPixelsX() + 4 + partOffset(gen));
	position.setPixelsY(satellite->getPosition().getPixelsY() + 4 + partOffset(gen));
	std::uniform_int_distribution<> velocityOffset{ 5, 9 };
	velocity.setDX(satellite->getDX() + velocityOffset(gen));
	velocity.setDY(satellite->getDY() + velocityOffset(gen));
	angle.setRadians(satellite->getAngle());
	radius = 2 * position.getZoom();
	dead = false;
}

/*************************************
 * STARLINKARRAY : CONSTRUCTOR
 *************************************/
StarlinkArray::StarlinkArray(Satellite* satellite) {
	fragmentNum = 3;
	partNum = 0;
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_int_distribution<> fragOffset{ 1, 8 };
	position.setPixelsX(satellite->getPosition().getPixelsX() + 4 + fragOffset(gen));
	position.setPixelsY(satellite->getPosition().getPixelsY() + 4 + fragOffset(gen));
	std::uniform_int_distribution<> velocityOffset{ 5, 9 };
	velocity.setDX(satellite->getDX() + velocityOffset(gen));
	velocity.setDY(satellite->getDY() + velocityOffset(gen));
	angle.setRadians(satellite->getAngle());
	radius = 2 * position.getZoom();
	dead = false;
}