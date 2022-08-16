/*
#pragma once

#include "vex.h"
using namespace vex;
 
 
 int choice = 0;
 Brain.Screen.setFont(propXXL); 
 //Brain.Screen.printAt(int32_t x, int32_t y, bool bOpaque, )
 
 
 
  // variables of where on screen stuff is
  int aa = 100;
  int bb = 1;
  int cc = 240;
  int dd = 1;
  int ee = 390;
  int ff = 1;
  // clear and print them
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(black);
  Brain.Screen.setPenColor( red );
  Brain.Screen.setPenWidth(10); 
  Brain.Screen.drawRectangle(5,5,465,220);
  Brain.Screen.setFillColor(yellow);
  Brain.Screen.drawCircle(100, 1, 30); 
  Brain.Screen.drawCircle(240, 1, 30);
  Brain.Screen.drawCircle(390, 1, 30);
 
    // Touch control
  while(choice < 1){
    //circle one
    if (Controller1.ButtonX.pressing()){
     choice += 10; }
    if(Brain.Screen.pressing() and Brain.Screen.xPosition() > aa - 30 and Brain.Screen.yPosition() > bb - 30 and Brain.Screen.xPosition() < aa + 30 and Brain.Screen.yPosition() < bb + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.drawCircle(aa,bb,30);
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      aa = Brain.Screen.xPosition();
      bb = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(cc, dd, 30);
      Brain.Screen.drawCircle(ee, ff, 30);
      Brain.Screen.drawCircle(aa,bb,30);
      wait(50,msec);

      }
    }
    // circle 2
    if(Brain.Screen.pressing() and Brain.Screen.xPosition() > cc - 30 and Brain.Screen.yPosition() > dd - 30 and Brain.Screen.xPosition() < cc + 30 and Brain.Screen.yPosition() < dd + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      cc = Brain.Screen.xPosition();
      dd = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(aa, bb, 30); 
      Brain.Screen.drawCircle(ee, ff, 30);
      Brain.Screen.drawCircle(Brain.Screen.xPosition(),Brain.Screen.yPosition(),30);
      wait(50,msec);
      }
    }
    // circle 3
   if(Brain.Screen.pressing() and Brain.Screen.xPosition() > ee - 30 and Brain.Screen.yPosition() > ff - 30 and Brain.Screen.xPosition() < ee + 30 and Brain.Screen.yPosition() < ff + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      ee = Brain.Screen.xPosition();
      ff = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(aa, bb, 30); 
      Brain.Screen.drawCircle(cc, dd, 30);
      Brain.Screen.drawCircle(Brain.Screen.xPosition(),Brain.Screen.yPosition(),30);
      wait(50,msec);
      }
    }
  }




  */