/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Sep 24 2019                                           */
/*    Description:  Controller Buttons                                        */
/*    This program shows two different ways of controlling robot behavior     */
/*    using Controller buttons.                                               */
/*   - "When Controller" events are triggered when a Controller button is     */
/*     pressed                                                                */
/*   - "If / Else" statements can be used inside of a "true" loop to check    */
/*     if a button pressed and perform different behaviors.                   */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor            motor         1               
// RightMotor           motor         10              
// ClawMotor            motor         5               
// ArmMotor             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// Method - 1 Callbacks
// whenControllerL1Pressed and whenControllerL2Pressed callback functions are
// registered to the contorller's button 'pressed' event. Whenever the 'Button
// L1' and 'Button R1` are pressed, the functions will run.

void whenControllerL1Pressed() {
  ArmMotor.spin(forward);
  waitUntil(!Controller1.ButtonL1.pressing());
  ArmMotor.stop();
}

void whenControllerL2Pressed() {
  ArmMotor.spin(reverse);
  waitUntil(!Controller1.ButtonL2.pressing());
  ArmMotor.stop();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Set motor's brake mode and velocity
  ArmMotor.setStopping(hold);
  ClawMotor.setStopping(hold);
  ArmMotor.setVelocity(30, percent);
  ClawMotor.setVelocity(60, percent);

  // Method 1 - Using Callbacks
  // Register callbacks to controller button 'pressed' events.
  Controller1.ButtonL1.pressed(whenControllerL1Pressed);
  Controller1.ButtonL2.pressed(whenControllerL2Pressed);

  // Method - 2 Inline-code
  // Use a 'forever loop' to constantly check the controller's values.
  while (true) {
    if (Controller1.ButtonR1.pressing()) {
      ClawMotor.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      ClawMotor.spin(reverse);
    } else {
      ClawMotor.stop();
    }
    wait(25, msec);
  }
}
