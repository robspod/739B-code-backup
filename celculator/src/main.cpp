/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Sat Dec 14 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

int one = 0;
int two = 0;

void celc(){
 Controller1.Screen.clearScreen();
 Controller1.Screen.print("A = +, B = -, X = *, Y = /");
 while(true){
  if(Controller1.ButtonUp.pressing()){
    if(Controller1.ButtonL1.pressing()){
     one += 10;
     Controller1.Screen.clearScreen();
     Controller1.Screen.print(one); 
    }
    else{
     one += 1;
     Controller1.Screen.clearScreen();
     Controller1.Screen.print(one);
    }
  }
  if(Controller1.ButtonDown.pressing()){
    one -= 1;
    Controller1.Screen.clearScreen();
    Controller1.Screen.print(one);
  }
 }
}
int main() {
  celc();
  Brain.SDcard.loadFile("file.txt",buffer,100);
  vex::brain::lcd::drawBitmap();
  vexcodeInit();

  
}
