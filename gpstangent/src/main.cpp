/*----------------------------------------------------------------------------------*/
/*                                                                                  */
/*    Module:             main.cpp                                                  */
/*    Author:             VEX                                                       */
/*    Created:            Wed Jun 09 2021                                           */
/*    Description:        Drive to Location (Using Tangents)                        */
/*                        This example will show how to use a GPS Sensor to         */
/*                        navigate a V5 Moby Hero Bot to the center of the field    */
/*                        by using a tangent calculation to determine the heading   */
/*                        to drive towards                                          */
/*                                                                                  */
/*    Starting Position:  Any                                                       */
/*                                                                                  */
/*----------------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// GPS8                 gps           10              
// Drivetrain           drivetrain    13, 17, 2, 12, 3
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
  // Calibrate the GPS before starting
 // GPS8.calibrate();
  while (GPS8.isCalibrating()) { task::sleep(50); }

  // Orient the drivetrain's heading with the GPS heading
  Drivetrain.setHeading(GPS8.heading(), degrees);
  Drivetrain.setTurnVelocity(25, percent);

  // Print the starting position of the robot
  printPosition();

  // Store the current position of the robot
  float startingX = GPS8.xPosition(mm);
  float startingY = GPS8.yPosition(mm);

  // Store the target ending position of the robot
  float endingX = 1;
  float endingY = 0;

  // Implement atan2 to calculate the heading that the robot needs to
  // turn to in order to drive towards the ending position
  float turnAngle = atan((endingX - startingX) / (endingY - startingY)) * 180 / M_PI;
  if (endingY - startingY < 0) {
    turnAngle = turnAngle + 180;
  }

  // Turn the robot to face the ending position
  Drivetrain.turnToHeading(turnAngle, degrees, true);

  // Calculate the drive distance needed, then drive towards the target position
  float driveDistance = sqrt(((endingX - startingX) * (endingX - startingX)) + ((endingY - startingY) * (endingY - startingY)));

  Drivetrain.driveFor(forward, driveDistance, mm, true);
  
  // Print the ending position of the robot
  printPosition();
}