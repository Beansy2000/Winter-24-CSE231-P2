/***********************************************************************
 * Source File:
 *    satelliteShip.h
 * Author:
 *    Sawyer Stakkeland
 * Summary:
 *    The Ship class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include <iostream>
using namespace std;

 /***************************************************
  * Ship
  ***************************************************/
class Ship : public Satellite
{
private:
    double thrust = 0.05;  // Accelleration
    bool drawThrust;

public:
    Ship() : Satellite()  {
        pos.setPixelsX(-450);
        pos.setPixelsY(450);
        velocity.setDY(-2000);
        radius = 10 * pos.getZoom();
        drawThrust = false;
    }
    Ship(double x, double y, double dx, double dy) : Satellite() {
        pos.setMeters(x, y);
        velocity.setDX(dx);
        velocity.setDY(dy);
        radius = 10;
    }

    void draw(ogstream* pgout) {
        if (isDead() == false)
            pgout->drawShip(pos, angle.getRadians(), drawThrust);
    }

    void destroy(Satellite& satellite) { // Destruction logic here

    }

    double getThrust() {
        return thrust;
    }

    void input(const Interface* pUI, list<Satellite*>& satellites) { 

        float time = 24 * 60 / 30;

        drawThrust = false;
        if (pUI->isUp()) {
            velocity.addDX(0.5 * (angle.getDx() * thrust * (time * time)));
            velocity.addDY(0.5 * (angle.getDy() * thrust * (time * time)));
            drawThrust = true;
           }
        if (pUI->isLeft()) {
            angle.setRadians(angle.getRadians() - 0.05);
        }
        if (pUI->isRight()) {
            angle.setRadians(angle.getRadians() + 0.05);
        }
        if (pUI->isSpace()) {
            Velocity kick;
            kick.set(this->getAngle(), 3000);
            Position offset;
            offset.setMeters(this->getAngle(), 10.01 * pos.getZoom());

            satellites.push_back(new Projectile(*this, offset, kick));
        }
    }
};