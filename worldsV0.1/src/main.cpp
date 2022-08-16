/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Mon Apr 18 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 3, 4      
// ring                 motor         9               
// tray                 motor         11              
// claw                 motor         12              
// lift                 motor         13              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Competition;

int balanceGo;
int clawSense;

void intake(){
  ring.spin(forward,75,pct);
}
void intake(int insped){
  ring.spin(forward,insped,pct);
}
void outtake(){
  ring.spin(reverse,50,pct);
}
void outtake(int insped){
  ring.spin(reverse,insped,pct);
}
void stoptake(){
  ring.stop(brake);
}
void trayup(){
  tray.spinToPosition(360,degrees);
} 
void traydown(){
  tray.spinToPosition(610,degrees);
}

//enter callback functions here
//claw control
void clawToggle(){
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
//tray control
void trayToggle(){
  if(tray.position(degrees)<400){
    tray.spinToPosition(660, degrees, false);
  }else if (tray.position(degrees)>=400) {
    tray.spinToPosition(370, degrees);
    tray.stop(hold);
  }
}
void trayStop(){
  tray.stop(brake);
}
//lift control

//ring control

//balance control
void balanceToggle(){
  if(balanceGo==0){
    balanceGo=1;
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("balance");
  }else if(balanceGo==1){
    balanceGo=2;
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("lock");
  }else if(balanceGo==2){
    balanceGo=0;
    Controller1.rumble(".");
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("off");
  }
}



void pre_auton(void){

}

void Autonomous(void){


}




void usercontrol(void) {


  while(1){
    Controller1.ButtonA.pressed(intake);
    Controller1.ButtonA.released(stoptake);
    Controller1.ButtonB.pressed(outtake);
    Controller1.ButtonB.released(stoptake);
    Controller1.ButtonR1.pressed(trayup);
    Controller1.ButtonR2.released(traydown);
    Controller1.ButtonL1.pressed(clawToggle);
    Controller1.ButtonL2.pressed(trayToggle);
    Controller1.ButtonUp.pressed(balanceToggle);


  }
}

// DO NOT TOUCH YOU NEVER NEED TO TOUCH THIS NEVER
int main() {
  //thread_local task(task1);
  Competition.autonomous(Autonomous);
  Competition.drivercontrol(usercontrol);
  // HANDS OFF DO NOT TOUCH
  
  pre_auton();
  // I SAID HANDS OFF
  
  while (true) {
    wait(100, msec);
  }
}