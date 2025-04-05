/***********************************************************************
 * Source File:
 *    Hubble
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Hubble
 *********************************************************************/
#pragma once

#include "satelliteHubble.h"
#include <list>

/********************
* Huddle Constructor
********************/
Hubble:: Hubble() {
	fragmentNum = 0;
	partNum = 4;
	position.setMeters(0.0, -42164000.0);
	velocity.setDX(3100);
	velocity.setDY(0.0);
	radius = 10.0 * position.getZoom();
	angularVelocity = 0;
	dead = false;
}

Hubble:: Hubble(double dx, double dy) {
		int fragmentNum = 0;
		int partNum = 4;
		position.setMeters(dx, -dy);
		velocity.setDX(3100);
		velocity.setDY(0.0);
		radius = 10.0 * position.getZoom();
		angularVelocity = 0;
		dead = false;
}

/******************
* HUBBLE: DESTROY
******************/
void Hubble::destroy(std::list<Satellite*>& satellites, Satellite* satellite) {
	satellites.push_back(new HubbleRight(satellite));
	satellites.push_back(new HubbleLeft(satellite));
	satellites.push_back(new HubbleComputer(satellite));
	satellites.push_back(new HubbleTelescope(satellite));
}

/*************************************
 * HUBBLERIGHT : CONSTRUCTOR
 *************************************/
HubbleRight::HubbleRight(Satellite* satellite) {
	fragmentNum = 3;
	partNum = 3;
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
 * HUBBLE LEFT : CONSTRUCTOR
 *************************************/
HubbleLeft::HubbleLeft(Satellite* satellite) {
	fragmentNum = 2;
	partNum = 2;
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
 * HUBBLE COMPUTER : CONSTRUCTOR
 *************************************/
HubbleComputer::HubbleComputer(Satellite* satellite) {
	fragmentNum = 1;
	partNum = 1;
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

HubbleTelescope::HubbleTelescope(Satellite* satellite) {
	fragmentNum = 4;
	partNum = 4;
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
