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
#include "projectile.h"
#include "earth.h"
#include "list"
#include "collision.h"
#include "algorithm"
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
		stars.resetStars(ptUpperRight.getPixelsX(), ptUpperRight.getPixelsY());
   }
   Collision ptCollision;
   Earth ptEarth;
   Ship ptShip;
   Position ptStar;
   Position ptUpperRight;
   Stars stars;
   list<Projectile*> projectiles;
   list<Satellite*> Satellites{ new Hubble, new Sputnik, new Starlink, new CrewDragon, new GPS(1), new GPS(2),
       new GPS(3), new GPS(4), new GPS(5), new GPS(6), &ptShip };
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
   if (std::find(pDemo->Satellites.begin(), pDemo->Satellites.end(), &pDemo->ptShip) != pDemo->Satellites.end()) {
       if (pUI->isUp()) {
           pDemo->ptShip.drive();
       }
       else {
           pDemo->ptShip.drawThrust = false;
       }
       //if (pUI->isDown())
       //    pDemo->ptShip.addPixelsY(-cos(pDemo->ptShip.getAngle()));
       //    pDemo->ptShip.addPixelsX(-sin(pDemo->ptShip.getAngle()));
       if (pUI->isLeft())
           pDemo->ptShip.rotateLeft();
       if (pUI->isRight())
           pDemo->ptShip.rotateRight();
       if (pUI->isSpace()) {
           pDemo->projectiles.push_back(new Projectile(pDemo->ptShip));
       }
   }

   // move by a little
   // collision detection and destruction
   pDemo->ptEarth.rotate(td);
   sattosatcollision:
   for (auto satellite : pDemo->Satellites) {
       satellite->move(tpf);
       for (auto satelliteB : pDemo->Satellites) {
           if (satellite != satelliteB) {
               if (pDemo->ptCollision.IsColliding(*satellite, *satelliteB)) {
                   pDemo->Satellites.remove(satellite);
                   pDemo->Satellites.remove(satelliteB);
                   satellite->destroy(satelliteB);
                   satelliteB->destroy(satellite);
                   satellite = nullptr;
                   satelliteB = nullptr;
                   goto sattosatcollision;
               }
           }
       }
   }
   sattoearthcollision:
   for (auto satellite : pDemo->Satellites) {
       if (pDemo->ptCollision.IsColliding(*satellite, pDemo->ptEarth)) {
           pDemo->Satellites.remove(satellite);
           satellite->destroy();
           satellite = nullptr;
           goto sattoearthcollision;
       }
   }
   projectileexpiration:
   for (auto projectile : pDemo->projectiles) {
       projectile->move(tpf);
       if (projectile->expirationTimer <= 0) {
           pDemo->projectiles.remove(projectile);
           projectile = nullptr;
           goto projectileexpiration;
       }
   }
   sattoprojectilecollision:
   for (auto projectile : pDemo->projectiles) {
       for (auto satellite : pDemo->Satellites) {
           if (pDemo->ptCollision.IsColliding(*satellite, *projectile) and satellite != &pDemo->ptShip) {
               pDemo->Satellites.remove(satellite);
               satellite->destroy(projectile);
               pDemo->projectiles.remove(projectile);
               satellite = nullptr;
               projectile = nullptr;
               goto sattoprojectilecollision;
           }
       }
   }

   //
   // perform all the game logic
   //

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);
   // draw all the stars
   pDemo->stars.draw(gout);

   // draw projectiles and satellites
   for (auto projectile : pDemo->projectiles) {
       projectile->draw(gout);
   }
   for (auto satellite : pDemo->Satellites) {
       satellite->draw(gout);
   }

   // draw the earth
   pDemo->ptEarth.draw(gout);
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
