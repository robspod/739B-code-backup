// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Left                 motor         8               
// Right                motor         2               
// spiner               motor         3               
// spiner2              motor         4               
// lift                 motor         5               
// Leftarm              motor         7               
// Rightarm             motor         9               
// Controller1          controller                    
// Controller2          controller                    
// Vision               vision        20              
// AccelX               accelerometer A               
// AccelY               accelerometer B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;





vex::competition    Competition;
int speed = 2;
int speed2 = 2;
int speedpct = 50;
int wheeldi = 4;
double pi = 3.1415926535;
int circum = pi * wheeldi;
double matlength = 24.5;
int wheelleng = 14;
double disquard = (wheelleng * pi)/4;


void forwardin(int mats){
 double length = mats * matlength;
 double dege = (length / circum) * 360;
 Left.rotateFor(dege,vex::rotationUnits::deg,speedpct,vex::velocityUnits::pct,false);
 Right.rotateFor(dege,vex::rotationUnits::deg,speedpct,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
 Controller1.Screen.clearScreen();
 Controller1.rumble("--");
 Controller1.Screen.print("Calculation complete");
 Controller2.Screen.clearScreen();
 Controller2.rumble("--");
 Controller2.Screen.print("Calculation complete");
}
void backin(int mats){
 double length = mats * matlength;
 double dege = length / circum;
 double deges = dege * -360;
 
 Left.rotateFor(deges,vex::rotationUnits::deg,speedpct,vex::velocityUnits::pct,false); 
 Right.rotateFor(deges,vex::rotationUnits::deg,speedpct,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
}
void turnright(int degs){
  Left.spinFor(degs,degrees);
  Right.spinFor(-degs,degrees);
  
    
}
void turnleft(int degs){
  Left.spinFor(-degs,degrees);
  Right.spinFor(degs,degrees);
    
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
void lifthold(){
    lift.stop(vex::brakeType::hold);
}
void liftup(){
    lift.spin(vex::directionType::fwd,100/speed,vex::velocityUnits::pct);
}
void liftdown(){
    lift.spin(vex::directionType::rev,100/speed,vex::velocityUnits::pct);
}
void up(){
    Rightarm.spin(vex::directionType::fwd,100/speed2,vex::velocityUnits::pct);
    Leftarm.spin(vex::directionType::fwd,100/speed2,vex::velocityUnits::pct);     
}
void down(){
    Rightarm.spin(vex::directionType::rev,100/speed2,vex::velocityUnits::pct);
    Leftarm.spin(vex::directionType::rev,100/speed2,vex::velocityUnits::pct);
}
void stoparms(){
    Rightarm.stop(vex::brakeType::hold);
    Leftarm.stop(vex::brakeType::hold);
}
void janktest(){
  while(true){  
     forwardd();
     liftup();
     up();
     intake();
     wait(300, msec);
     backward();   
     liftdown();
     down();
     outtake();
     vex::task::sleep(300);
     turnright(90);
  }

}
    


void pre_auton( void ) {
   
}



void autonomous( void ) {
 forwardd();
 vex::task::sleep(5000);
 stopleft();
 outtake();
 vex::task::sleep(1000);
 stopall();
 outtake();
 vex::task::sleep(300);
 backward();
 vex::task::sleep(1000);
 stopall();
 stopintake();
 //forwardin(2);
 //backin(3);
 //int abs = true;
// while(abs == true){
//    Vision.takeSnapshot(Vision__ORNAGES);
//            if(Vision.objects[0].exists){
//              if(Vision.objects[0].centerX > 150 && Vision.objects[0].centerX < 166){
//                if(Vision.objects[0].height > 50){
//                  forwardin(1);
//                }
//                
//                
//              }
//              if(Vision.objects[0].centerX < 150){
//                Left.spin(reverse);
//                Right.spin(forward);
//              }
//              if(Vision.objects[0].centerX > 166){
//                int ang = Vision.objects[0].angle;
//                Left.spin(forward);
//                Right.spin(reverse);
//              }
//
//              }
//    wait(100,msec);
//    Left.stop();
//    Right.stop();  
// }  
}



void usercontrol( void ) {
 
  
  while (1) {

        
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
       if(Controller2.ButtonL1.pressing()){
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

          }
          
      
       
       Controller2.ButtonR1.pressed(intake);
       Controller2.ButtonR1.released(stopintake);
       Controller2.ButtonR2.pressed(outtake);
       Controller2.ButtonR2.released(stopintake);
       Controller1.ButtonX.pressed(liftup);
       Controller1.ButtonX.released(lifthold);
       Controller1.ButtonB.pressed(liftdown);
       Controller1.ButtonB.released(lifthold);
       Controller2.ButtonUp.pressed(up);
       Controller2.ButtonUp.released(stoparms);
       Controller2.ButtonDown.pressed(down);
       Controller2.ButtonDown.released(stoparms);
       Left.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/speed , vex::velocityUnits::pct); //(Axis3+Axis4)/2
       Right.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/2
      
      
      vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
      
    }
}



int main() {
    
     
    pre_auton();
   
    
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

                       
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    

}
