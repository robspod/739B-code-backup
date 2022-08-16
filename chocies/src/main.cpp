/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left                 motor         19              
// Right                motor         18              
// spiner               motor         3               
// spiner2              motor         9               
// lift                 motor         5               
// Vision               vision        20              
// lift2                motor         16              
// trystop              bumper        A               
// winch                motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
#define AXIS1 Controller1.Axis1.value();
#define AXIS2 Controller1.Axis2.value();
#define AXIS3 Controller1.Axis3.value();
#define AXIS4 Controller1.Axis4.value();
competition Competition;
int choice = 0;
int speed = 2;
int speed2 = 2;
int speedpct = 100;
int wheeldi = 4;
double pi = 3.1415926535;
int circum = pi * wheeldi;
double matlength = 24.5;
int wheelleng = 14;
double disquard = (wheelleng * pi)/4;
int speedfor = 50;
int batlevel = Brain.Battery.voltage();
int LIFT = 1;



void forwardin(double mats){
 double length = mats * matlength;
 double dege = (length / circum) * 360;
 Left.rotateFor(dege,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false);
 Right.rotateFor(dege,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
 Controller1.Screen.clearScreen();
 Controller1.rumble("--");
 Controller1.Screen.print("Calculation complete");

}
void backin(double mats){
 double length = mats * matlength;
 double dege = length / circum;
 double deges = dege * -360;
 
 Left.rotateFor(deges,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
 Right.rotateFor(deges,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
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
void intake(){
    spiner.spin(vex::directionType::fwd,speedpct,vex::velocityUnits::pct);
    spiner2.spin(vex::directionType::fwd,speedpct,vex::velocityUnits::pct);
}
void outtake(){
    spiner.spin(vex::directionType::rev,speedpct,vex::velocityUnits::pct);
    spiner2.spin(vex::directionType::rev,speedpct,vex::velocityUnits::pct);
}
void stopintake(){
    spiner.stop(vex::brakeType::coast);
    spiner2.stop(vex::brakeType::coast);
}
void intakehold(){
    spiner.stop(vex::brakeType::hold);
    spiner2.stop(vex::brakeType::hold);
}
void lifthold(){
    lift.stop(vex::brakeType::hold);
    lift2.stop(vex::brakeType::hold);

}
void liftup(){
    lift.spin(vex::directionType::rev,100/speed,vex::velocityUnits::pct);
    lift2.spin(vex::directionType::rev,100/speed,vex::velocityUnits::pct);
}
void liftdown(){
    lift.spin(vex::directionType::fwd,100/speed,vex::velocityUnits::pct);
    lift2.spin(vex::directionType::fwd,100/speed,vex::velocityUnits::pct);

}
void winchup(){
  winch.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
}
void winchdown(){
  winch.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
}
void winchstop(){
  winch.stop(vex::brakeType::hold);
}
void winchdeg(int degw){
winch.startRotateFor(-degw,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
}
void janktest(){
  while(true){  
     forwardd();
     liftup();
    
     intake();
     wait(300, msec);
     backward();   
     liftdown();
    
     outtake();
     vex::task::sleep(300);
     turnright(90);
  }

}   
void stack(){
    speedpct = 80; 
    outtake();
    wait(400,msec);
    stopintake();
    wait(500,msec);
    speed = 4;
    liftup();
    wait(1200,msec);
    lifthold();
    forwardd();
    wait(200,msec);
    stopall();
    wait(500,msec);
    backin(1);
    stopall();
    stopintake();
    
}

void pre_auton(void) {
  
  vexcodeInit();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(10,10,100,100);
  Brain.Screen.printAt(15,60, "Small Red");
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(200,10,100,100);
  Brain.Screen.printAt(205,60, "Small Blue");
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(10,150,150,100);
  Brain.Screen.printAt(15,200, "Big Red");
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


void autonomous(void) {
 // if (choice ==0){
 //   Controller1.Screen.clearScreen();
 //   Controller1.Screen.print("Choice is none");

  
  if(choice == 1){
    speed = 3;
    intake();
    forwardin(1.9);
    winchdeg(1080);
    stopintake();
    wait(2000,msec);
    
    backin(1);
    turnright(430);
    forwardd();
    wait(1000,msec);
    stopall();
    liftup();
    wait(3000,msec);
    lifthold();
    backin(1);
    liftdown();
    wait(3000,msec);
    lifthold();

    

   

  }
  if(choice == 2){
     speed = 3;
     intake();
    forwardin(1.8);
    winchdeg(1080);
    wait(2000,msec);
    stopintake();
    backin(1);
    turnleft(430);
    forwardd();
    wait(1000,msec);
    stopall();
    liftup();
    wait(3500,msec);
    lifthold();
    backin(.9);
    liftdown();
    wait(3000,msec);
    lifthold();
  
  
  
  }
  if(choice == 3){
    speedfor = 40;
    lifthold();
    intake();
    forwardin(0.8);
    speed = 1;
   
    forwardin(0.5);
    intake();
    forwardin(.5);
    speed = 2;
    turnleft(455);
    winchdeg(1080);
    forwardin(1.7);
    wait(1,sec);
   
    speedpct = 80;
    stopintake();
    wait(500,msec);
    outtake();
    wait(300,msec);
    stopintake();
    speed = 2;
    liftup();
    
    wait(2000,msec);
    
    speed =5;

    liftup();
    wait(1000,msec);
    lifthold();
    

    forwardd();
    wait(200,msec);
    stopall();
    speedfor = 25;
    wait(500,msec);
    backward();
    wait(1000,msec);
    stopall();
    stopintake();
    winchstop();
  }
  if(choice == 4){
    speedfor = 40;
    lifthold();
    intake();
    forwardin(0.8);
    speed = 1;
   
    forwardin(0.5);
    intake();
    winchdeg(1080);
    forwardin(.5);
    speed = 2;
    turnright(460);
    
    forwardd();
    wait(2.2,sec);
    stopall();
   
    speedpct = 80;
    stopintake();
    wait(500,msec);
    outtake();
    wait(200,msec);
    stopintake();
    speed = 2;
    liftup();
    
    wait(2000,msec);
    
    speed =5;

    liftup();
    wait(1000,msec);
    lifthold();
    

    forwardd();
    wait(200,msec);
    stopall();
    speedfor = 25;
    wait(500,msec);
    backward();
    wait(1000,msec);
    stopall();
    stopintake();
    winchstop();
    liftdown();
    wait(1000,msec);
    lifthold();
    
  }


}



void usercontrol(void) {
  while (1) {
     
      
       if(Controller1.Axis2.value() == 0){
          lift.stop(vex::brakeType::hold);
       } 
       if(Controller1.ButtonLeft.pressing()){
         if(Controller1.ButtonUp.pressing()){
           stack();
         }
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
                Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print(speed);
                wait(100,msec);
            }
        }
        if(Controller1.ButtonL2.pressing()){
           if(Controller1.ButtonR2.pressing()){
                speed = speed + 1;
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
                Controller1.Screen.clearScreen();
                Controller1.Screen.setCursor(1, 1); 
                Controller1.Screen.print(speed);
                wait(100,msec);
            }
            
        }
     
       /*if(Controller2.ButtonL1.pressing()){
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
            
        }
        Vision.takeSnapshot(Vision__ORNAGES);
        if(Vision.objects[0].exists){
          if(Vision.objects[0].centerX > 150 && Vision.objects[0].centerX < 166){
            Left.spin(forward);
            Right.spin(forward);
          }
          if(Vision.objects[0].centerX < 150){
            Left.spin(reverse);
            Right.spin(forward);
          }
          if(Vision.objects[0].centerX > 166){
            Left.spin(forward);
            Right.spin(reverse);
          }

          }*/
          
       if (Controller1.Axis2.position(percent) > 50){
         speed = 4;
         Controller1.Screen.clearScreen();
         Controller1.Screen.setCursor(1,1);
         Controller1.Screen.print(speed);
       }
       if(speed == 1 or speed == 2 or speed == 3){
        LIFT = 0;
        
       } 
       else{
         LIFT = 1;
       }
       
       Controller1.ButtonUp.pressed(winchup);
       Controller1.ButtonUp.released(winchstop);
       Controller1.ButtonDown.pressed(winchdown);
       Controller1.ButtonDown.released(winchstop);
       Controller1.ButtonR1.pressed(intake);
       Controller1.ButtonR1.released(stopintake);
       Controller1.ButtonR2.pressed(outtake);
       Controller1.ButtonR2.released(stopintake);
       Controller1.ButtonX.pressed(liftup);
       Controller1.ButtonX.released(lifthold);
       Controller1.ButtonB.pressed(liftdown);
       Controller1.ButtonB.released(lifthold);
      /* Controller2.ButtonUp.pressed(up);
       Controller2.ButtonUp.released(stoparms);
       Controller2.ButtonDown.pressed(down);
       Controller2.ButtonDown.released(stoparms);*/
       lift.spin(vex::directionType::fwd, (Controller1.Axis2.value() + Controller1.Axis1.value())*LIFT , vex::velocityUnits::pct); //(Axis3+Axis4)/2
       lift2.spin(vex::directionType::fwd, (Controller1.Axis2.value() + Controller1.Axis1.value())*LIFT , vex::velocityUnits::pct); //(Axis3+Axis4)/2

      // main wheel drive
       Left.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/speed , vex::velocityUnits::pct); //(Axis3+Axis4)/2
       Right.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/2
      // vibrates controller when motor temp is high
     /* if (Right.temperature(percent) >  50 or Left.temperature(percent) > 50){
        Controller1.rumble("-");
        Controller1.Screen.setCursor(1,1);
        Controller1.Screen.clearScreen();
        Controller1.Screen.print(Right.temperature(percent));
        Controller1.Screen.setCursor(2,1);
        Controller1.Screen.print(Left.temperature(percent));
      }*/
      
      vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
      
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
