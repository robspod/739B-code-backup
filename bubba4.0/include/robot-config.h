using namespace vex;
extern brain Brain;
// VEXcode devices
extern controller Controller1;
extern motor_group leftD;
extern motor_group rightD;
extern motor claw;
extern motor tray;
extern motor lift;
extern motor ring;
//extern limit clawLimit;
extern line LineTrackerH;
extern encoder leftE;
extern encoder rightE;
extern inertial magic;
void  vexcodeInit( void );