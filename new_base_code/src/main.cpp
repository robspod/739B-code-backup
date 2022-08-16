// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// see_me               vision        20              
// Right                motor         2               
// left                 motor         8               
// spiner               motor         3               
// spiner2              motor         4               
// leftarm              motor         9               
// rightarm             motor         7               
// lift                 motor         5               
// Controller2          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "robot-config.cpp"



vex::competition    Competition;
int speed = 2;
int speed2 = 2;
int speedpct = 100;
void forward(){
    Left.spin(vex::directionType::fwd,50,vex::velocityUnits::rpm); 
    Right.spin(vex::directionType::fwd,50,vex::velocityUnits::rpm);
}
void backward(){
    Left.spin(vex::directionType::rev,50,vex::velocityUnits::rpm);
    Right.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
}
void TurnRight(){
    Left.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);
    Right.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
}
void TurnLeft(){
    Left.spin(vex::directionType::rev,50,vex::velocityUnits::pct);
    Right.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);
}
void stopall(){
    Left.stop(vex::brakeType::brake);
    Right.stop(vex::brakeType::brake);
}
void stopleft(){
    Left.stop(vex::brakeType::brake);
}
void stopright(){
    Right.stop(vex::brakeType::brake);
}
void intake(){
    spiner.spin(vex::directionType::fwd,speedpct,vex::velocityUnits::pct);
    spiner2.spin(vex::directionType::fwd,speedpct,vex::velocityUnits::pct);
}
void outtake(){
    spiner.spin(vex::directionType::rev,speedpct,vex::velocityUnits::pct);
    spiner2.spin(vex::directionType::rev,speedpct,vex::velocityUnits::pct);
}
void stopintake(){
    spiner.stop(vex::brakeType::coast);
    spiner2.stop(vex::brakeType::coast);
}
void lifthold(){
    lift.stop(vex::brakeType::hold);
}
void liftup(){
    lift.spin(vex::directionType::fwd,100/speed,vex::velocityUnits::pct);
}
void liftdown(){
    lift.spin(vex::directionType::rev,100/speed,vex::velocityUnits::pct);
}
void up(){
    Rightarm.spin(vex::directionType::fwd,100/speed2,vex::velocityUnits::pct);
    Leftarm.spin(vex::directionType::fwd,100/speed2,vex::velocityUnits::pct);     
}
void down(){
    Rightarm.spin(vex::directionType::rev,100/speed2,vex::velocityUnits::pct);
    Leftarm.spin(vex::directionType::rev,100/speed2,vex::velocityUnits::pct);
}
void stoparms(){
    Rightarm.stop(vex::brakeType::hold);
    Leftarm.stop(vex::brakeType::hold);
}



void pre_auton( void ) {
    
}



void autonomous( void ) {
 forward();
 vex::timeUnits(1)
 stopall();
 
 
    
    
}



void usercontrol( void ) {
 
  
  while (1) {

        
        if(Con.ButtonL1.pressing()){
            if(speed == 1){
                Con.Screen.clearScreen();
                Con.Screen.print("Stop");
                Con.rumble("-");
            }
            else{
                speed = speed - 1;
                Con.Screen.clearScreen();
                Con.Screen.print(speed);
            }
        }
        if(Con.ButtonL2.pressing()){
           if(Con.ButtonR2.pressing()){
                speed = speed + 1;
                Con.Screen.clearScreen();
                Con.Screen.print(speed);
           }
            
            if(speed == 5){
                Con.Screen.clearScreen();
                Con.Screen.print("Stop");
                Con.rumble("-");
           }
            
            else{
                speed = speed + 1;
                Con.Screen.clearScreen();
                Con.Screen.print(speed);
            }
            
        }
       if(Con2.ButtonL1.pressing()){
            if(speed2 == 1){
                Con.Screen.clearScreen();
                Con.Screen.print("Stop");
                Con.rumble("-");
            }
            else{
                speed2 = speed2 - 1;
                Con.Screen.clearScreen();
                Con.Screen.print(speed2);
            }
        }
        if(Con2.ButtonL2.pressing()){
           if(Con2.ButtonR2.pressing()){
                speed2 = speed2 + 1;
                Con.Screen.clearScreen();
                Con.Screen.print(speed2);
           }
            
            if(speed2 == 5){
                Con2.Screen.clearScreen();
                Con2.Screen.print("Stop");
                Con2.rumble("-");
           }
            
            else{
                speed2 = speed2 + 1;
                Con2.Screen.clearScreen();
                Con2.Screen.print(speed2);
            }
            
        }

          
      
       
       Con2.ButtonR1.pressed(intake);
       Con2.ButtonR1.released(stopintake);
       Con2.ButtonR2.pressed(outtake);
       Con2.ButtonR2.released(stopintake);
       Con.ButtonX.pressed(liftup);
       Con.ButtonX.released(lifthold);
       Con.ButtonB.pressed(liftdown);
       Con.ButtonB.released(lifthold);
       Con2.ButtonUp.pressed(up);
       Con2.ButtonUp.released(stoparms);
       Con2.ButtonDown.pressed(down);
       Con2.ButtonDown.released(stoparms);
       Left.spin(vex::directionType::fwd, (Con.Axis3.value() + Con.Axis4.value())/speed , vex::velocityUnits::pct); //(Axis3+Axis4)/2
       Right.spin(vex::directionType::fwd, (Con.Axis3.value() - Con.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/2
      
      
      vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
      
    }
}



int main() {
    
    
    pre_auton();
   
    
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

                       
    while(1) {
      wait(100,msec);
    }    
       
}