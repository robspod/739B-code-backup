using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern sonar RangeFinderA;
extern motor29 Motor393C;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );