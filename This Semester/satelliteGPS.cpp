/***********************************************************************
 * Source File:
 *    GPS
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Sputnik
 ************************************************************************/
#pragma once

#include "satelliteGPS.h"

 /*************************************
  * GPS : CONSTRUCTOR
  *************************************/
GPS::GPS(int i) {
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
	fragmentNum = 0;
	partNum = 3;
	radius = 12.0 * position.getZoom();
	angularVelocity = -0.0069813;
	dead = false;
}

/*************************************
 * GPS : DEFAULT CONSTRUCTOR
 *************************************/
GPS::GPS() {
	fragmentNum = 2;
	partNum = 3;
	position.setMeters(1, 1);
	velocity.setDX(0);
	velocity.setDY(0);
	radius = 12.0 * this->position.getZoom();
	angularVelocity = -0.0069813;
	dead = false;
}

/*************************************
 * GPS : DESTROY
 *************************************/
void GPS::destroy(std::list<Satellite*>& satellites, Satellite* satellite) {
	satellites.push_back(new GPSCenter(satellite));
	satellites.push_back(new GPSLeft(satellite));
	satellites.push_back(new GPSRight(satellite));
}

/*************************************
 * GPSCENTER : CONSTRUCTOR
 *************************************/
GPSCenter::GPSCenter(Satellite* satellite) {
	fragmentNum = 3;
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
	radius = 7 * position.getZoom();
	angularVelocity = -0.0069813;
	dead = false;
}

/*************************************
 * GPSLEFT : CONSTRUCTOR
 *************************************/
GPSLeft::GPSLeft(Satellite* satellite) {
	fragmentNum = 3;
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
	radius = 8 * position.getZoom();
	angularVelocity = -0.0069813;
	dead = false;
}

/*************************************
 * GPSRIGHT : CONSTRUCTOR
 *************************************/
GPSRight::GPSRight(Satellite* satellite) {
	fragmentNum = 3;
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
	radius = 8 * position.getZoom();
	angularVelocity = -0.0069813;
	dead = false;
}