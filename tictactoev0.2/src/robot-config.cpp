#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Left = motor(PORT13, ratio18_1, true);
motor Right = motor(PORT5, ratio18_1, false);
motor top2 = motor(PORT10, ratio18_1, false);
motor middle = motor(PORT9, ratio18_1, true);
motor bottom = motor(PORT8, ratio18_1, false);
controller Controller1 = controller(primary);
motor arm1 = motor(PORT11, ratio18_1, false);
motor arm2 = motor(PORT7, ratio18_1, true);
/*vex-vision-config:begin*/
signature Vision__REDS = signature (1, 2561, 8571, 5566, -1409, 143, -634, 1, 0);
signature Vision__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision = vision (PORT19, 50, Vision__REDS, Vision__SIG_2, Vision__SIG_3, Vision__SIG_4, Vision__SIG_5, Vision__SIG_6, Vision__SIG_7);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}