using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern accelerometer AccelYAxis;
extern accelerometer xaxes;
extern accelerometer AccelZaxes;
extern motor29 Motor393E;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );