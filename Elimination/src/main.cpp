// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// Motor11              motor         12              
// LEDA                 led           A               
// claw                 motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// Motor11              motor         12              
// LEDA                 led           A               
// claw                 motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// Motor11              motor         12              
// LEDA                 led           A               
// claw                 motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// Motor11              motor         12              
// LEDA                 led           A               
// claw                 motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// Motor11              motor         12              
// LEDA                 led           A               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// Motor11              motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor18              motor         15              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
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
// Motor18              motor         15              
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Motor3               motor         17              
// Motor11              motor         12              
// LEDA                 led           A               
// claw                 motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


competition Competition;
//claw
void clawdown(){
  Motor3.setVelocity(100, percent); 
  Motor3.spin(reverse); 
}
  void clawup(){
  Motor3.setVelocity(100, percent); 
  Motor3.spin(forward); 
}
void clawstop(){
  Motor3.stop(hold);
}
void clawopen(){
  claw.spin(forward);
}
void clawclose(){
  claw.spin(reverse);
}
void clawwstop(){
  claw.stop(hold);
}
//arm
void armup(){
  Motor18.setVelocity(100, percent); 
  Motor11.setVelocity(100, percent);
  Motor18.spin(forward);
  Motor11.spin(forward);
}
void armdown(){
  Motor18.setVelocity(100, percent); 
  Motor11.setVelocity(100, percent);
  Motor18.spin(reverse);
  Motor11.spin(reverse);
}
void aarmup(){
  Motor18.setVelocity(50, percent); 
  Motor11.setVelocity(50, percent);
  Motor18.spin(forward);
  Motor11.spin(forward);
}
void aarmdown(){
  Motor18.setVelocity(50, percent);
  Motor11.setVelocity(50, percent); 
  Motor18.spin(reverse);
  Motor11.spin(reverse);
}
void armhold(){
  Motor18.stop(hold);
  Motor11.stop(hold);
}
void armstop(){
  Motor18.stop(brake);
  Motor11.stop(brake);
}
void move(int ins){
  Drivetrain.driveFor(forward, ins, inches); 
}
void rights(int degs){
  Drivetrain.turnFor(right,degs, degrees); 
}
void lefts(int degs){
  Drivetrain.turnFor(left, degs, degrees); 
}



void pre_auton(void) {
  
  vexcodeInit();
  LEDA.on(); 



  int choice = 0;
 Brain.Screen.setFont(propXXL); 
 //Brain.Screen.printAt(int32_t x, int32_t y, bool bOpaque, )
 
 
 
 
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
    if (Controller1.ButtonX.pressing()){
     choice += 10; }
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
      wait(50,msec);

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
      wait(50,msec);
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
      wait(50,msec);
      }
    }
  }
}



void autonomous(void) {
  Drivetrain.setDriveVelocity(100, percent); 
  armdown();
  move(23);
  move(-16);
  armstop();
  rights(120);
  clawopen();
  move(-40);
  clawstop();
  aarmup();
  wait(1.4,sec);
  armhold();
  move(30);
  Drivetrain.setDriveVelocity(50, percent);
  lefts(38);
  move(-49);
  wait(0.8,sec); 
  Drivetrain.setDriveVelocity(150, percent);
  move(45);
  move(-5);
  move(9);
 
 
 
 
 
 
 
 
 
 
 
/* move(30);
  rights(137);
  move(32);
  clawclose();
  wait(0.6,sec);
  clawstop();
  move(-48);
*/

  
 
 /* move(-5);
  armdown();
  clawopen();
  wait(0.65,sec);
  armstop();
  clawstop();
  move(-43);
  aarmup();
  wait(0.4,sec);
  armhold();
  move(20);
  rights(120);
  Drivetrain.setDriveVelocity(30, percent);
  move(35);
  clawclose();
  wait(500,msec);
  clawwstop();
  Drivetrain.setDriveVelocity(100, percent);
  clawup();
  wait(500,msec);
  clawstop();
  move(-50);

*/


 
 


 
  
}





void usercontrol(void) {
  Drivetrain.setDriveVelocity(100, percent); 
  while (1) {
    Controller1.ButtonL1.pressed(armup);
    Controller1.ButtonL2.pressed(armdown);
    Controller1.ButtonL1.released(armhold);
    Controller1.ButtonL2.released(armstop);

    Controller1.ButtonR1.pressed(clawup);
    Controller1.ButtonR2.pressed(clawdown);
    Controller1.ButtonR1.released(clawstop);
    Controller1.ButtonR2.released(clawstop);
    Controller1.ButtonY.pressed(clawopen);
    Controller1.ButtonY.released(clawwstop);
    Controller1.ButtonA.pressed(clawclose);
    Controller1.ButtonA.released(clawwstop);

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
