/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Wed Mar 09 2022                                           */
/*    Description:  Program controlling worlds robot                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// leftD                motor_group   17, 12          
// rightD               motor_group   13, 2           
// leftE                encoder       A, B            
// rightE               encoder       C, D            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
double pi=3.141592653;
using namespace vex;
competition Competition;

int balanceGo=0;
int conveyorGo=0;

void pre_auto (void){
  //reset all encoders
  leftE.resetRotation();
  rightE.resetRotation();
  leftD.resetRotation();
  rightD.resetPosition();
  claw.resetPosition();
  lift.resetPosition();
  tray.resetPosition();
  ring.resetPosition();
  magic.calibrate();
  lift.setStopping(hold);
  wait(1, sec);//actually necessary
  vexcodeInit();//start claw and drive tasks
  Controller1.rumble("..");//inform user that we are clear for take off
}
 
//enter callback functions here
void clawToggle(){ //claw control
  if(claw.position(degrees)<50){
    claw.spinToPosition(120, degrees);
    claw.stop(hold);
  }else if (claw.position(degrees)>=50) {
    claw.spinToPosition(0, degrees, false);
  }
}
void clawStop(){
  claw.stop(brake);
}
void trayToggle(){ //tray control
  if(tray.position(degrees)<500){
    tray.spinToPosition(660, degrees, false);
  }else if (tray.position(degrees)>500) {
    tray.spinToPosition(400, degrees);
    tray.stop(hold);
  }
}
void trayStop(){
  tray.stop(brake);
}
//lift control

//ring control
void ringOut(){
  ring.spin(reverse, 100, pct);
}
void ringStop(){
  ring.stop(coast);
}
void ringToggle(){
  if(conveyorGo==0){
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("conveyor on");
    wait(5,msec);
    conveyorGo=1;
  }else if(conveyorGo==1){
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("conveyor off");
    wait(5,msec);
    conveyorGo=0;
  }
}
void balanceToggle(){ //balance control
  if(balanceGo==0){
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print("balance");
    wait(5,msec);
    balanceGo=1;
  }else if(balanceGo==1){
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print("lock");
    wait(5,msec);
    balanceGo=2;
  }else if(balanceGo==2){
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print("off");
    wait(5,msec);
    balanceGo=0;
  }
}

void auton (void){
  
}

void driver (void){
  while(1){
  Controller1.ButtonL1.pressed(clawToggle);
  Controller1.ButtonL2.pressed(trayToggle);
  Controller1.ButtonUp.pressed(ringToggle);
  Controller1.ButtonDown.pressed(ringOut);
  Controller1.ButtonDown.released(ringStop);
  Controller1.ButtonRight.pressed(balanceToggle);
  lift.spin(forward,Controller1.Axis2.position() ,pct);
  }
}

int main() {
  pre_auto();
  Competition.autonomous(auton);
  Competition.drivercontrol(driver);
  while(1){wait(20,msec);}
}