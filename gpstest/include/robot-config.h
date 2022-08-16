using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern motor_group ForkMotorGroup;
extern rotation Rotation4;
extern gps GPS8;
extern distance DistanceLeft;
extern distance DistanceRight;
extern optical Optical19;
extern bumper BumperA;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );