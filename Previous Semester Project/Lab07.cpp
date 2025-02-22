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
#include "test.h"
#include "physics.h"
#include "satellite.h"
#include "satelliteStarlink.h"
#include "satelliteSputnik.h"
#include "satelliteGps.h"
#include "satelliteHubble.h"
#include "satelliteCrewDragon.h"
#include "satelliteShip.h"
#include "projectile.h"
#include "earth.h"
#include <list>

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
private:
    list<Satellite*> satellites;
    double tpf;
public:
   Demo(Position ptUpperRight) :
                    ptUpperRight(ptUpperRight)
   {
       phaseStar = 0;

       // Satellite Creation
       for (int i = 1; i <= 6; i++)
           satellites.push_back(new Gps(i));
       satellites.push_back(new Hubble());
       satellites.push_back(new Sputnik());
       satellites.push_back(new Starlink());
       satellites.push_back(new CrewDragon());
       satellites.push_back(new Ship());

       // calculations for simulation speed
       double td = 24 * 60;   // Time dialation = hoursDay x minutesHour
       tpf = td / 30;    // Time per frame = td / framerate
   }

   Position* ptStar = new Position[50];
   Position ptUpperRight;

   unsigned char phaseStar;
   int starLoops = 0;
   int count = 0;

   void input(const Interface* ui) {
       for (auto it = satellites.begin(); it != satellites.end(); ++it)
           (*it)->input(ui, satellites);
   }

   void draw(ogstream& pgout) {
       for (auto it = satellites.begin(); it != satellites.end(); ++it)
       {
           (*it)->draw(pgout);
       }
   }

   void move() {
       list<Satellite*> ::iterator it1;
       list<Satellite*> ::iterator it2;

       // Move everything
       for (auto satellite : satellites)
           satellite->move(tpf);

       // Handles collisions
       // ADD COLLISIONS HERE
       //
       //
       //

       // Destroy anything that has been marked as dead
       // for (it1 = satellites.begin(); it1 != satellites.end();)
   }
    
    // For testing purposes
    list<Satellite*> getList() {
        return satellites;
    }
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
   Demo* pSim = (Demo*)p;

   //
   // perform all the game logic
   //

   // accept input for ship
   pSim->input(pUI);

   //Move each satellite
   pSim->move();


   //
   // draw everything
   //
   Position pt;
   ogstream gout(pt);

   // draw satellites & earth
   pSim->draw(gout);


   // draw 50 stars
   pSim->phaseStar++;
   if (pSim->starLoops == 0)
   {
       for (int i = 0; i < 50; i++)
       {
           pSim->ptStar[i].setPixelsX(pSim->ptUpperRight.getPixelsX() * random(-0.5, 0.5));
           pSim->ptStar[i].setPixelsY(pSim->ptUpperRight.getPixelsY() * random(-0.5, 0.5));
       }

       pSim->starLoops += 1;
   }
   for (int i = 0; i < 50; i++)
   {
       pSim->phaseStar = random(0, 244);
       gout.drawStar(pSim->ptStar[i], pSim->phaseStar);
   }
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
