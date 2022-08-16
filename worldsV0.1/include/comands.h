#pragma once
#include "vex.h"




extern void intake(){
  Belt.spin(forward,50,pct);
}
extern void intake(int insped){
  Belt.spin(forward,insped,pct);
}
extern void outtake(){
  Belt.spin(reverse,50,pct);
}
extern void outtake(int insped){
  Belt.spin(reverse,insped,pct);
}
extern void stoptake(){
  Belt.stop(brake);
}
