/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Claw and Arm                                              */
/*                                                                            */
/*    The VEX V5 Clawbot grabs an object and transports it forward.           */
/*    The Clawbot then places the object down and returns to its orginal      */
/*    spot.                                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, D
// ClawMotor            motor         3
// ArmMotor             motor         8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Set the motor's internal encoder values of both the Arm and Claw's internal
  // motor encoders to zero
  ArmMotor.setPosition(0, degrees);
  ClawMotor.setPosition(0, degrees);
  // Close the Claw on an object
  ClawMotor.spinFor(forward, 90, degrees);
  wait(1, seconds);
  // Raise the Arm
  ArmMotor.spinFor(forward, 1, turns);
  // Drive Forward
  Drivetrain.driveFor(forward, 10, inches);
  // Lower the Arm
  ArmMotor.spinFor(reverse, 1, turns);
  // Open the Claw
  ClawMotor.spinFor(reverse, 45, degrees);
  // Move the robot back to the original starting place
  wait(1, seconds);
  Drivetrain.driveFor(reverse, 10, inches);
}
