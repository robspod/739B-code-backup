/*----------------------------------------------------------------------------------*/
/*                                                                                  */
/*    Module:             main.cpp                                                  */
/*    Author:             VEX                                                       */
/*    Created:            Wed Jun 09 2021                                           */
/*    Description:        Drive to Location (Known Starting Position)               */
/*                        This example will show how to use a GPS Sensor to         */
/*                        navigate a V5 Moby Hero Bot to the center of a field      */
/*                        by driving along the X-axis then the Y-axis               */
/*                                                                                  */
/*    Starting Position:  Bottom Right Corner - Facing West                         */
/*                                                                                  */
/*----------------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, 3        
// ForkMotorGroup       motor_group   2, 9            
// Rotation4            rotation      4               
// GPS8                 gps           8               
// DistanceLeft         distance      12              
// DistanceRight        distance      20              
// Optical19            optical       19              
// BumperA              bumper        A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void printPosition() {
  // Print GPS position values to the V5 Brain
  Brain.Screen.print("X: %.2f", GPS8.xPosition(mm));
  Brain.Screen.print("  Y: %.2f", GPS8.yPosition(mm));
  Brain.Screen.newLine();
}

int main() {
  // Calibrate the GPS Sensor before starting
  GPS8.calibrate();
  while (GPS8.isCalibrating()) { task::sleep(50); }

  // Set the approximate starting position of the robot
  // This helps the GPS Sensor know its starting position
  // if it is too close to the field walls to get an accurate initial reading
  GPS8.setLocation(56, -45, inches, 270, degrees);

  // Print the starting position of the robot
  printPosition();
  Drivetrain.drive(forward);

  // Keep driving until the GPS's xPosition passes 0 (horizontal center)
  while (!(GPS8.xPosition(mm) < 0)) {
    wait(0.1, seconds);
  }
  Drivetrain.stop();

  Drivetrain.turnToHeading(90, degrees, true);
  Drivetrain.drive(forward);

  // Keep driving until the GPS's yPosition passes 0 (vertical center)
  while (!(GPS8.yPosition(mm) > 0)) {
    wait(0.1, seconds);
  }
  Drivetrain.stop();

  // Print the ending position of the robot
  printPosition();
}