/***********************************************************************
 * Header File:
 *    COLLISION
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    The Collision class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "earth.h"
#include "projectile.h"

class Collision {
public:
	bool IsColliding(Satellite& satelliteA, Satellite& satelliteB);
	bool IsColliding(Satellite& satellite, Projectile& projectile);
	bool IsColliding(Satellite& satellite, Earth& earth);
	bool IsColliding(Projectile& projectile, Earth& earth);
};