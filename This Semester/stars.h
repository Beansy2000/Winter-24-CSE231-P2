/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once

#include "uiDraw.h"     // for RANDOM and DRAWSTAR
#include <random>


 /*****************************************************
  * STAR
  * A star that twinkles
  *****************************************************/
class Stars
{
public:
   struct Star {
      Position position;
      unsigned char phase;
      Star(Position pos, unsigned char ph) : position(pos), phase(ph) {}
   };

   Stars();
   Stars(double width, double height);
   void resetStars(double width, double height);
   void draw(ogstream& gout);

private:
   std::vector<Star> stars;  // Simple vector of Star structs
   double width, height;

   void initialize(double width, double height);
};