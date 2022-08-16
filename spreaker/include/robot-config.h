using namespace vex;

extern brain Brain;

// VEXcode devices
extern bumper BumperA;
extern controller Controller1;
extern motor Motor14;
extern line LineTrackerH;
extern bumper BumperB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );