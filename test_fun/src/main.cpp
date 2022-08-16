/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  Detect Collisions                                         */
/*                  This program uses the Accelerometer to detect if the robot*/
/*                  is bumped along the y-axis. */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    2, 8            
// AccelYAxis           accelerometer B               
// xaxes                accelerometer A               
// AccelZaxes           accelerometer C               
// Motor393E            motor29       E               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool hasStopped = false;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Set the drive velocity to 50 percent and drive forward.
  Drivetrain.setDriveVelocity(50, percent);

  // Repear forever
  while (true) {
    // If the accelerometer reads greater than .2 gs, and has not stopped yet, stop.
    if (AccelYAxis.acceleration() > .1 && !hasStopped) {
      Drivetrain.stop();
      Controller1.Screen.print("Robot hit on Y Axis");
      hasStopped = true;
    }
     if (xaxes.acceleration() > .1 && !hasStopped) {
      Drivetrain.stop();
      Controller1.Screen.print("Robot hit on X Axis");
      hasStopped = true;
    }
    wait(5, msec);

  }
}
