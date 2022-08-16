
#include <vex.h>

double diam = 2.75;
double pi = 3.141592653;
double circum = pi * diam;

//claw
extern void liftdown(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spinToPosition(0, degrees,false); 
  lift2.spinToPosition(0, degrees); 
}
extern void liftdownF(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spinToPosition(0, degrees,false); 
  lift2.spinToPosition(0, degrees, false); 
}
extern void liftto(int amount){
  lift1.setVelocity(100, percent);
  lift2.setVelocity(100, percent); 
  lift1.spinToPosition((amount), degrees, false);
  lift2.spinToPosition((amount), degrees); 
}
extern void lift(int amount){
  lift1.setVelocity(100, percent);
  lift2.setVelocity(100, percent); 
  lift1.spinToPosition((amount*12), degrees, false);
  lift2.spinToPosition((amount*12), degrees); 
}
extern void liftF(int amount){
  lift1.setVelocity(100, percent);
  lift2.setVelocity(100, percent); 
  lift1.spinToPosition((amount*12), degrees, false);
  lift2.spinToPosition((amount*12), degrees, false); 
}
extern void liftstop(){
  lift1.stop(hold);
  lift2.stop(hold);
}
extern void moveS(int length, int speed){
  Drivetrain.driveFor(forward, length, inches, speed, rpm, false);
  wait(750,msec);
  while( Eleft.velocity(dps)  > 1){
  }
  Drivetrain.stop(hold);
}
extern void forin(double length){
  Drivetrain.setStopping(brake); 
  bool i = true;
 double dege = (length / circum) * 360;
 Drivetrain.drive(fwd,600,rpm);
 while(i==true){
 if (((Eleft+Eright)+0.01/2) >= dege){
   Drivetrain.stop(brake);
    i=false;
 }
 Drivetrain.stop(brake);
 }
}
/*
extern void forin(double length,directionType dir){
 double dege = (length / circum) * 360;
 Drivetrain.drive(dir,200,rpm);
 if (((Eleft+Eright)/2) >= dege){
   Drivetrain.stop(hold);
 }
}
extern void forin(double length,directionType dir, double velocity, velocityUnits units){
 double dege = (length / circum) * 360;
 Drivetrain.drive(dir,velocity,units);
 if (((Eleft+Eright)/2) >= dege){
   Drivetrain.stop(hold);
 }
}/*
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

*/
//claw
extern void clawtoggle(){claw.spinFor(forward, 90, degrees);}
extern void clawopen(){claw.spinFor(forward, 90, degrees);wait(0.5,sec);claw.spinFor(forward, 90, degrees);}
extern void clawclose(){claw.spin(forward);}
extern void clawstop(){claw.stop(hold);}
extern void clawin(){claw.spinFor(forward, 90, degrees, false);}
//tray
extern void traydown(){tray2.setVelocity(100, percent);tray2.spinToPosition(-985, degrees);}
extern void traydownN(){tray2.setVelocity(100, percent);tray2.spinToPosition(-985, degrees,false);}
extern void trayhalf(){tray2.setVelocity(100, percent);tray2.spinToPosition(-750, degrees, false);}
extern void trayup(){tray2.setVelocity(100, percent);tray2.spinToPosition(-240, degrees);}
extern void downtray(){tray2.spin(reverse,100,pct);}
extern void uptray(){tray2.spin(forward,100,pct);}
extern void trayhold(){tray2.stop(hold);}
extern void traystop(){tray2.stop(brake);}
//drive
extern void moveT(int length, int speed){
  Drivetrain.driveFor(forward, length, inches, speed, rpm, false);
  wait(length/(0.2*speed), sec);
  Drivetrain.stop(brake);
  }
extern void move(int ins, int speed){Drivetrain.driveFor(forward, ins, inches, speed, rpm); }
extern void rights(int degs, int speed){Drivetrain.turnFor(right, degs, degrees, speed, rpm); }
extern void lefts(int degs, int speed){Drivetrain.turnFor(left, degs, degrees, speed, rpm); }
extern void turnto(int degs){Drivetrain.turnToHeading(degs, degrees);}
extern void speed(int speeds){Drivetrain.setDriveVelocity(speeds, percent);}