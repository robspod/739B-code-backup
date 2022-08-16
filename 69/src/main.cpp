/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Thu Oct 10 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

uint8_t     myTestData[ 100 ];
uint8_t     myReadBuffer[ 76549 ];

int main() {
    Brain.Screen.drawImageFromFile ("face.png",100,100);


        


        int nRead = Brain.SDcard.loadfile( "face.png", myReadBuffer, sizeof(myReadBuffer) );