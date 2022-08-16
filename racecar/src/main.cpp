

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// lefts                motor         1               
// rights               motor         10              
// Accel2GA             accelerometer A               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

void drift(){
  lefts.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  rights.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
}
void coasts(){
  lefts.stop(vex::);
}

void control(){
    while(true){
      Controller1.Screen.clearScreen();
      lefts.spin(vex::directionType::fwd,Controller1.Axis2.value(), vex::velocityUnits::pct);
      rights.spin(vex::directionType::fwd,Controller1.Axis3.value(), vex::velocityUnits::pct);
      Controller1.ButtonX.pressed(drift);
      

    }
}







int main() {
  
  vexcodeInit();
  control();
}
