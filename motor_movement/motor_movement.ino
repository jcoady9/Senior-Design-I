#include <BioloidController.h>
#include <ax12.h>

#include <Motors2.h>

// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

int i;
void setup(){
    i = 0;
}

void loop(){
    // set AX-12 servo with ID=1, to position i, where 0=<i<1024
    SetPosition(3,i);
    i = (i++)%1024;
}


/*Motors2 drive = Motors2();

void setup() {
    drive.set(-255,-255); // drive backwards at full speed 
    delay(1000);

    drive.set(0,0); // stop
    delay(1000);

    drive.set(100,100); // drive forward at half speed
    delay(1000);

    drive.left(0); // stop the left motor, turn in place
    delay(500);    
    drive.right(50); // cut right motor speed in half
    delay(500);
    drive.right(0); // and stop
}

void loop(){
    
}
*/
