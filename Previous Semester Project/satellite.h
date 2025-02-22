/***********************************************************************
 * Source File:
 *    SATELLITE
 * Summary:
 *    Everything we need to know about the base class for satellites
 ************************************************************************/

#include <iostream>
#include <cmath>
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "physics.h"
#include "acceleration.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <list>
using namespace std;
#pragma once

enum SatelliteType {
    SHIP, 
    GPS, GPS_LEFT, GPS_RIGHT, GPS_CENTER,
    HUBBLE, HUBBLE_LEFT, HUBBLE_RIGHT, HUBBLE_COMPUTER, HUBBLE_CENTER,
    STARLINK, STARLINK_BODY, STARLINK_ARRAY,
    SPUTNIK,
    CREWDRAGON,
    FRAGMENT
};


class Satellite {
protected:
    Velocity velocity;
    Position pos;
    Physics phys;
    double angularVelocity;
    bool dead;
    double radius;
    Angle angle;
    int age;
    bool useRandom;

public:
    Satellite(int age=0, double radius = 0.0, double angularVelocity = 0.0) : angularVelocity(angularVelocity), dead(false), radius(radius), age(age) {}

    // For creating fragments
    Satellite(const Satellite& parent, const Angle& direction) :
        velocity(parent.velocity),
        pos(parent.pos),
        angle(parent.angle),
        angularVelocity(parent.angularVelocity),
        radius(0.0),
        age(0),
        useRandom(parent.useRandom),
        dead(false) 
    {
        float speed = random(1000.0, 3000.0);
        if (parent.useRandom == false) {
            speed = 3000.0;
        }
        Velocity kick(speed, direction);
        velocity.addDX(kick.getDX());
        velocity.addDY(kick.getDY());

        // Compute the offset
        Position posKick;
        posKick.setPixelsX(4.0 * sin(direction.getRadians()));
        posKick.setPixelsY(4.0 * cos(direction.getRadians()));
        pos.addMetersX(posKick.getMetersX());
        pos.addMetersY(posKick.getMetersY());
    };

    // For projectile
    Satellite(const Satellite& parent, const Position& offset, const Velocity& kick) :
        velocity(parent.velocity),
        pos(parent.pos),
        angle(parent.angle),
        angularVelocity(parent.angularVelocity),
        radius(0.0),
        age(0),
        useRandom(parent.useRandom),
        dead(false)
    {
        velocity.addDX(kick.getDX());
        velocity.addDY(kick.getDY());

        pos.addMetersX(offset.getMetersX());
        pos.addMetersY(offset.getMetersY());
    };

    float getRadius() const {
        return radius;
    }
    double getAngle() const {
        return angle.getRadians();
    }
    

    bool isDead() const {
        return dead;
    }

    Position getPosition() const {
        return pos;
    }

    void setMetersX(double metersX) {
        pos.setMetersX(metersX);
    }
    void setMetersY(double metersY) {
        pos.setMetersY(metersY);
    }
    void setMeters(double x, double y) {
        pos.setMeters(x, y);
    }
    void setDX(double dx) {
        velocity.setDX(dx);
    }
    void setDY(double dy) {
        velocity.setDY(dy);
    }
    void setAngle(float radians) {
        angle.setRadians(radians);
    }

    void addDX(double dx) {
        velocity.addDX(dx);
    }
    void addDY(double dy) {
        velocity.addDY(dy);
    }

    double getMetersX() {
        return pos.getMetersX();
    }
    double getMetersY() {
        return pos.getMetersY();
    }
    double getDX() {
        return velocity.getDX();
    }
    double getDY() {
        return velocity.getDY();
    }

    void kill() {
        dead = true;
    }

    virtual void draw(ogstream& gout) {
        // Drawing logic here
    }

    void destroy(Satellite& satellite) {
        // Destruction logic here
    }

    void move(float time) {
        // Calculate the gravitational acceleration
        double accel = phys.getAccelFromGravity(pos.getMetersX(), pos.getMetersY());

        // Get the direction of gravity in radians
        double gravDirection = phys.getGravDirectionRadians(pos.getMetersX(), pos.getMetersY());

        // Calculate the changes in velocity (dx and dy) due to gravity
        double ddx = phys.getDDX(accel, gravDirection);
        double ddy = phys.getDDY(accel, gravDirection);

        // Update the velocity based on acceleration
        velocity.setDX(velocity.getDX() + ddx * time);
        velocity.setDY(velocity.getDY() + ddy * time);

        // Update the position based on velocity
        pos.setMetersX(pos.getMetersX() + velocity.getDX() * time);
        pos.setMetersY(pos.getMetersY() + velocity.getDY() * time);

        // Rotational inertia
        angle.add(angularVelocity);

        age++;
    }
    

    virtual void input(const Interface* ui, list <Satellite*>& satellites) {
        // Input handling logic here
    }
};

class Projectile : public Satellite {
public:
    Projectile(const Satellite& parent, const Position& offset, const Velocity& kick) : Satellite(parent, offset, kick) {
        this->radius = 1.0 * this->pos.getZoom();
    }

    void move(float time) {
        Satellite::move(time);
        if (age > 100)
            dead = true;
    };

    virtual void draw(ogstream& gout) {
        gout.drawProjectile(this->pos);
    }
};

class Fragment : public Satellite {
public:
    Fragment(const Satellite& parent, const Angle& direction) : Satellite() {
        this->age = random(0, 50);
    }

    void move(float time) {
        Satellite::move(time);
        if (age > 50)
            dead = true;
    };

    virtual void draw(ogstream& gout) {
        gout.drawFragment(this->pos, this->angle.getRadians());
    }
};
