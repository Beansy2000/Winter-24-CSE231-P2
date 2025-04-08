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
#include "satelliteShip.h"
#include "satelliteFragment.h"

class Collision {
public:
	bool IsColliding(Satellite& satelliteA, Satellite& satelliteB);
	bool IsColliding(Satellite& satellite, Projectile& projectile);
	bool IsColliding(Satellite& satellite, Earth& earth);
	bool IsColliding(Projectile& projectile, Earth& earth);

	void SatellitetoSatelliteCollision(std::list<Satellite*>& satellites, std::list<Fragment*>& fragments);
	void ProjectiletoEarthCollision(std::list<Projectile*>& projectiles, Earth& earth);
	void SatellitetoEarthCollision(std::list<Satellite*>& satellites, Earth& earth);
	void SatellitetoProjectileCollision(std::list<Satellite*>& satellites, std::list<Projectile*>& projectiles, std::list<Fragment*>& fragments, Satellite& ship);
};