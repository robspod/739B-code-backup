/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Mon Nov 18 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  while(true){
    Brain.Screen.clearScreen();
    Brain.Screen.drawRectangle(10,10,90,90,50);
    Brain.Screen.drawRectangle(150,150,90,90,30);
    Brain.Screen.drawRectangle(10,10,40,40,10);
  }
  vexcodeInit();
  
}
