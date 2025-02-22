/***********************************************************************
 * Source File:
 *    Starlink
 * Author:
 *    Sawyer Stakkeland
 * Summary:
 *    The Starlink class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"

 /***************************************************
  * Sputnik
  ***************************************************/
class Starlink : public Satellite
{
public:
    Starlink() : Satellite() {
        pos.setMeters(0.0, -13020000.0);
        velocity.setDX(5800.0);
        velocity.setDY(0.0);
        radius = 6 * pos.getZoom();
        angularVelocity = 1;
    }

    void draw(ogstream* pgout) {
        pgout->drawStarlink(pos, angle.getRadians()); 
    }

    void destroy(Satellite& satellite) { // Destruction logic here

    }
private:
};

