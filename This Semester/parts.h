#pragma once
#include "position.h"  // To define the position of the part

class Part {
protected:
   Position position;  // Position of the part in space
   double radius;      // Size of the part (we assume spherical parts for simplicity)
   bool isFragment;    // Flag to determine if the part is a fragment

public:
   // Constructor to initialize a part
   Part(Position position, double radius, bool isFragment = false)
      : position(position), radius(radius), isFragment(isFragment) {}

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
};
