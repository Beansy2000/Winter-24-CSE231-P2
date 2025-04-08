/***********************************************************************
 * Source File:
 *    STARS
 * Author:
 *    Tyler Philips, Cesar Tavarez, and Boston Stamm
 * Summary:
 *    Everything we need to know about the base class for Stars
 ************************************************************************/
#pragma once

#include "stars.h"

/*************************************
 * STARS : CONSTRUCTOR
 *************************************/
Stars::Stars() {
	initialize(100.0, 100.0);
}

/*************************************
 * STARS : CONSTRUCTOR
 *************************************/
Stars::Stars(double width, double height) {
    initialize(width, height);
}

/*************************************
 * STARS : RESETSTARS
 *************************************/
void Stars::resetStars(double width, double height) {
    initialize(width, height);
}

/*************************************
 * STARS : DRAW
 *************************************/
void Stars::draw(ogstream& gout) {
    for (auto& star : stars) {
        gout.drawStar(star.position, star.phase);
        star.phase++;  // Increment phase (twinkle effect)
    }
}

/*************************************
 * STARS : INITIALIZE
 *************************************/
void Stars::initialize(double width, double height) {
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