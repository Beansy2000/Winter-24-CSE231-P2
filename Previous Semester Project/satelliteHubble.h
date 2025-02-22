/***********************************************************************
 * Source File:
 *    Hubble
 * Author:
 *    Sawyer Stakkeland
 * Summary:
 *    The Hubble class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"

 /***************************************************
  * Hubble
  ***************************************************/
class Hubble : public Satellite
{
public:
    Hubble() : Satellite() {
        pos.setMeters(0.0, -42164000.0);
        velocity.setDX(3100.0);
        velocity.setDY(0.0);
        radius = 10.0 * pos.getZoom();
        angularVelocity = 1;
    }

    void draw(ogstream* pgout) {
        pgout->drawHubble(pos, angle.getRadians());
    }

    void destroy(Satellite& satellite) { // Destruction logic here

    }

    void input(const Interface* pUI, list<Satellite*>& satellites) {}
private:
};
