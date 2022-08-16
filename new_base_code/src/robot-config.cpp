#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
/*vex-vision-config:begin*/
signature see_me__ORNAGE = signature (1, 6685, 8897, 7792, -2341, -1675, -2008, 2.5, 0);
signature see_me__GREEEN = signature (2, -7199, -511, -3854, -3097, -441, -1770, 0.9, 0);
signature see_me__PUPLE = signature (3, 473, 1649, 1062, 4681, 8761, 6722, 1.3, 0);
signature see_me__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature see_me__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature see_me__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature see_me__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision see_me = vision (PORT20, 50, see_me__ORNAGE, see_me__GREEEN, see_me__PUPLE, see_me__SIG_4, see_me__SIG_5, see_me__SIG_6, see_me__SIG_7);
/*vex-vision-config:end*/
motor Right = motor(PORT2, ratio18_1, false);
motor left = motor(PORT8, ratio18_1, false);
motor spiner = motor(PORT3, ratio18_1, false);
motor spiner2 = motor(PORT4, ratio18_1, false);
motor leftarm = motor(PORT9, ratio18_1, false);
motor rightarm = motor(PORT7, ratio18_1, false);
motor lift = motor(PORT5, ratio18_1, false);
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