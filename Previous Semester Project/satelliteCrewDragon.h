/***********************************************************************
 * Source File:
 *    Crew Dragon
 * Author:
 *    SAwyer Stakkeland
 * Summary:
 *    The Crew Dragon class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"

 /***************************************************
  * GPS
  ***************************************************/
class CrewDragon : public Satellite
{
public:
    CrewDragon() : Satellite() {
        pos.setMeters(0.0, 8000000.0);
        velocity.setDX(-7900.0);
        velocity.setDY(0.0);
        radius = 7 * pos.getZoom();
        angularVelocity = 1;
    }

    void draw(ogstream* pgout) {
        pgout->drawCrewDragon(pos, angle.getRadians()); 
    }

    void destroy(Satellite& satellite) { // Destruction logic here

    }

    void input(const Interface* pUI, list<Satellite*>& satellites) {}
private:
};
