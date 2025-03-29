/***********************************************************************
 * Source File:
 *    SATELLITE
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for satellites
 ************************************************************************/

#include "projectile.h" // Now the full definition of Projectile is available
#include "satellite.h"
#include <cstdlib>
#include <cmath>
#include <vector>

/*************************************
 * SATELLITE : MOVE
 *************************************/
void Satellite::move(float time) {
	// Gravitational Acceleration
	double acceleration = physics.getAccelFromGravity(position.getMetersX(), position.getMetersY());

	// Direction of Gravity in Radians
	double gravDirection = physics.getGravDirectionRadians(position.getMetersX(), position.getMetersY());

	// Change velocity with Gravity
	double ddx = physics.getDDX(acceleration, gravDirection);
	double ddy = physics.getDDY(acceleration, gravDirection);

	// Update velocity with Acceleration
	velocity.setDX(velocity.getDX() + ddx * time);
	velocity.setDY(velocity.getDY() + ddy * time);

	// Update position
	position.setMetersX(position.getMetersX() + velocity.getDX() * time);
	position.setMetersY(position.getMetersY() + velocity.getDY() * time);

	// Rotate
	angle.add(angularVelocity);
}


#include "projectile.h" // Now the full definition of Projectile is available

void Satellite::destroy(std::vector<Satellite*>& satellites) {
   this->kill(); // Mark the original satellite as destroyed

   int numParts = rand() % 4 + 3; // Generate between 3 and 6 parts

   for (int i = 0; i < numParts; i++) {
      // Create a new part (assuming Part is a subclass of Satellite or has similar properties)
      Part* part = new Part(position, this->radius / 3, true);  // Use Part's constructor

      // Set part position to match destroyed satellite
      part->setPosition(this->position);

      // Generate random velocity direction
      double angle = (rand() % 360) * (M_PI / 180.0); // Convert degrees to radians
      double speed = (rand() % 50 + 50) / 100.0; // Speed between 0.5 and 1.0

      part->setDX(this->getDX() + speed * cos(angle));
      part->setDY(this->getDY() + speed * sin(angle));

      // Set part properties (radius and 'dead' flag)
      part->setRadius(this->radius / 3);  // Smaller radius for fragments
      part->setDead(false); // The part is active

      // Add part to satellite list (or another appropriate collection)
      satellites.push_back(part);  // Add to the vector or list of satellites
   }
}

