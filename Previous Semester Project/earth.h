#pragma once
#include "satellite.h"
#include "uiDraw.h"

class Earth : public Satellite {
public:
	Earth() : Satellite() {
		pos.setMeters(0.0, 0.0);
		velocity.set(0.0, 0.0);
		radius = 6378;
		angularVelocity = -(2 * M_PI / 30) * (24 * 60 / 86400);
	}

	void draw(ogstream* pgout) {
		pgout->drawEarth(pos, angle.getRadians()); //second parameter needs to be fixed
	}

	void destroy(Satellite& satellite) { // Destruction logic here

	}

	void input(const Interface* pUI, list<Satellite*>& satellites) {}
private:
};
