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
bumper button = bumper(Brain.ThreeWirePort.A);
led green1 = led(Brain.ThreeWirePort.B);
led yellow1 = led(Brain.ThreeWirePort.C);
led yellow2 = led(Brain.ThreeWirePort.D);
led red1 = led(Brain.ThreeWirePort.E);
led rear = led(Brain.ThreeWirePort.H);
led flashlight = led(Brain.ThreeWirePort.G);
inertial Inertial6 = inertial(PORT6);
/*vex-vision-config:begin*/
vision Vision = vision (PORT19, 50);
/*vex-vision-config:end*/

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
  wait(50, msec);
  Brain.Screen.clearScreen();
}