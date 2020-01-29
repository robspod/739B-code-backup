using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor Left;
extern motor Right;
extern motor spiner;
extern motor spiner2;
extern motor lift;
extern motor Leftarm;
extern motor Rightarm;
extern controller Controller1;
extern controller Controller2;
extern signature Vision__ORNAGES;
extern signature Vision__PUPLE;
extern signature Vision__GREENS;
extern signature Vision__BLUES;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;
extern accelerometer AccelX;
extern accelerometer AccelY;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );