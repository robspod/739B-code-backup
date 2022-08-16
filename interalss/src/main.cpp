/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Dec 04 2019                                           */
/*    Description:  This program will turn right 90 degrees using the         */
/*                  Inertial Sensor.                                          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         1               
// RightMotor           motor         10              
// Inertial20           inertial      20              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Inertial20.calibrate();
  // waits for the Inertial Sensor to calibrate
  while (Inertial20.isCalibrating()) {
    wait(100, msec);
  }
  // Turns the robot to the right
  LeftMotor.spin(forward);
  RightMotor.spin(reverse);
  // Waits until the motor reaches a 90 degree turn and stops the Left and
  // Right Motors.
  waitUntil((Inertial20.rotation(degrees) >= 90.0));
  LeftMotor.stop();
  RightMotor.stop();
  wait(1, seconds);
}
