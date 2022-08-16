using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor lift2;
extern smartdrive Drivetrain;
extern motor lift1;
extern motor tray2;
extern motor claw;
extern gps gyros;
extern encoder Eleft;
extern encoder Eright;
extern encoder Eback;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );