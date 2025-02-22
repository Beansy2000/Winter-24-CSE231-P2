/***********************************************************************
 * Source File:
 *    Sputnik
 * Author:
 *    Sawyer Stakkeland
 * Summary:
 *    The Sputnik class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <list>


 /***************************************************
  * Sputnik
  ***************************************************/
class Sputnik : public Satellite
{
public:
    Sputnik() : Satellite() {
        pos.setMeters(-36515095.13, 21082000.0);
        velocity.setDX(2050);
        velocity.setDY(2684);
        radius = 4.0 * pos.getZoom();
        angularVelocity = 1;
    }

    void draw(ogstream* pgout) {
        pgout->drawSputnik(pos, angle.getRadians());
    }

    void destroy(Satellite& satellite) { // Destruction logic here

    }

    void input(const Interface* pUI, list<Satellite*>& satellites) {}
private:
};
