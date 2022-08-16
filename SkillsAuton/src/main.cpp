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
// Controller1          controller                    
// lift2                motor         15              
// lift1                motor         17              
// tray2                motor         12              
// claw                 motor         18              
// RangeFinder          sonar         G, H            
// GPS21                gps           21              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


competition Competition;

//postioning systum 



//lift controls
void liftdown(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spin(reverse); 
  lift2.spin(reverse); 
}
  void liftup(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spin(forward);
  lift2.spin(forward); 
}
void lifthold(){
  lift1.stop(brake);
  lift2.stop(brake);
}
//claw controls
void clawtoggle(){
  claw.spinFor(forward, 45, degrees); 
}
void clawopen(){
  claw.spinFor(forward, 45, degrees);
  wait(0.6, sec);
  claw.spinFor(forward, 45, degrees);
}
void clawclose(){
  claw.spin(forward);
}
void clawwstop(){
  claw.stop(hold);
}
//tray controls
void trayup(){
  tray2.setVelocity(100, percent);
  tray2.spin(forward);
}
void traydown(){
  tray2.setVelocity(100, percent);
  tray2.spin(reverse);
}
void trayup50(){
  tray2.setVelocity(50, percent);
  tray2.spin(forward);
}
void traydown50(){
  tray2.setVelocity(50, percent); 
  tray2.spin(reverse);
}
void trayhold(){
  tray2.stop(hold);
}
void traystop(){
  tray2.stop(brake);
}



// Atoun drive control
void move(int ins){
Drivetrain.driveFor(forward, ins, inches); 
Controller1.Screen.clearScreen();
Controller1.Screen.print(RangeFinder.distance(inches));
if(RangeFinder.distance(inches) <= 4){
  Drivetrain.stop();
}
}

// atuon turn controls
void rights(int degs){
  Drivetrain.turnFor(right,degs, degrees); 
}
void lefts(int degs){
  Drivetrain.turnFor(left, degs, degrees); 
}



void pre_auton(void) {
  vexcodeInit();// <-- don't touch
  // put stuff in here is you want it to be run right as soon as the bot is turned on 
  lifthold();
}



void autonomous(void) {


 //Mitchell Auton 
 Drivetrain.setDriveVelocity(100, percent); 
  traydown();
  wait(0.65,sec);
  trayhold();
  move(-7);
  trayup();
  wait(0.9,sec);
  trayhold();
  clawtoggle();//close
  rights(87);
  Drivetrain.setDriveVelocity(100, percent);
  move(55);

 //Stack Middle Left 
  liftup();
  wait(1.5,sec);
  lifthold();
  rights(140);
  Drivetrain.setDriveVelocity(60, percent);
  move(53);
  clawtoggle();//open

 //Grab Middle Right Goal
  wait(.5,sec);
  move(-16);
  Drivetrain.turnToHeading(0,degrees);
  liftdown();
  Drivetrain.setDriveVelocity(75, percent);
  move(-55);
  wait(0.2,sec);
  move(8);
  lifthold();
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.turnToHeading(90,degrees);
  Drivetrain.setDriveVelocity(50, percent);
  move(30);
  wait(600,msec);
  clawtoggle();
  move(-10);
  liftup();

 //Stack Middle Right Goal
  lefts(153);
  lifthold();
  Drivetrain.setDriveVelocity(60, percent);
  move(61);
  clawtoggle();//Open

 //Middle Goal to Top Left Corner
  move(-10);
  liftdown();
  move(-15);
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.turnToHeading(40,degrees);
  lifthold();
  move(105);
  Drivetrain.setDriveVelocity(75, percent);
  move(-15);
  liftup();
  rights(90);
  lifthold();
  move(15);
  liftdown();
  wait(1,sec);
  lifthold();


}





void usercontrol(void) {
  // drive train speed
  Drivetrain.setDriveVelocity(100, percent); 
  while (1) {
    //tray button control
    Controller1.ButtonL1.pressed(trayup);
    Controller1.ButtonL2.pressed(traydown);
    Controller1.ButtonL1.released(trayhold);
    Controller1.ButtonL2.released(trayhold);
    //lift button control
    Controller1.ButtonR1.pressed(liftup);
    Controller1.ButtonR2.pressed(liftdown);
    Controller1.ButtonR1.released(lifthold);
    Controller1.ButtonR2.released(lifthold);
    //claw button control
    Controller1.ButtonY.pressed(clawopen);
    Controller1.ButtonA.pressed(clawclose);;
    Controller1.ButtonA.released(clawwstop);
    // some sort of resorse management time thing so leave it alone
    wait(20, msec); // <---  don't touch
    //  ^
    //  |  leave alone
  }
}

// DO NOT TOUCH YOU NEVER NEED TO TOUCH THIS NEVER
int main() {
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // HANDS OFF DO NOT TOUCH
  
  pre_auton();
  // I SAID HANDS OFF
  
  while (true) {
    wait(100, msec);
  }
}

