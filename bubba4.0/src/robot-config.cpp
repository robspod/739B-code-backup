#include "vex.h"
using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor claw = motor(PORT15, ratio36_1, 1);
motor lift = motor(PORT13, ratio36_1, 1);
motor tray = motor(PORT6, ratio36_1);
motor ring = motor(PORT18, ratio6_1, 0);
motor leftDMotorA = motor(PORT4, ratio18_1, 1);
motor leftDMotorB = motor(PORT5, ratio18_1, 0);
motor_group leftD = motor_group(leftDMotorA, leftDMotorB);
motor rightDMotorA = motor(PORT16, ratio18_1, 1);
motor rightDMotorB = motor(PORT17, ratio18_1, 0);
motor_group rightD = motor_group(rightDMotorA, rightDMotorB);
encoder rightE = encoder(Brain.ThreeWirePort.C);
encoder leftE = encoder(Brain.ThreeWirePort.G);
inertial magic = inertial(PORT7);
line LineTrackerH = line(Brain.ThreeWirePort.H);

//drive, claw, and balance tasks
bool Control = true;
bool stopDriver = true;
bool stopClawer = true;
extern int balanceGo;
extern int conveyorGo;
//void closed(){claw.spinToPosition(120,degrees);}
//void opened(){claw.spinToPosition(0,degrees);}
//void closed(){LineTrackerH.reflectivity();}
//void opened(){LineTrackerH.reflectivity() ;}

int userDrive() {// drive control
  while(true) {
    if(Control) {
      int drivetrainRightSpeed = Controller1.Axis3.position() - Controller1.Axis4.position();
      int drivetrainLeftSpeed = Controller1.Axis3.position() + Controller1.Axis4.position();

      if (abs(drivetrainLeftSpeed) < 5 && abs(drivetrainRightSpeed) < 5) {
        if (stopDriver) {
          leftD.stop(coast);
          rightD.stop(coast);
          stopDriver = false;
        }
      } else {
        stopDriver = true;
      }
      if (stopDriver) {
        leftD.setVelocity(drivetrainLeftSpeed, percent);
        leftD.spin(forward);
        rightD.setVelocity(drivetrainRightSpeed, percent);
        rightD.spin(forward);
      }
    }
    wait(20, msec);
  }
  return 0;
}
int senseClaw(){ //claw control
  while(true) {
      if (LineTrackerH.reflectivity() > 35 &&stopClawer==true) {
          claw.spin(forward);
          while(claw.velocity(pct)>1){
            wait(20, msec);
          }
          claw.stop(hold);
          stopClawer = false;
      } else if (LineTrackerH.reflectivity() < 30){
          claw.spinToPosition(0,degrees);
          stopClawer = true;
      }
    wait(20, msec);
  }
  return 0;
}
int conveyor(){ //ring control
  while(true){
    if(conveyorGo==1 && lift.position(deg)>120){
      ring.spin(forward, 100, pct);
    }else {
      ring.stop(coast);
    }
    wait(20, msec);
  }
  return 0;
}
int teeterTotter(){ //balancing act
  double angleToSpeed;
  while(true){
    if(balanceGo==0){
      wait(20, msec);
      }else if(balanceGo==1){
      angleToSpeed = (magic.pitch(degrees));
      leftD.spin(forward, angleToSpeed*0.45 ,percent);
      rightD.spin(forward, angleToSpeed*0.45 ,percent);
      if(angleToSpeed > -18 && angleToSpeed < 18){
        leftD.stop(hold);
        rightD.stop(hold);
      }
    }else if(balanceGo==2){
      leftD.stop(hold);
      rightD.stop(hold);
    }
    wait(20, msec);
  }
  return 0;
}
//run these bitches forever
void vexcodeInit( void ) {
task rc_auto_loop_task_Controller1(userDrive);
task clawSense(senseClaw);
task balancer(teeterTotter);
task ring (conveyor);
wait(50, msec);
}