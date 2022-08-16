/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotics Student                                 */
/*    Created:      Tue Feb 16 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LEDone               led           B               
// LEDtwo               led           C               
// LEDfour              led           D               
// LEDeight             led           E               
// LEDsixteen           led           F               
// LEDthirtytwo         led           G               
// LEDsixtytwo          led           H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>
using namespace std;

using namespace vex;
bool one = false;
bool two = false;
bool four = false;
bool sixteen = false;
bool
int n = 0;
int main() {
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1){
    
    if(n % 2 == 0)
    cout<<n<<( one = true);
    else
    cout<<n<<(one = false);
    return 0;
    

  }
}
