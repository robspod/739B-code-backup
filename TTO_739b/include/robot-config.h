#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"
//
vex::brain Brain;
vex::controller Con = vex::controller();
vex::motor Left = vex::motor(vex::PORT8,vex::gearSetting::ratio18_1,false);
vex::motor Right = vex::motor(vex::PORT2,vex::gearSetting::ratio18_1,true);
vex::motor spiner = vex::motor(vex::PORT3,vex::gearSetting::ratio18_1,true);
vex::motor spiner2 = vex::motor(vex::PORT4,vex::gearSetting::ratio18_1,false);
vex::motor lift = vex::motor(vex::PORT5,vex::gearSetting::ratio18_1,false);
vex::motor Leftarm = vex::motor(vex::PORT7,vex::gearSetting::ratio18_1,false);
vex::motor Rightarm = vex::motor(vex::PORT9,vex::gearSetting::ratio18_1,true);
vex::controller Con2 = vex::controller(vex::controllerType::partner);
 



