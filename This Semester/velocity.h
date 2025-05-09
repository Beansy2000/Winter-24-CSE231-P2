/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

// for add()
class Acceleration;
class Angle;

/*********************************************
 * Velocity
 * I feel the need, the need for speed
 *********************************************/
class Velocity
{
public:
   // constructors
   Velocity() : dx(0.0), dy(0.0) { }
   Velocity(double dx, double dy) : dx(dx), dy(dy) { }

   // getters
   double getDX() const { return dx; }
   double getDY() const { return dy; }

   double getSpeed() const;

   // setters
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void setDXY(double dx, double dy) { this->dx = dx; this->dy = dy; }

   void set(const Angle& angle, double magnitude);

   void addDX(double dx) { this->dx += dx; }
   void addDY(double dy) { this->dy += dy; }

   virtual void add(const Acceleration& acceleration, double time);
   virtual void add(const Velocity& v);

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};