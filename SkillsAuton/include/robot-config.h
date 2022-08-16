using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor lift2;
extern motor lift1;
extern motor tray2;
extern motor claw;
extern sonar RangeFinder;
extern gps GPS21;
extern smartdrive Drivetrain;
extern gps DrivetrainGPS;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );