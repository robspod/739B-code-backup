#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor lift2 = motor(PORT15, ratio36_1, true);
motor lift1 = motor(PORT17, ratio36_1, false);
motor tray2 = motor(PORT12, ratio18_1, false);
motor claw = motor(PORT18, ratio36_1, false);
sonar RangeFinder = sonar(Brain.ThreeWirePort.G);
gps GPS21 = gps(PORT21, 0.00, 0.00, mm, 90);
motor leftMotorA = motor(PORT7, ratio18_1, false);
motor leftMotorB = motor(PORT16, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT9, ratio18_1, true);
motor rightMotorB = motor(PORT10, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
gps DrivetrainGPS = gps(PORT20, 0.00, 0.00, mm, 90);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainGPS, 319.19, 320, 40, mm, 1);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain GPS
  wait(200, msec);
  DrivetrainGPS.calibrate();
  Brain.Screen.print("Calibrating GPS for Drivetrain");
  // wait for the GPS calibration process to finish
  while (DrivetrainGPS.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}