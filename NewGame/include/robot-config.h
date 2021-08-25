using namespace vex;

extern brain Brain;

// VEXcode devices
extern RoboticArm RoboticArm1;
extern controller Controller1;
extern smartdrive Drivetrain;
extern gps DrivetrainGPS;
extern led LED;
extern digital_in DigitalInG;
extern digital_out DigitalOutF;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );