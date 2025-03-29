#pragma once
#include "satellite.h"  // Include the base class
#include "position.h"   // To define the position of the part
#include <vector>

class Part : public Satellite {
protected:
   Position position;  // Position of the part in space
   double radius;      // Size of the part (we assume spherical parts for simplicity)
   bool isFragment;    // Flag to determine if the part is a fragment

public:
   // Constructor to initialize a part (assuming parts are created from a destroyed satellite)
   Part(SatelliteType type, Position position, double radius, bool isFragment = false)
      : Satellite(type, radius), position(position), radius(radius), isFragment(isFragment) {}

   // Getters and setters for position and radius
   Position getPosition() const { return position; }
   double getRadius() const { return radius; }
   bool getIsFragment() const { return isFragment; }

   // Method to set a new position for the part (if needed)
   void setPosition(Position newPosition) { position = newPosition; }

   // Method to break the part into smaller fragments (if needed)
   void breakIntoFragments() {
      if (!isFragment) {
         isFragment = true;
         radius /= 2;  // Example: break into smaller pieces (halve the radius)
      }
   }

   // Override the destroy method (this can be customized based on your needs)
   void destroy(std::vector<Satellite*>& satellites) override {
      // Implement destroy logic specific to Part
   }

   // Override other methods specific to Part, if necessary
};
