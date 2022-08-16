#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
led LEDone = led(Brain.ThreeWirePort.B);
led LEDtwo = led(Brain.ThreeWirePort.C);
led LEDfour = led(Brain.ThreeWirePort.D);
led LEDeight = led(Brain.ThreeWirePort.E);
led LEDsixteen = led(Brain.ThreeWirePort.F);
led LEDthirtytwo = led(Brain.ThreeWirePort.G);
led LEDsixtytwo = led(Brain.ThreeWirePort.H);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}