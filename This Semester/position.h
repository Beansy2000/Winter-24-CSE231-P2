 /***********************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/
#pragma once

#include <iostream> 
#include <cmath>
#include "acceleration.h"
#include "velocity.h"

class TestPosition;
class Acceleration;
class Velocity;

/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
class Position
{
public:
   friend TestPosition;
   
   // constructors
   Position()            : x(0.0), y(0.0)  {}
   Position(double x, double y) : x(x), y(y) {}
   Position& operator = (const Position& pt);

   // getters
   double getMetersX()       const { return x;                    }
   double getMetersY()       const { return y;                    }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) {x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)       { x = xMeters;           }
   void setMetersY(double yMeters)       { y = yMeters;           }
   void setPixelsX(double xPixels)       { x = xPixels * metersFromPixels;          }
   void setPixelsY(double yPixels)       { y = yPixels * metersFromPixels;          }
   void addMetersX(double dxMeters)      { setMetersX(getMetersX() + dxMeters);     }
   void addMetersY(double dyMeters)      { setMetersY(getMetersY() + dyMeters);     }
   void addPixelsX(double dxPixels)      { setPixelsX(getPixelsX() + dxPixels);     }
   void addPixelsY(double dyPixels)      { setPixelsY(getPixelsY() + dyPixels);     }

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels) { this->metersFromPixels = metersFromPixels; }
   double getZoom() const { return metersFromPixels; }

   bool operator < (const Position& other) const { return x < other.x || (x == other.x && y < other.y); }
   bool operator == (const Position& rhs) const { return rhs.getMetersX() == x && rhs.getMetersY() == y; }
   bool operator != (const Position& rhs) const { return rhs.getMetersX() != x || rhs.getMetersY() != y; }

   void add(const Acceleration& a, const Velocity& v, double t);

private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};

inline double computeDistance(const Position& pos1, const Position& pos2);
// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);




/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


