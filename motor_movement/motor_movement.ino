#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>

// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

int i;
void setup(){
    i = 512;
    Serial.begin(38400); //start serial communications at 38400bps
}

void loop(){
    // set AX-12 servo with ID=1, to position i, where 0=<i<950 because of extention
   int inByte = Serial.read();
   Serial.println("Running...");
   while(i<700){
     delay(50);
      SetPosition(2,i);
     SetPosition(1,i);
     i++;
     
     int inByte = Serial.read();       
      switch (inByte)
      {
        case '0':    
          relaxArm();
          exit(0);
        break;    
      }
   }
   
   while(i>512){
     switch (inByte)
      {
        case '0':    
          relaxArm();
          exit(0);
        break;    
      }
      
     delay(50);
     SetPosition(2,i);
     SetPosition(1,i);
     i--;
   }
   
}

void relaxArm(){
    i=512; 
    SetPosition(2,i);
    SetPosition(1,i);
}

