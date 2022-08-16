#include "vex.h"
using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain  Brain;

controller Controller1 = controller(primary);
motor claw = motor(PORT15, ratio36_1, 1);
motor lift = motor(PORT13, ratio18_1, 1);
motor tray = motor(PORT6, ratio36_1);
motor ring = motor(PORT18, ratio36_1, 0);
motor leftDMotorA = motor(PORT4, ratio18_1, 1);
motor leftDMotorB = motor(PORT5, ratio18_1, 0);
motor_group leftD = motor_group(leftDMotorA, leftDMotorB);
motor rightDMotorA = motor(PORT16, ratio18_1, 1);
motor rightDMotorB = motor(PORT17, ratio18_1, 0);
motor_group rightD = motor_group(rightDMotorA, rightDMotorB);
limit clawLimit = limit(Brain.ThreeWirePort.H);
encoder leftE = encoder(Brain.ThreeWirePort.G);
encoder rightE = encoder(Brain.ThreeWirePort.C);
inertial magic = inertial(PORT3);

//drive, claw, and balance tasks
bool Control = true;
bool stopDriver = true;
bool stopClawer = true;
extern int balanceGo;

int userDrive() {
  while(true) {
    if(Control) {
      int drivetrainLeftSpeed = Controller1.Axis3.position() - Controller1.Axis4.position();
      int drivetrainRightSpeed = Controller1.Axis3.position() + Controller1.Axis4.position();

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

int senseClaw(){
  while(true) {
      if (clawLimit.pressing()&&stopClawer==true) {
          claw.spinToPosition(120,degrees);
          claw.stop(hold);
          stopClawer = false;
      } else if (clawLimit.pressing()==false){
          stopClawer = true;
      }
    wait(20, msec);
  }
  return 0;
}
//balancing act
int teeterTotter(){
  double angleToSpeed;
  //double edge;
  while(1){
    if(balanceGo==0){

    }else if(balanceGo==1){
      angleToSpeed = -(magic.roll(degrees));
      leftD.spin(forward, angleToSpeed*0.50 ,percent);
      rightD.spin(forward, angleToSpeed*0.50 ,percent);
      if(angleToSpeed > -10 && angleToSpeed < 10){
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
wait(50, msec);
}