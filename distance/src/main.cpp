/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Mon Aug 24 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RangeFinderA         sonar         A, B            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;




int main() {
 while(true){
  RangeFinderA.distance(inches); 
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print(RangeFinderA.distance(inches)); 
 }
  
  
  // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
  
}
