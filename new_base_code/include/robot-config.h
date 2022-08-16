using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern signature see_me__ORNAGE;
extern signature see_me__GREEEN;
extern signature see_me__PUPLE;
extern signature see_me__SIG_4;
extern signature see_me__SIG_5;
extern signature see_me__SIG_6;
extern signature see_me__SIG_7;
extern vision see_me;
extern motor Right;
extern motor left;
extern motor spiner;
extern motor spiner2;
extern motor leftarm;
extern motor rightarm;
extern motor lift;
extern controller Controller2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );