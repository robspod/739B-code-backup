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
// Left                 motor         13              
// Right                motor         5               
// top2                 motor         10              
// middle               motor         9               
// bottom               motor         8               
// Controller1          controller                    
// arm1                 motor         11              
// arm2                 motor         7               
// Vision               vision        19              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
int choice = 0;
int speed = 2;
int speed2 = 2;
int speedpct = 100;
double wheeldi = 4.125;
double pi = 3.1415926535;
int degin = (pi * wheeldi)/ 360;
int wheelleng = 14;
double disquard = (wheelleng * pi)/4;
int speedfor = 50;
int batlevel = Brain.Battery.voltage();
int LIFT = 1;
// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


void forwardin(double inchs){
 double length = inchs * degin;

 Left.rotateFor(length,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false);
 Right.rotateFor(length,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct);


}

void turnright(int degs){
Left.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
Right.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
  
    
}
void turnleft(int degs){
Left.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
Right.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
    
}
void forwardd(){
    Left.spin(vex::directionType::fwd,50,vex::velocityUnits::pct); 
    Right.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);

}

void backward(){
    Left.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
    Right.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
}
void TurnRight(){
    Left.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);
    Right.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
}
void TurnLeft(){
    Left.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
    Right.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);
}
void stopall(){
    Left.stop(vex::brakeType::brake);
    Right.stop(vex::brakeType::brake);
}
void stopleft(){
    Left.stop(vex::brakeType::brake);
}
void stopright(){
    Right.stop(vex::brakeType::brake);
}
void armsin(){
  arm1.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  arm2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  
}
void armsout(){
  arm1.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  arm2.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
 
}
void armstop(){
  arm1.stop(vex::brakeType::brake);
  arm2.stop(vex::brakeType::brake);
   middle.stop(vex::brakeType::brake);

}
void outtop(){
  top2.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  bottom.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
}
void outback(){
  top2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  bottom.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
}
void spinstop(){
  top2.stop(vex::brakeType::brake);
  middle.stop(vex::brakeType::brake);
  bottom.stop(vex::brakeType::brake);

}
void BIG_PP(){
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print("------________");
  Controller1.Screen.setCursor(2,1);
  Controller1.Screen.print("|===             )");
  Controller1.Screen.setCursor(3,1);
  Controller1.Screen.print("____------------");
  
  
}
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  BIG_PP();
  
  
  
  
  while (1) {
  int abs = false;
  while(abs == true){
    Vision.takeSnapshot(Vision__REDS);
    int ang = Vision.objects[0].angle;
    int dis = 18 * cos(45);
    Controller1.Screen.clearScreen();
    Controller1.Screen.print(dis);           
 }  

  
  
  
  
  
  
  
  Controller1.ButtonR1.pressed(armsout);
  Controller1.ButtonR1.released(armstop);
  Controller1.ButtonR2.pressed(armsin);
  Controller1.ButtonR2.released(armstop);
  Controller1.ButtonA.pressed(outtop);
  Controller1.ButtonA.released(spinstop);
  Controller1.ButtonX.pressed(outback);
  Controller1.ButtonX.released(spinstop);
  // main wheel drive
  Left.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/speed , vex::velocityUnits::pct); //(Axis3+Axis4)/2
  Right.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/2

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
