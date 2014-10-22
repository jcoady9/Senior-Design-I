#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>

// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

int i;
void setup(){
    i = 512;
    SetPosition(3, 450);
    Serial.begin(38400); //start serial communications at 38400bps
}

void loop(){
    // set AX-12 servo with ID=1, to position i, where 0=<i<950 because of extention
   int inByte = Serial.read();
   Serial.println("Running...");
   while(i<600){
     delay(35);
     SetPosition(1,i);
     SetPosition(2,i);
     //SetPosition(3,i);
     
     i++;
    
     int inByte = Serial.read();       
      switch (inByte)
      {
        case '0':    
          relaxArm();
          exit(0);
          break;    
        
        case '1':
          penUp();
          Serial.println("Pen Up");
          break;
        
        case '2':
          penDown();
          Serial.println("Pen Down");
          break;      
    }
   }
   
   while(i>400){
     switch (inByte)
      {
        case '0':    
          relaxArm();
          exit(0);
        break; 
     
        case '1':
          penUp();
          Serial.println("Pen Up");
          break;
      
        case '2':
          penDown();
          Serial.println("Pen Down");
          break;
          
      }
      
     delay(50);
     SetPosition(1,i);
     SetPosition(2,i);
     //SetPosition(3,i);
     i--;
   }
   
}

void relaxArm(){
    i=512; 
    SetPosition(2,i);
    SetPosition(1,i);
    SetPosition(3,450);
}

void penUp(){
    SetPosition(3, 350);
}

void penDown(){
    SetPosition(3, 450);
}

