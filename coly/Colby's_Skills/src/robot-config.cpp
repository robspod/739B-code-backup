#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor top2 = motor(PORT10, ratio18_1, false);
motor middle = motor(PORT12, ratio18_1, true);
motor bottom = motor(PORT8, ratio18_1, false);
controller Controller1 = controller(primary);
motor arm1 = motor(PORT11, ratio18_1, true);
motor arm2 = motor(PORT7, ratio18_1, false);
motor topback = motor(PORT9, ratio18_1, true);
motor LeftDriveSmart = motor(PORT5, ratio18_1, false);
motor RightDriveSmart = motor(PORT13, ratio18_1, true);
inertial TurnGyroSmart = inertial(PORT20);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart, 319.19, 320, 40, mm, 1);
/*vex-vision-config:begin*/
signature Vision__REDS = signature (1, 4253, 9295, 6774, -729, 115, -308, 2.1, 0);
signature Vision__BLUES = signature (2, -3071, -1087, -2078, 5117, 10365, 7742, 1.1, 0);
vision Vision = vision (PORT19, 50, Vision__REDS, Vision__BLUES);
/*vex-vision-config:end*/
bumper button = bumper(Brain.ThreeWirePort.A);
led green1 = led(Brain.ThreeWirePort.B);
led yellow1 = led(Brain.ThreeWirePort.C);
led yellow2 = led(Brain.ThreeWirePort.D);
led red1 = led(Brain.ThreeWirePort.E);
led rear = led(Brain.ThreeWirePort.H);
led flashlight = led(Brain.ThreeWirePort.G);
inertial Inertial6 = inertial(PORT6);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis4
      // right = Axis3 - Axis4
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis4.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis4.position();
      
      // check if the values are inside of the deadband range
      if (abs(drivetrainLeftSideSpeed) < 5 && abs(drivetrainRightSideSpeed) < 5) {
        // check if the motors have already been stopped
        if (DrivetrainNeedsToBeStopped_Controller1) {
          // stop the drive motors
          LeftDriveSmart.stop();
          RightDriveSmart.stop();
          // tell the code that the motors have been stopped
          DrivetrainNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the motors next time the input is in the deadband range
        DrivetrainNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain gyro
  wait(200, msec);
  TurnGyroSmart.calibrate();
  Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // wait for the gyro calibration process to finish
  while (TurnGyroSmart.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}