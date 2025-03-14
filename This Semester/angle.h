/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159 

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   // Constructors
   Angle() : radians(0.0) {}                                        // Default Constructor
   Angle(const Angle& rhs) : radians(rhs.radians) {}                // Copy Constructor
   Angle(double degrees, bool isRadians) : radians(0.0) {           // Non-default Constructor
      setRadians(convertToRadians(degrees));
      if (isRadians) {
         setRadians(degrees);
      }
   } 

   // Getters
   double getDegrees() const { return radians * (180 / M_PI); }
   double getRadians() const { return radians; }

   double getDx() const { return sin(radians); }
   double getDy() const { return cos(radians); }

   // Setters
   void setDegrees(double degrees) { this->radians = normalize(degrees * (M_PI / 180)); }
   void setRadians(double radians) { this->radians = normalize(radians); }

   void setUp() { this->radians = 0.0; }
   void setDown() { this->radians = M_PI; }
   void setRight() { this->radians = M_PI / 2; }
   void setLeft() { this->radians = M_PI + M_PI / 2; }

   void setDXY(double dx, double dy) { this->radians = normalize(atan2(dx, dy)); }

   void reverse();
   Angle& add(double delta);

private:
   double radians;

   double normalize(double rad) const;

   double convertToRadians(double degrees) const;
   double convertToDegrees(double rad) const;
};