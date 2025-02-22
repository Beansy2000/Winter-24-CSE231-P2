//#pragma once
///***********************************************************************
// * Source File:
// *    projectile.h
// * Author:
// *    Boston
// * Summary:
// *    The Projectile class
// ************************************************************************/
//
//#pragma once
//#include "uiDraw.h"
//#include "physics.h"
//#include "velocity.h"
//#include "angle.h"
//#include "satellite.h"
//
// /***************************************************
//  * GPS
//  ***************************************************/
//class Projectile : public Satellite
//{
//public:
//    Projectile() : Satellite() {}
//    Projectile(double x, double y, double dx, double dy){
//        pos.setMeters(x, y);
//        velocity.setDX(dx);
//        velocity.setDY(dy);
//    }
//    bool isActive = false;
//
//    void draw(ogstream* pgout) {
//        pgout->drawProjectile(getPosition());
//    }
//
//    void destroy(Satellite& satellite) { // Destruction logic here
//
//    }
//
//    Position getPosition() {
//        return pos;
//    }
//    void fire(Satellite& ship) {
//        pos.setMeters(ship.getMetersX(), ship.getMetersY());
//        velocity.setDX(ship.getDX());
//        velocity.setDY(ship.getDY());
//    }
//private:
//
//};