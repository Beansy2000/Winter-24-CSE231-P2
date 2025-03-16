/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "angle.h"         // for ANGLE
#include "velocity.h"
#include "acceleration.h"
#include "stars.h"
#include "physics.h"
#include "test.h"
#include "satellite.h"
#include "satelliteSputnik.h"
#include "satelliteHubble.h"
#include "satelliteCrewDragon.h"
#include "satelliteGPS.h"
#include "satelliteStarlink.h"
#include "satelliteShip.h"
#include "earth.h"
#include "list"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      // ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      // ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      // ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      // ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      // 
      // ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      // ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      // 
      // ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      // ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      // 
      // ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      // ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      
		stars.resetStars(ptUpperRight.getPixelsX(), ptUpperRight.getPixelsY());

   }

   Earth ptEarth;
   Hubble ptHubble;
   Sputnik ptSputnik;
   Starlink ptStarlink;
   CrewDragon ptCrewDragon;
   Ship ptShip;
   GPS ptGPS1 = GPS(1);
   GPS ptGPS2 = GPS(2);
   GPS ptGPS3 = GPS(3);
   GPS ptGPS4 = GPS(4);
   GPS ptGPS5 = GPS(5);
   GPS ptGPS6 = GPS(6);
   //list<GPS> GPSArray{GPS(1), GPS(2), GPS(3), GPS(4), GPS(5), GPS(6)};
   Position ptStar;
   Position ptUpperRight;
   Stars stars;
   // Acceleration gravity;

   // Angle angleShip;
   // double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;
   double td = 24 * 60;
   double tpf = td / 30;

   //
   // accept input
   //
  /* if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);*/

   // move by a little
   pDemo->ptEarth.rotate(td);
   pDemo->ptHubble.move(tpf);
   pDemo->ptSputnik.move(tpf);
   pDemo->ptStarlink.move(tpf);
   pDemo->ptCrewDragon.move(tpf);
   pDemo->ptShip.move(tpf);
   pDemo->ptGPS1.move(tpf);
   pDemo->ptGPS2.move(tpf);
   pDemo->ptGPS3.move(tpf);
   pDemo->ptGPS4.move(tpf);
   pDemo->ptGPS5.move(tpf);
   pDemo->ptGPS6.move(tpf);
   /*for (auto gps : pDemo->GPSArray) {
       gps.move(tpf);
   }*/

   //
   // perform all the game logic
   //

	// Apply acceleration to velocity
	//double sputnikX = pDemo->ptSputnik.getMetersX();
	//double sputnikY = pDemo->ptSputnik.getMetersY();
 //  pDemo->angleShip.setRadians(pDemo->physics.getGravDirectionRadians(sputnikX, sputnikY));
	//cout << "X: " << sputnikX << " Y: " << sputnikY << endl;
   //pDemo->gravity.set(pDemo->angleShip, pDemo->physics.getAccelFromGravity(sputnikX, sputnikY) * 9800);
	//cout << "Angle: " << pDemo->physics.getGravDirectionRadians(sputnikX, sputnikY) << " DDX: " << pDemo->gravity.getDDX() << " DDY: " << pDemo->gravity.getDDY() << endl;
 //  pDemo->accSputnik.setDDX(pDemo->gravity.getDDX());
 //  pDemo->accSputnik.setDDY(pDemo->gravity.getDDY());
	//pDemo->velSputnik.add(pDemo->accSputnik, t);
	//cout << pDemo->velSputnik.getDX() << " " << pDemo->velSputnik.getDY() << endl;

	// Apply velocity to position
	
	//pDemo->ptSputnik.add(pDemo->accSputnik, pDemo->velSputnik, t);

   // rotate the earth
   //pDemo->angleEarth -= 0.01; // way too fast
   //pDemo->angleEarth -= 0.003490658504; // orginal calculation, too slow
   //pDemo->angleEarth -= 0.0040469023027; // noice

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   // gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   // gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   // gout.drawSputnik   (pDemo->ptSputnik.getPosition(), pDemo->ptSputnik.getAngle());
   pDemo->ptHubble.draw(gout);
   pDemo->ptSputnik.draw(gout);
   pDemo->ptStarlink.draw(gout);
   pDemo->ptCrewDragon.draw(gout);
   pDemo->ptShip.draw(gout);
   pDemo->ptGPS1.draw(gout);
   pDemo->ptGPS2.draw(gout);
   pDemo->ptGPS3.draw(gout);
   pDemo->ptGPS4.draw(gout);
   pDemo->ptGPS5.draw(gout);
   pDemo->ptGPS6.draw(gout);
 /*  for (auto gps : pDemo->GPSArray) {
       gps.draw(gout);
       gps.move(tpf);
   }*/
   // gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   // gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   // gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
   // pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   // pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   // gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   // pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   // pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   // gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   // pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   // pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   // gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   // pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   // pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   // gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   // pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   // pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   // gout.drawFragment(pt, pDemo->angleShip);
   // pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   // pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   // gout.drawFragment(pt, pDemo->angleShip);

   // draw all the stars
   pDemo->stars.draw(gout);

   // draw the earth
   pDemo->ptEarth.draw(gout);
   /*pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);*/
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
