/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RoboticArm1          RoboticArm    1, 2, 3, 4, A, B, C, D
// Controller1          controller                    
// Drivetrain           drivetrain    5, 6, 7         
// LED                  led           H               
// DigitalInG           digital_in    G               
// DigitalOutF          digital_out   F               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


competition Competition;





void pre_auton(void) {
  
  vexcodeInit();
  int choice = 0;
  int aa = 100;
  int bb = 1;
  int cc = 240;
  int dd = 1;
  int ee = 390;
  int ff = 1;
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(black);
  Brain.Screen.setPenColor( red );
  Brain.Screen.setPenWidth(10); 
  Brain.Screen.drawRectangle(5,5,465,220);
  Brain.Screen.setFillColor(yellow);
  Brain.Screen.drawCircle(100, 1, 30); 
  Brain.Screen.drawCircle(240, 1, 30);
  Brain.Screen.drawCircle(390, 1, 30);
 

  while(choice < 1){
    if(Brain.Screen.pressing() and Brain.Screen.xPosition() > aa - 30 and Brain.Screen.yPosition() > bb - 30 and Brain.Screen.xPosition() < aa + 30 and Brain.Screen.yPosition() < bb + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      aa = Brain.Screen.xPosition();
      bb = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(cc, dd, 30);
      Brain.Screen.drawCircle(ee, ff, 30);
      Brain.Screen.drawCircle(aa,bb,30);

      }
    }

    if(Brain.Screen.pressing() and Brain.Screen.xPosition() > cc - 30 and Brain.Screen.yPosition() > dd - 30 and Brain.Screen.xPosition() < cc + 30 and Brain.Screen.yPosition() < dd + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      cc = Brain.Screen.xPosition();
      dd = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(aa, bb, 30); 
      Brain.Screen.drawCircle(ee, ff, 30);
      Brain.Screen.drawCircle(Brain.Screen.xPosition(),Brain.Screen.yPosition(),30);
      }
    }
   if(Brain.Screen.pressing() and Brain.Screen.xPosition() > ee - 30 and Brain.Screen.yPosition() > ff - 30 and Brain.Screen.xPosition() < ee + 30 and Brain.Screen.yPosition() < ff + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      ee = Brain.Screen.xPosition();
      ff = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(aa, bb, 30); 
      Brain.Screen.drawCircle(cc, dd, 30);
      Brain.Screen.drawCircle(Brain.Screen.xPosition(),Brain.Screen.yPosition(),30);
      }
    }
  }
}



void autonomous(void) {


  
}



void usercontrol(void) {
  
  while (1) {
    

    wait(20, msec); 

  }
}


int main() {
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  
  pre_auton();

  
  while (true) {
    wait(100, msec);
  }
}
