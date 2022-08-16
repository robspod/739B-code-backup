#pragma once
#include "vex.h"
using namespace vex;
//postioning systum 
//Constens

long double circum = 3.1415 * 2.75;
long double Tl = 9.5625;
long double Tr = 9.5625;
long double Ts = 0.123;

//Formula
long double dege = 360 / circum;
int leftdis = (Encoderleft.value()) * dege;
int rightdis = (Encoderright.value()) * dege;
int pheta = ((leftdis) - (rightdis))/(Tl+Tr);
long double y = 2 * (((rightdis+0.01)/pheta)+Tr) * (sin(pheta/2)); 
//extern long double x = 2 * (((Encoderback.position(degrees) + 0.01)/pheta)+Ts) * (sin(pheta/2)); 





//auton
/*
void forwardin(double mats){
 double length = mats * matlength;
 double dege = (length / circum) * 360;
 Left.rotateFor(dege,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false);
 Right.rotateFor(dege,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
 Controller1.Screen.clearScreen();
 Controller1.rumble("--");
 Controller1.Screen.print("Calculation complete");

}
void backin(double mats){
 double length = mats * matlength;
 double dege = length / circum;
 double deges = dege * -360;
 
 Left.rotateFor(deges,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
 Right.rotateFor(deges,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
}
void turnright(int degs){
Left.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
Right.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
  
    
}
void turnleft(int degs){
Left.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
Right.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 

*/