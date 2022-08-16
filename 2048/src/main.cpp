/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Thu Jan 16 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "robot-config.h"

using namespace vex;


#define SWIPE_NONE 0
#define SWIPE_UP 1
#define SWIPE_DOWN 2
#define SWIPE_LEFT 3
#define SWIPE_RIGHT 4

#define SCREEN_FAIL_THRESHOLD 15

#define IN_BOUNDARY(x) (x >= 0 && x <= 3)

int array2048[4][4] = {};
int press_x, press_y;

void generate2()
{
    int dst_x, dst_y;
    do
    {
        dst_x = rand() % 4;
        dst_y = rand() % 4;
    }
    while(array2048[dst_x][dst_y] != 0);
    array2048[dst_x][dst_y] = 2;
}

void __combineNum(int array[4])
{
    if(array[0] == array[1] || array[2] == array[3])
    {
        if(array[0] == array[1])
        {
            array[0] <<= 1;
            array[1] = 0;
        }
        if(array[2] == array[3])
        {
            array[2] <<= 1;
            array[3] = 0;
        }
    }
    else if(array[1] == array[2])
    {
        array[1] <<= 1;
        array[2] = 0;
    }
}

void __combineZero(int array[4])
{
    int tmp_array[4], tmp_cnt = 0;
    for(int a = 0; a <= 3; ++a) tmp_array[a] = array[a];
    for(int a = 0; a <= 3; ++a)
    {
        if(tmp_array[a] != 0)
        {
            array[tmp_cnt++] = tmp_array[a];
        }
    }
    for(; tmp_cnt <= 3; ++tmp_cnt) array[tmp_cnt] = 0;
}

void combine(int dir)
{
    int proc_array[4];
    switch(dir)
    {
        case SWIPE_UP:
        {
            for(int x = 0; x <= 3; ++x)
            {
                for(int y = 0; y <= 3; ++y) proc_array[y] = array2048[x][y];
                __combineZero(proc_array);
                __combineNum(proc_array);
                __combineZero(proc_array);
                for(int y = 0; y <= 3; ++y) array2048[x][y] = proc_array[y];
            }
            break;
        }
        case SWIPE_DOWN:
        {
            for(int x = 0; x <= 3; ++x)
            {
                for(int y = 0; y <= 3; ++y) proc_array[3 - y] = array2048[x][y];
                __combineZero(proc_array);
                __combineNum(proc_array);
                __combineZero(proc_array);
                for(int y = 0; y <= 3; ++y) array2048[x][y] = proc_array[3 - y];
            }
            break;
        }
        case SWIPE_LEFT:
        {
            for(int y = 0; y <= 3; ++y)
            {
                for(int x = 0; x <= 3; ++x) proc_array[x] = array2048[x][y];
                __combineZero(proc_array);
                __combineNum(proc_array);
                __combineZero(proc_array);
                for(int x = 0; x <= 3; ++x) array2048[x][y] = proc_array[x];
            }
            break;
        }
        case SWIPE_RIGHT:
        {
            for(int y = 0; y <= 3; ++y)
            {
                for(int x = 0; x <= 3; ++x) proc_array[3 - x] = array2048[x][y];
                __combineZero(proc_array);
                __combineNum(proc_array);
                __combineZero(proc_array);
                for(int x = 0; x <= 3; ++x) array2048[x][y] = proc_array[3 - x];
            }
            break;
            break;
        }
    }
}

void refreshScreen()
{
    for(int x = 0; x <= 3; ++x)
    {
        for(int y = 0; y <= 3; ++y)
        {
            Brain.Screen.printAt(x * 60 + 15, y * 60 + 35, "    ");
            if(array2048[x][y] != 0)
            {
                Brain.Screen.setPenColor(array2048[x][y] << 2);
                Brain.Screen.printAt(x * 60 + 15, y * 60 + 35, "%d", array2048[x][y]);
                Brain.Screen.setPenColor(vex::color::white);
            }
        }
    }
}

bool isFinal()
{
    for(int x = 0; x <= 3; ++x)
    {
        for(int y = 0; y <= 3; ++y)
        {
            if(array2048[x][y] == 0) return false;
        }
    }
    return true;
}

void gamingScreenPressedCallback()
{
    if(press_x == 0 && press_y == 0)
    {
        press_x = Brain.Screen.xPosition();
        press_y = Brain.Screen.yPosition();
    }
}

void gamingScreenReleasedCallback()
{
    int dst_x = Brain.Screen.xPosition(), dst_y = Brain.Screen.yPosition();
    int delta_x = dst_x - press_x, delta_y = dst_y - press_y;
    press_x = press_y = 0;
    if(abs(delta_x) < SCREEN_FAIL_THRESHOLD && abs(delta_y) < SCREEN_FAIL_THRESHOLD) return;
    
    int swipe_dir = SWIPE_NONE;
    if(abs(delta_x) > abs(delta_y))
    {
        if(delta_x > 0) swipe_dir = SWIPE_RIGHT;
        else if(delta_x < 0) swipe_dir = SWIPE_LEFT;
    }
    else if(abs(delta_y) > abs(delta_x))
    {
        if(delta_y > 0) swipe_dir = SWIPE_DOWN;
        else if(delta_y < 0) swipe_dir = SWIPE_UP;
    }
    else if (Controller1.ButtonRight.pressing())swipe_dir = SWIPE_RIGHT;
    else if (Controller1.ButtonLeft.pressing())swipe_dir = SWIPE_LEFT;
    else if (Controller1.ButtonDown.pressing())swipe_dir = SWIPE_DOWN;
    else if (Controller1.ButtonUp.pressing())swipe_dir = SWIPE_UP;
    combine(swipe_dir);
    if(isFinal())
    {
        Brain.Screen.clearScreen();
        Brain.Screen.printAt(50, 50, "Game over...");
        Brain.Screen.printAt(50, 75, "Please quit the program.");
        while(true) vex::task::yield();
    }
    generate2();
    refreshScreen();
}

int main()
{
    Brain.Screen.setPenColor(vex::color::white);
    
    // Initialize random
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(50, 50, "Now press on the screen randomly.");
    Brain.Screen.printAt(50, 75, "Then swipe the screen to play.");
    Brain.Screen.printAt(50, 100, "Though V5 screen is hard to swipe. :(");
    Brain.Screen.printAt(50, 150, "V5 2048 Game");
  
    int rnd_x, rnd_y;
    while(!Brain.Screen.pressing()) vex::task::yield();
    rnd_x = Brain.Screen.xPosition();
    rnd_y = Brain.Screen.yPosition();
    while(Brain.Screen.pressing()) vex::task::yield();
    srand(rnd_x * rnd_y * time(NULL));
    
    // Draw initial rectangle
    Brain.Screen.clearScreen();
    for(int x = 0; x <= 3; ++x)
    {
        for(int y = 0; y <= 3; ++y)
        {
            Brain.Screen.drawRectangle(x * 60, y * 60, 60, 60);
        }
    }
    
    generate2();
    generate2();
    refreshScreen();
    
    Brain.Screen.pressed(gamingScreenPressedCallback);
    Brain.Screen.released(gamingScreenReleasedCallback);
    
    while(true) vex::task::yield();
}
