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
extern encoder Encoderleft;
extern encoder Encoderright;
extern encoder Encoderback;
extern rotation Rotation18;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );