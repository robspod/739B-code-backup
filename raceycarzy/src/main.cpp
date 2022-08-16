/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Tue Jan 28 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    3, 4            
// left                 motor         1               
// right                motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void forward();

int main() {
  while(true){
    Controller1.ButtonL1.pressed();

  }
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}
