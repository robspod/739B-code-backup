#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT2, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 130, mm, 1);
controller Controller1 = controller(primary);
/*vex-vision-config:begin*/
signature Vision20__SIG_1 = signature (1, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision20__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision20__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision20__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision20__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision20__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision20__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision20 = vision (PORT20, 50, Vision20__SIG_1, Vision20__SIG_2, Vision20__SIG_3, Vision20__SIG_4, Vision20__SIG_5, Vision20__SIG_6, Vision20__SIG_7);
/*vex-vision-config:end*/
light LightA = light(Brain.ThreeWirePort.A);
motor Motor3 = motor(PORT3, ratio18_1, false);
controller Controller2 = controller(partner);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}