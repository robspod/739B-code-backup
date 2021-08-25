#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RoboticArm1_mJ1 = motor(PORT1, ratio18_1, false);
motor RoboticArm1_mJ2 = motor(PORT2, ratio18_1, true);
motor RoboticArm1_mJ3 = motor(PORT3, ratio18_1, false);
motor RoboticArm1_mJ4 = motor(PORT4, ratio18_1, false);
pot RoboticArm1_mJ1_pot = pot(Brain.ThreeWirePort.A);
pot RoboticArm1_mJ2_pot = pot(Brain.ThreeWirePort.B);
pot RoboticArm1_mJ3_pot = pot(Brain.ThreeWirePort.C);
pot RoboticArm1_mJ4_pot = pot(Brain.ThreeWirePort.D);
RoboticArm RoboticArm1 = RoboticArm(RoboticArm1_mJ1, RoboticArm1_mJ1_pot, RoboticArm1_mJ2, RoboticArm1_mJ2_pot, RoboticArm1_mJ3, RoboticArm1_mJ3_pot, RoboticArm1_mJ4, RoboticArm1_mJ4_pot);
controller Controller1 = controller(primary);
motor LeftDriveSmart = motor(PORT5, ratio18_1, false);
motor RightDriveSmart = motor(PORT6, ratio18_1, true);
gps DrivetrainGPS = gps(PORT7, 0.00, 0.00, mm, 180);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainGPS, 319.19, 320, 40, mm, 1);
led LED = led(Brain.ThreeWirePort.H);
digital_in DigitalInG = digital_in(Brain.ThreeWirePort.G);
digital_out DigitalOutF = digital_out(Brain.ThreeWirePort.F);

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