#include "vex.h"

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
// Drivetrain           drivetrain    5, 13, 20       
// button               bumper        A               
// green1               led           B               
// yellow1              led           C               
// yellow2              led           D               
// red1                 led           E               
// rear                 led           H               
// flashlight           led           G               
// Inertial6            inertial      6               
// Vision               vision        19              
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// A global instance of competition
competition Competition;
bool redball = true;
bool blueballs = true;
bool fun = true;
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
void turnright(int degss){
Drivetrain.turnFor(right, degss, degrees);
}

      

void turnleft(int degs){
  Drivetrain.turnFor(left, degs, degrees);

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
void armsout(){
  arm1.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  arm2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  
}
void armsin(){
  arm1.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  arm2.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);

 
}
void armstop(){
  arm1.stop(vex::brakeType::brake);
  arm2.stop(vex::brakeType::brake);
  middle.stop(vex::brakeType::brake);
  

}
void outback(){
  top2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  bottom.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  topback.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
}
void outtop(){
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
void specialsort(){
  middle.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  bottom.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  topback.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
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
/*void move(double dist ){
  Drivetrain.driveFor(dist,inches, false);
  //wait(dist /10,sec);
  //Drivetrain.stop(); 
}
void move_(double dist ){
  Drivetrain.driveFor(-dist,inches, false);
  wait(dist/10,sec);
  Drivetrain.stop(); 
}*/
void stops(){
    Drivetrain.setStopping(brake);
   Drivetrain.stop(); 
}
void move(double dist ){
  fun = true;
 Drivetrain.driveFor(dist,inches);
  while(Drivetrain.isMoving() && fun == true){
    if(button.pressing()){
      stops();
      fun = false;
    }
    
  
  }
  


     
   

 
}

  


/*void burnout(){
  Left.stop(vex::brakeType::hold);
  Right.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
}*/
void pre_auton(void) {
  
  
  
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.print("Calabrating...");
  Inertial6.calibrate(); 

  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(10,10,100,100);
  Brain.Screen.printAt(15,60, "1 point");
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(200,10,100,100);
  Brain.Screen.printAt(205,60, "Small Blue");
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(10,150,150,100);
  Brain.Screen.printAt(15,200, "2 point ");
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(200,150,150,100);
  Brain.Screen.printAt(205,200, "Big Blue");

  while(choice < 1){
  if(Controller1.ButtonX.pressing()){
    choice = 10;
  }
  if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 10 and Brain.Screen.yPosition() > 10 and Brain.Screen.xPosition() < 110 and Brain.Screen.yPosition() < 110){
  
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(100,100);
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Small Red");
      choice = 1;

  }
  if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 200 and Brain.Screen.yPosition() > 10 and Brain.Screen.xPosition() < 310 and Brain.Screen.yPosition() < 110){
  
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(100,100);
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Small Blue");
      choice = 2;
  }
     if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 10 and Brain.Screen.yPosition() > 150 and Brain.Screen.xPosition() < 110 and Brain.Screen.yPosition() < 270){
  
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(100,100);
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Big Red");
      choice = 3;

  }
  if(Brain.Screen.pressing() and Brain.Screen.xPosition() > 200 and Brain.Screen.yPosition() > 150 and Brain.Screen.xPosition() < 310 and Brain.Screen.yPosition() < 270){
  
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(100,100);
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Big Blue");
      choice = 4;
  }
  
  }
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(propXXL);
    Brain.Screen.setFillColor(white);
    Brain.Screen.drawRectangle(0,0,480,272);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(75,136,"Men In Black");


  


}
/*void turnto(int deges){
  Drivetrain.turnToHeading(deges, deg);
}
//void notmove(){
  //if(Drivetrain.
//}
/---------------------------------------------------------------------------/
/                                                                           /
/                              Autonomous Task                              /
/                                                                          /
/  This task is used to control your robot during the autonomous phase of   /
/  a VEX Competition.                                                       /
/                                                                           /
/  You must modify the code to add your own robot specific commands here.   /
/---------------------------------------------------------------------------*/

void autonomous(void) {
Drivetrain.setDriveVelocity(60, percent); 
Drivetrain.setTurnVelocity(30, percent); 
 // goal 1 & 2
  Inertial6.calibrate();
  outtop();
  wait(.3,sec);
  spinstop();
  armsin();
  turnleft(135);
  move(30);
  turnleft(90);
  armstop();
  move(20);
  outtop();
  wait(0.5,sec);
  spinstop();
 // goal 3
  move(-20);

  /*spinstop();
  armstop();
  armsout();
  wait(0.5,sec);
  armstop();
  move(-11);
  armsin();
  wait(0.5,sec);
  outtop();
  armstop();
  wait(2,sec);
  spinstop();

  //goal 2
  armstop();
  turnright(139);
  armsin();
  move(47);
  wait(0.2,sec);
  armstop();
  armsin();
  wait(0.5,sec);
  turnleft(100);
  armsin();
  move(10);
  wait(0.5,sec);
  

  
  wait(0.25,sec);
  outback();
  redball = true;
  while(redball == true){
  Vision.takeSnapshot(Vision__REDS);
    if  (Vision.objects[0].width >= 200){
      redball = false;
    }
  }
  spinstop();
  armsin();
  wait(0.5,sec);
  move(-10);
 
  armstop();*/


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
  
Controller1.Screen.clearScreen();
Controller1.Screen.setCursor(1, 1); 
//Controller1.Screen.print(Drivetrain.heading(degrees) );
Controller1.Screen.setCursor(2, 1); 
Controller1.Screen.print(Brain.Battery.capacity());
   if (Brain.Battery.capacity() >= 75)
  {
   green1.on(); 
  }
  else{
    green1.off();
  }
   if (Brain.Battery.capacity() <= 75 && Brain.Battery.capacity() >= 50 )
  {
   yellow1.on(); 
  }
  else{
    yellow1.off();
  }
   if (Brain.Battery.capacity() <=50 && Brain.Battery.capacity() >=25 )
  {
   yellow2.on(); 
  }
  else{
    yellow2.off();
  }
   if (Brain.Battery.capacity() <= 25)
  {
   red1.on(); 
  }
  else{
    red1.off();
  }
  //int abs = false;
  //while(abs == true){
    //Vision.takeSnapshot(Vision__REDS);
    //int ang = Vision.objects[0].angle;
    //int dis = 18 * cos(45);
    //Controller1.Screen.clearScreen();
    //Controller1.Screen.print(dis);           
 //}  
if(button.pressing() ){
 Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print("Stop");
                Controller1.rumble("-");

     
   }
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
  if(choice == 1 || choice == 3){
    if (button.pressing()){

    }


  }
  
  
  
  
  
  Controller1.ButtonR1.pressed(armsin);
  Controller1.ButtonR1.released(armstop);
  Controller1.ButtonR2.pressed(armsout);
  Controller1.ButtonR2.released(armstop);
  Controller1.ButtonA.pressed(outback);
  Controller1.ButtonA.released(spinstop);
  Controller1.ButtonX.pressed(outtop);
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

