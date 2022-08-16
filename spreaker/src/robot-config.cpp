#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
bumper BumperA = bumper(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);
motor Motor14 = motor(PORT14, ratio18_1, false);
line LineTrackerH = line(Brain.ThreeWirePort.H);
bumper BumperB = bumper(Brain.ThreeWirePort.B);

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