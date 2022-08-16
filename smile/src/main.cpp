/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Mon Dec 16 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {   
    //Create an infinite loop to record data until the user manually ends the program.
    while(1) {         
        //Check to see if the brain has been pressed.
        if(Brain.Screen.pressing()) { //If the Brain is pressed...
            //...Clear the screen of any circles that were on the screen from a previous touch.
            Brain.Screen.clearScreen();            
            //Draw a circle with the origin being the user's touch locations.
            Brain.Screen.drawCircle(Brain.Screen.xPosition(), Brain.Screen.yPosition(), 50);
        }
    }
    //Brain.SDcard.loadFile("face.png",buffer,100);
}
