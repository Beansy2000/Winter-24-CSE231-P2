/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    Sawyer Stakkeland
 * Summary:
 *    The GPS class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"

 /***************************************************
  * GPS
  ***************************************************/
class Gps : public Satellite
{
    public:
        Gps(int i) : Satellite() { 
            switch (i) {
            case 1:
                pos.setMeters(0.0, 26560000.0);
                velocity.setDX(-3880.0);
                velocity.setDY(0.0);
                break;
            case 2:
                pos.setMeters(23001634.72, 13280000.0);
                velocity.setDX(-1940.0);
                velocity.setDY(3360.18);
                break;
            case 3:
                pos.setMeters(23001634.72, -13280000.0);
                velocity.setDX(1940.0);
                velocity.setDY(3360.18);
                break;
            case 4:
                pos.setMeters(0.0, -26560000.0);
                velocity.setDX(3880.0);
                velocity.setDY(0.0);
                break;
            case 5:
                pos.setMeters(-23001634.72, -13280000.0);
                velocity.setDX(1940.0);
                velocity.setDY(-3360.18);
                break;
            case 6:
                pos.setMeters(-23001634.72, 13280000.0);
                velocity.setDX(-1940.0);
                velocity.setDY(-3360.18);
                break;
             }
            radius = 12.0 * pos.getZoom(); 
            angularVelocity = 1;
        }
        Gps(double x, double y, double dx, double dy) : Satellite() {
            pos.setMeters(x, y);
            velocity.setDX(dx);
            velocity.setDY(dy);
            radius = 12.0 * pos.getZoom();
        }

        void draw(ogstream* pgout) {
            pgout->drawGPS(pos, angle.getRadians());
        }

        void destroy(Satellite & satellite) { // Destruction logic here
           
        }
    private:
};
