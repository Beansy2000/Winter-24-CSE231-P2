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

	Stars()
	{
		initialize(100.0, 100.0);
	}
   Stars(double width, double height)
   {
      initialize(width, height);
   }

   void resetStars(double width, double height) {
      initialize(width, height);
   }

   void draw(ogstream& gout) {
      for (auto& star : stars) {
         gout.drawStar(star.position, star.phase);
         star.phase++;  // Increment phase (twinkle effect)
      }
   }

private:
   std::vector<Star> stars;  // Simple vector of Star structs
   double width, height;

   void initialize(double width, double height) {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_real_distribution<> xDis(-width, width);
      std::uniform_real_distribution<> yDis(-height, height);
      std::uniform_int_distribution<> pDis(0, 255);

      stars.clear();  // Clear any existing stars

      // Generate 50 stars with random positions and phases
      for (int i = 0; i < 5000; ++i) {
         Position pos(xDis(gen), yDis(gen));
         unsigned char phase = static_cast<unsigned char>(pDis(gen));
         stars.emplace_back(pos, phase);
      }
   }
};