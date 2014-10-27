#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>

// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

int i;
void setup(){
    i = 512;
    Serial.begin(9600); //start serial communications at 38400bps
}

void loop(){
    // set AX-12 servo with ID=1, to position i, where 0=<i<950 because of extention
   int inByte = Serial.read();
   readCoordinates();
       
      switch (inByte)
      {
        case '0':    
          relaxArm();
          exit(0);
        break;    
      }
  /* while(i<600){
     delay(35);
     SetPosition(1,i);
     SetPosition(2,i);
     SetPosition(3,i);
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
   
   while(i>400){
     switch (inByte)
      {
        case '0':    
          relaxArm();
          exit(0);
        break;    
      }
      
     delay(50);
     SetPosition(1,i);
     SetPosition(2,i);
     SetPosition(3,i);
     i--;
   }*/
   
}

void relaxArm(){
    i=512; 
    SetPosition(2,i);
    SetPosition(1,i);
}

void readCoordinates(){
int input;
int buff[5];
int j=-1;
while(j<5){
  
  if(Serial.available()>0){
          input=Serial.read();
          Serial.println("hello");
          if(input==','){
              j=-1; 
              Serial.println("hello?");
          }else{
              j++;
              buff[j]=input;
          }
    Serial.println(buff[0]);
    Serial.println(buff[1]);
    Serial.println(buff[2]);
    Serial.println(buff[3]);
    Serial.println(buff[4]);
    Serial.println("DONE\n");
  } 

}
    
}

