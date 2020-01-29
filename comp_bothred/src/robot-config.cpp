#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Left = motor(PORT8, ratio18_1, false);
motor Right = motor(PORT2, ratio18_1, true);
motor spiner = motor(PORT3, ratio18_1, true);
motor spiner2 = motor(PORT6, ratio18_1, false);
motor lift = motor(PORT5, ratio18_1, false);
motor Leftarm = motor(PORT7, ratio18_1, false);
motor Rightarm = motor(PORT9, ratio18_1, true);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
/*vex-vision-config:begin*/
signature Vision__ORNAGES = signature (1, 6079, 8447, 7262, -1963, -1577, -1770, 1.9, 0);
signature Vision__PUPLE = signature (2, -1, 1631, 814, 255, 6017, 3136, 1.2, 0);
signature Vision__GREENS = signature (3, -6709, -2247, -4478, -3133, -1013, -2074, 1.1, 0);
signature Vision__BLUES = signature (4, -3181, -2591, -2886, 10441, 12929, 11686, 2.5, 0);
signature Vision__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision = vision (PORT20, 50, Vision__ORNAGES, Vision__PUPLE, Vision__GREENS, Vision__BLUES, Vision__SIG_5, Vision__SIG_6, Vision__SIG_7);
/*vex-vision-config:end*/
accelerometer AccelX = accelerometer(Brain.ThreeWirePort.A);
accelerometer AccelY = accelerometer(Brain.ThreeWirePort.B);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}