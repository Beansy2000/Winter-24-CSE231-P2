/***********************************************************************
 * Source File:
 *    CREWDRAGON
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Crew Dragon
 ************************************************************************/
#pragma once

#include "satelliteCrewDragon.h"

 /*************************************
  * CREWDRAGON : CONSTRUCTOR
  *************************************/
CrewDragon::CrewDragon() {
	fragmentNum = 0;
	partNum = 3;
	position.setMeters(0.0, 8000000);
	velocity.setDX(-7900.0);
	velocity.setDY(0.0);
	radius = 7 * position.getZoom();
	angularVelocity = -0.01;
	dead = false;
}

/*************************************
 * CREWDRAGON : DESTROY
 *************************************/
void CrewDragon::destroy(std::list<Satellite*>& satellites, Satellite* satellite) {
	satellites.push_back(new CrewDragonCenter(satellite));
	satellites.push_back(new CrewDragonLeft(satellite));
	satellites.push_back(new CrewDragonRight(satellite));
}

/*************************************
 * CREWDRAGONCENTER : CONSTRUCTOR
 *************************************/
CrewDragonCenter::CrewDragonCenter(Satellite* satellite) {
	fragmentNum = 4;
	partNum = 0;
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_int_distribution<> partOffset{ 2, 8 };
	position.setPixelsX(satellite->getPosition().getPixelsX() + 2 * partOffset(gen));
	position.setPixelsY(satellite->getPosition().getPixelsY() + 2 * partOffset(gen));
	std::uniform_int_distribution<> velocityOffset{ 5, 9 };
	velocity.setDX(satellite->getDX() + velocityOffset(gen));
	velocity.setDY(satellite->getDY() + velocityOffset(gen));
	angle.setRadians(satellite->getAngle());
	radius = 6 * position.getZoom();
	angularVelocity = -0.01;
	dead = false;
}
/*************************************
 * CREWDRAGONLEFT : CONSTRUCTOR
 *************************************/
CrewDragonLeft::CrewDragonLeft(Satellite* satellite) {
	fragmentNum = 2;
	partNum = 0;
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_int_distribution<> partOffset{ 2, 8 };
	position.setPixelsX(satellite->getPosition().getPixelsX() + 2 * partOffset(gen));
	position.setPixelsY(satellite->getPosition().getPixelsY() + 2 * partOffset(gen));
	std::uniform_int_distribution<> velocityOffset{ 5, 9 };
	velocity.setDX(satellite->getDX() + velocityOffset(gen));
	velocity.setDY(satellite->getDY() + velocityOffset(gen));
	angle.setRadians(satellite->getAngle());
	radius = 6 * position.getZoom();
	angularVelocity = -0.01;
	dead = false;
}
/*************************************
 * CREWDRAGONRIGHT : CONSTRUCTOR
 *************************************/
CrewDragonRight::CrewDragonRight(Satellite* satellite) {
	fragmentNum = 2;
	partNum = 0;
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_int_distribution<> partOffset{ 2, 8 };
	position.setPixelsX(satellite->getPosition().getPixelsX() + 2 * partOffset(gen));
	position.setPixelsY(satellite->getPosition().getPixelsY() + 2 * partOffset(gen));
	std::uniform_int_distribution<> velocityOffset{ 5, 9 };
	velocity.setDX(satellite->getDX() + velocityOffset(gen));
	velocity.setDY(satellite->getDY() + velocityOffset(gen));
	angle.setRadians(satellite->getAngle());
	radius = 6 * position.getZoom();
	angularVelocity = -0.01;
	dead = false;
}