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
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
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
  // nothing to initialize
}