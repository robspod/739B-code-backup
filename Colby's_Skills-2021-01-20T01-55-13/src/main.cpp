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
// top2                 motor         10              
// middle               motor         12              
// bottom               motor         8               
// Controller1          controller                    
// arm1                 motor         11              
// arm2                 motor         7               
// topback              motor         9               
// Drivetrain           drivetrain    5, 13           
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
double degin = (pi * wheeldi);
int wheelleng = 14;
double disquard = (wheelleng * pi)/4;
int speedfor = 75;
int batlevel = Brain.Battery.voltage();
int LIFT = 1;
int speedz = 50;
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


/*void forwardin(double inchs){
 
 Left.setMaxTorque(30, percent); 
 Right.setMaxTorque(30, percent); 
 double length = (inchs / degin) * 360;
 //int accel = times * speedfor
 Left.rotateFor(length,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false);
 Right.rotateFor(length,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct);


}
*/
void turnright(int degs){
//Left.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
//Right.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
Drivetrain.turnFor(right, degs, degrees); 
  
    
}
void turnleft(int degss){
//Left.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
//Right.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
Drivetrain.turnFor(left, degss, degrees); 
}
/*
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
}*/
void armsin(){
  arm1.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  arm2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  
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
  top2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  bottom.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  topback.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
}
void outback(){
  top2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  bottom.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  topback.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
}
void spinstop(){
  top2.stop(vex::brakeType::brake);
  middle.stop(vex::brakeType::brake);
  bottom.stop(vex::brakeType::brake);
  topback.stop(vex::brakeType::brake);

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
void move(int dist ){
  Drivetrain.driveFor(dist,inches); 
}

/*void burnout(){
  Left.stop(vex::brakeType::hold);
  Right.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
}*/
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
Drivetrain.setDriveVelocity(55
, percent); 
Drivetrain.setTurnVelocity(25, percent); 
armsout();
 // forwardin(25);
  move(17);
  armstop();
  turnleft(144);
  move(25);
  armsout();
  outback();
  wait(1.5,sec);
  armstop();
  wait(0.5,sec);
  spinstop();
  move(-16);
  turnright(115);
  armsout();
  outtop();
  move(30);
  spinstop();
  armsout();
  move(15);
  turnleft(90);
  armstop();
  move(5);
  outback();


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
 // BIG_PP();
  
  
  
  
 while (1) {
  //int abs = false;
  //while(abs == true){
    //Vision.takeSnapshot(Vision__REDS);
    //int ang = Vision.objects[0].angle;
    //int dis = 18 * cos(45);
    //Controller1.Screen.clearScreen();
    //Controller1.Screen.print(dis);           
 //}  
if(Controller1.ButtonL1.pressing()){
            if(speed == 1){
                Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print("Stop");
                Controller1.rumble("-");
            }
            else{
                speed -= 1;
               // speed -= 20;
                Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print(speed);
                wait(100,msec);
                //Drivetrain.setDriveVelocity(speedz, percent); 
            }
        }
        if(Controller1.ButtonL2.pressing()){
           if(Controller1.ButtonR2.pressing()){
                speed = speed + 1;
               // speedz += 20;
                Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print(speed);
                wait(100,msec);
           }
            
            if(speed == 5){
                Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print("Stop");
                Controller1.rumble("-.");
           }
            
            else{
                speed += 1;
               // speedz += 20;
                Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print(speed);
                //Drivetrain.setDriveVelocity(speedz, percent); 
                wait(100,msec);
            }
            
        }
 // Drivetrain.setDriveVelocity((100/speed), percent); 
/*       if(Controller2.ButtonL1.pressing()){
            if(speed2 == 1){
                Controller2.Screen.clearScreen();
                Controller2.Screen.setCursor(1, 1); 
                Controller2.Screen.print("Stop");
                Controller2.rumble("-");
            }
            else{
                speed2 = speed2 - 1;
                Controller2.Screen.clearScreen();
                Controller2.Screen.setCursor(1, 1); 
                Controller2.Screen.print(speed2);
                wait(100,msec);
            }
        }
        if(Controller2.ButtonL2.pressing()){
           if(Controller2.ButtonR2.pressing()){
                speed2 = speed2 + 1;
                Controller2.Screen.clearScreen();
                Controller2.Screen.setCursor(1, 1); 
                Controller2.Screen.print(speed2);
                wait(100,msec);
           }
            
            if(speed2 == 5){
                Controller2.Screen.clearScreen();
                Controller2.Screen.setCursor(1, 1); 
                Controller2.Screen.print("Stop");
                Controller2.rumble("-.");
           }
            
            else{
                speed2 = speed2 + 1;
                Controller2.Screen.clearScreen();
                Controller2.Screen.setCursor(1, 1); 
                Controller2.Screen.print(speed2);
            }
  */
  
  
  
  
  
  
  Controller1.ButtonR1.pressed(armsout);
  Controller1.ButtonR1.released(armstop);
  Controller1.ButtonR2.pressed(armsin);
  Controller1.ButtonR2.released(armstop);
  Controller1.ButtonA.pressed(outtop);
  Controller1.ButtonA.released(spinstop);
  Controller1.ButtonX.pressed(outback);
  Controller1.ButtonX.released(spinstop);
  //Controller1.ButtonUp.pressed(burnout);
  //Controller1.ButtonUp.released(stopall);
  // main wheel drive
 // Left.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/speed , vex::velocityUnits::pct); //(Axis3+Axis4)/2
 // Right.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/2

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
