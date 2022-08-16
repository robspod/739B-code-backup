#pragma once
#include <vex.h>

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
  while( Encoderleft.velocity(dps)  > 1){
  }
  Drivetrain.stop();
}

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









