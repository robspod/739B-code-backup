#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
inertial DrivetrainInertial = inertial(PORT3);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);
motor ForkMotorGroupMotorA = motor(PORT2, ratio18_1, false);
motor ForkMotorGroupMotorB = motor(PORT9, ratio18_1, true);
motor_group ForkMotorGroup = motor_group(ForkMotorGroupMotorA, ForkMotorGroupMotorB);
rotation Rotation4 = rotation(PORT4, false);
gps GPS8 = gps(PORT8, 0.00, -240.00, mm, 180);
distance DistanceLeft = distance(PORT12);
distance DistanceRight = distance(PORT20);
optical Optical19 = optical(PORT19);
bumper BumperA = bumper(Brain.ThreeWirePort.A);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}