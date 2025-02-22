/***********************************************************************
 * Header File:
 *    ANGLE
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

 // for the unit tests
class TestAngle;
class TestPosition;
class TestVelocity;
class TestAcceleration;


/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
    // for the unit tests
    friend TestAcceleration;
    friend TestVelocity;
    friend TestAngle;
    class TestPosition;

    // Constructors
    Angle() : radians(0.0) {}
    Angle(const Angle& rhs) : radians(rhs.radians) {  }
    Angle(double degrees) : radians(0.0) { setDegrees(degrees); }

    // Getters
    double getDegrees() const { return convertToDegrees(radians); }
    double getRadians() const { return radians; }

    //         dx
    //    +-------/
    //    |      /
    // dy |     /
    //    |    / 1.0
    //    | a /
    //    |  /
    //    | /
    // dy = cos a
    // dx = sin a
    double getDx() const { return sin(radians); }
    double getDy() const { return cos(radians); }
    bool isRight() const { return radians < M_PI; }
    bool isLeft() const { return radians > M_PI; }

    // Setters
    void setDegrees(double degrees) { radians = normalize(convertToRadians(degrees)); }
    void setRadians(double radians) { this->radians = normalize(radians); }
    void setUp() { radians = 0.0; }
    void setDown() { radians = M_PI; }
    void setRight() { radians = M_PI * 0.5; }
    void setLeft() { radians = M_PI * 1.5; }
    void reverse() { radians = normalize(radians + M_PI); }
    Angle operator-() const                                              // Added from the video to make advance work
    {
        Angle aReturn(*this);
        aReturn.reverse();
        return aReturn;
    }
    Angle& add(double delta) { radians = normalize(radians + delta); return *this; }

    // set based on the components
    //         dx
    //     +-------/
    //     |      /
    //  dy |     /
    //     |    /
    //     | a /
    //     |  /
    //     | /
    void setDxDy(double dx, double dy) { radians = normalize(atan2(dx, dy)); }
    Angle operator+(double degrees) const { return Angle(getDegrees() + degrees); }

    double radians;   // 360 degrees equals 2 PI radians

private:
    double convertToDegrees(double radians) const
    {
        return radians / (M_PI * 2.0) * 360.0;
    }
    double convertToRadians(double degrees) const
    {
        return degrees / 360.0 * (M_PI * 2.0);
    }
    double normalize(double radians) const;
};

#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
    out << rhs.getDegrees() << "degree";
    return out;
}