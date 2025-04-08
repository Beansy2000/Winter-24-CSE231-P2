/***********************************************************************
 * Source File:
 *    COLLISION
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for collision
 ************************************************************************/
#pragma once

#include "collision.h"

/*************************************
 * COLLISION : CHECKFORCOLLISION SATELLITE TO SATELLITE
 *************************************/
bool Collision::IsColliding(Satellite& satelliteA, Satellite& satelliteB) {
	float distX = satelliteA.getPosition().getMetersX() - satelliteB.getPosition().getMetersX();
	float distY = satelliteA.getPosition().getMetersY() - satelliteB.getPosition().getMetersY();

	float distance = sqrt((distX * distX) + (distY * distY));
	if (distance <= satelliteA.getRadius() + satelliteB.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************
 * COLLISION : CHECKFORCOLLISION PROJECTILE TO SATELLITE
 *************************************/
bool Collision::IsColliding(Satellite& satellite, Projectile& projectile) {
	float distX = satellite.getPosition().getMetersX() - projectile.getPosition().getMetersX();
	float distY = satellite.getPosition().getMetersY() - projectile.getPosition().getMetersY();

	float distance = sqrt((distX * distX) + (distY * distY));
	if (distance <= satellite.getRadius() + projectile.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************
 * COLLISION : CHECKFORCOLLISION SATELLITE TO EARTH
 *************************************/
bool Collision::IsColliding(Satellite& satellite, Earth& earth) {
	float distX = satellite.getPosition().getMetersX() - earth.getPosition().getMetersX();
	float distY = satellite.getPosition().getMetersY() - earth.getPosition().getMetersY();

	float distance = sqrt((distX * distX) + (distY * distY));
	if (distance <= satellite.getRadius() + earth.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************
 * COLLISION : CHECKFORCOLLISION PROJECTILE TO EARTH
 *************************************/
bool Collision::IsColliding(Projectile& projectile, Earth& earth) {
	float distX = earth.getPosition().getMetersX() - projectile.getPosition().getMetersX();
	float distY = earth.getPosition().getMetersY() - projectile.getPosition().getMetersY();

	float distance = sqrt((distX * distX) + (distY * distY));
	if (distance <= earth.getRadius() + projectile.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************
 * COLLISION : COLLISION LOGIC PROJECTILE TO EARTH
 *************************************/
void Collision::ProjectiletoEarthCollision(std::list<Projectile*>& projectiles, Earth& earth) {
earthtoprojectilecollision:
	for (auto projectile : projectiles) {
		if (IsColliding(*projectile, earth)) {
			projectiles.remove(projectile);
			projectile = nullptr;
			goto earthtoprojectilecollision;
		}
	}
}


/*************************************
 * COLLISION : COLLISION LOGIC SATELLITE TO SATELLITE
 *************************************/
void Collision::SatellitetoSatelliteCollision(std::list<Satellite*>& satellites, std::list<Fragment*>& fragments) {
sattosatcollision:
	for (auto satellite : satellites) {
		for (auto satelliteB : satellites) {
			if (satellite != satelliteB) {
				if (IsColliding(*satellite, *satelliteB)) {
					satellites.remove(satellite);
					satellites.remove(satelliteB);
					for (int i = 0; i <= satellite->getNumFrags(); i++) {
						fragments.push_back(new Fragment(satellite, satelliteB));
					}
					for (int i = 0; i <= satelliteB->getNumFrags(); i++) {
						fragments.push_back(new Fragment(satellite, satelliteB));
					}
					if (satellite->getNumParts() > 0) {
						satellite->destroy(satellites, satellite);
					}
					if (satelliteB->getNumParts() > 0) {
						satelliteB->destroy(satellites, satelliteB);
					}
					satellite = nullptr;
					satelliteB = nullptr;
					goto sattosatcollision;
				}
			}
		}
	}
}

/*************************************
 * COLLISION : COLLISION LOGIC SATELLITE TO EARTH
 *************************************/
void Collision::SatellitetoEarthCollision(std::list<Satellite*>& satellites, Earth& earth) {
sattoearthcollision:
	for (auto satellite : satellites) {
		if (IsColliding(*satellite, earth)) {
			satellites.remove(satellite);
			satellite = nullptr;
			goto sattoearthcollision;
		}
	}
}

/*************************************
 * COLLISION : COLLISION LOGIC SATELLITE TO PROJECTILE
 *************************************/
void Collision::SatellitetoProjectileCollision(std::list<Satellite*>& satellites, std::list<Projectile*>& projectiles, std::list<Fragment*>& fragments, Satellite& ship) {
sattoprojectilecollision:
	for (auto projectile : projectiles) {
		for (auto satellite : satellites) {
			if (IsColliding(*satellite, *projectile) and satellite != &ship) {
				satellites.remove(satellite);
				for (int i = 0; i <= satellite->getNumFrags(); i++) {
					fragments.push_back(new Fragment(satellite, projectile));
				}
				if (satellite->getNumParts() > 0) {
					satellite->destroy(satellites, satellite);
				}
				projectiles.remove(projectile);
				satellite = nullptr;
				projectile = nullptr;
				goto sattoprojectilecollision;
			}
		}
	}
}