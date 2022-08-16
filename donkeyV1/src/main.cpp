/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Thu Jan 20 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// Controller1          controller                    
// lift2                motor         15              
// tray                 motor         12              
// claw                 motor         18              
// lift1                motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

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
void liftstop(){
  lift1.stop(hold);
  lift2.stop(hold);
}
void clawopen(){
  claw.spin(forward);
}
void clawclose(){
  claw.spin(reverse);
}
void clawstop(){
  claw.stop(hold);
}

void trayup(){
  tray.setVelocity(100, percent); 
  tray.spin(forward);
}
void traydown(){
  tray.setVelocity(100, percent); 
  tray.spin(reverse);
}
void trayhold(){
  tray.stop(hold);
}
void traystop(){
  Tray1.stop(brake);
  Tray2.stop(brake);
}
void move(int length){
  if (length<<12){
    Drivetrain.driveFor(forward, length, inches); 
  }else if (length>=12){
    Drivetrain.driveFor(forward, length, inches); 
  }
}
void rights(int degs){
  Drivetrain.turnFor(right,degs, degrees); 
}
void lefts(int degs){
  Drivetrain.turnFor(left, degs, degrees); 
}

int choices = 0;

void pre_auton(void) {
  vexcodeInit();
  candle.on(); 

  Brain.Screen.clearScreen();
  Brain.Screen.setFont(monoS);
  Brain.Screen.print("running intercourse");

  int i=1;
  while(i<=4){
    Brain.Screen.drawCircle(96*i,70,30,black);
    i+=1;
  }
    i=1;
  while(i<=2){
    Brain.Screen.drawCircle(96 + 96*i,150,30, black);
    i+=1;
  }

  Brain.Screen.setFont(propM);
  Brain.Screen.setFillColor(black);
  Brain.Screen.setCursor(4,9);
  Brain.Screen.print(" QR");
  Brain.Screen.setCursor(4,19);
  Brain.Screen.print("QL");
  Brain.Screen.setCursor(4,29);
  Brain.Screen.print("ER");
  Brain.Screen.setCursor(4,38);
  Brain.Screen.print(" EL");
  Brain.Screen.setCursor(8,19);
  Brain.Screen.print("SK");
  Brain.Screen.setCursor(8,29);
  Brain.Screen.print("No");

  Brain.Screen.setFont(propL);
  Brain.Screen.setCursor(8,2);

  while (choices == 0){
  if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 66 and Brain.Screen.yPosition() > 40 and Brain.Screen.xPosition() < 126 and Brain.Screen.yPosition() < 70){
    choices = 1;
    Brain.Screen.clearScreen();
    Brain.Screen.print("right side qualification auton");
  } else if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 162 and Brain.Screen.xPosition() < 222 and Brain.Screen.yPosition() > 40 and Brain.Screen.yPosition() < 70 ){
    choices = 2;  
    Brain.Screen.clearScreen();
    Brain.Screen.print("left side qualification auton");
  } else if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 258 and Brain.Screen.xPosition() < 318 and Brain.Screen.yPosition() > 40 and Brain.Screen.yPosition() < 70 ){
    choices = 3;  
    Brain.Screen.clearScreen();
    Brain.Screen.print("right side elimination auton");
  } else if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 354 and Brain.Screen.xPosition() < 414 and Brain.Screen.yPosition() > 40 and Brain.Screen.yPosition() < 70 ){
    choices = 4;  
    Brain.Screen.clearScreen();
    Brain.Screen.print("left side elimination auton");
  } else if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 162 and Brain.Screen.xPosition() < 222 and Brain.Screen.yPosition() > 120 and Brain.Screen.yPosition() < 189 ){
    choices = 5;  
    Brain.Screen.clearScreen();
    Brain.Screen.print("skills auton");
  } else if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 258 and Brain.Screen.xPosition() < 318 and Brain.Screen.yPosition() > 120 and Brain.Screen.yPosition() < 180 ){
    choices = 6;  
    Brain.Screen.clearScreen();
    Brain.Screen.print("nope on the auton");
    }
  }
}



void autonomous(void) {
  if(choices==1){         //right qualification
      //rq
  }else if (choices==2){  //left qualification
      //lq
  }else if (choices==3){  //right elemination
      //re
  }else if (choices==4){  //Left elimination
      //le
  }else if (choices==5){  //skills auton
    Drivetrain.setDriveVelocity(75, percent); 
    liftup();
    wait(.8,sec);
    liftdown();
    wait(1,sec);
    liftstop();
    move(-13);
    rights(39);
    move(144);

   
   
   
   
   
   /* liftup();
    wait(.8,sec);
    liftdown();
    wait(1,sec);
    liftstop();
    rights(88);
    clawopen();
    move(40);
    Drivetrain.setDriveVelocity(30,percent);
    move(10);
    clawclose();
    wait(1,sec);
    clawstop();
    liftup();
    lefts(140);
    move(55);
    clawopen();
    wait(1,sec);
    move(-20);
    rights(60);
    Drivetrain.setDriveVelocity(100,percent);
    move(70);
    Drivetrain.setDriveVelocity(30,percent);
    liftdown();
    move(-15);
    wait(1.25,sec);
    liftstop();
    rights(78);
    move(20);
    clawclose();
    wait(1,sec);
    liftup();
    rights(135);
    liftstop();
    Drivetrain.setDriveVelocity(100,percent);
    move(58);
    clawopen();
    wait(1,sec);
    move(-20);
    clawclose();
*/
    
  }else if (choices==6){  //no auton
      //no
    }
}



void usercontrol(void) {
  Drivetrain.setDriveVelocity(100, percent); 
  while (1) {
    Controller1.ButtonUp.pressed(clawopen);
    Controller1.ButtonUp.released(clawstop);
    Controller1.ButtonX.pressed(clawclose);
    Controller1.ButtonX.released(clawstop);
    
    Controller1.ButtonL1.pressed(trayup);
    Controller1.ButtonL2.pressed(traydown);
    Controller1.ButtonL1.released(trayhold);
    Controller1.ButtonL2.released(traystop);

    Controller1.ButtonR1.pressed(liftup);
    Controller1.ButtonR2.pressed(liftdown);
    Controller1.ButtonR1.released(liftstop);
    Controller1.ButtonR2.released(liftstop);
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

