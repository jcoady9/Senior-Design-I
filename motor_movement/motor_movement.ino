#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>

// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

int i;
const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields

void setup(){
    i = 512;
    SetPosition(3, 450);
    Serial.begin(9600); //start serial communications at 38400bps
}

void loop(){
    // set AX-12 servo with ID=1, to position i, where 0=<i<950 because of extention
  readCoordinates();
  while(i<600){
     delay(35);
     SetPosition(1,i);
     SetPosition(2,i);
     i++;
        int inByte = Serial.read();
        switch (inByte)
        {
          case 'q':    
            relaxArm();
            exit(0);
            break;    
          
          case 'u':
            penUp();
            break;
          
          case 'd':
            penDown();
            break;      
      }
   }
   
   while(i>400){
       int inByte = Serial.read();
       switch (inByte)
        {
          case 'q':    
            relaxArm();
            exit(0);
          break; 
       
          case 'u':
            penUp();
            break;
        
          case 'd':
            penDown();
            break;
            
        }
        
       delay(50);
       SetPosition(1,i);
       SetPosition(2,i);
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
  }else{
   Serial.println(buff[0]);
    Serial.println(buff[1]);
    Serial.println(buff[2]);
    Serial.println(buff[3]);
    Serial hy.println(buff[4]);
    Serial.println("DONE\n");
    Serial.flush(); 
 }
}

int determineLineLength(){
  
}
    
}


//other test code I (Shane) wrote to try and communicate in a different way
/* if( Serial.available())
  {
    char ch = Serial.read();
    if(ch >= '0' && ch <= '9') // is this an ascii digit between 0 and 9?
    {
      // yes, accumulate the value
      values[fieldIndex] = (values[fieldIndex] * 10) + (ch - '0'); 
    }
    else if (ch == ',')  // comma is our separator, so move on to the next field
    {
      if(fieldIndex < NUMBER_OF_FIELDS-1)
        fieldIndex++;   // increment field index
    }
    else
    {
      // any character not a digit or comma ends the acquisition of fields
      // in this example it's the newline character sent by the Serial Monitor
      Serial.print( fieldIndex +1);
      Serial.println(" fields received:");
      for(int i=0; i <= fieldIndex; i++)
      {
        Serial.println(values[i]);
        values[i] = 0; // set the values to zero, ready for the next message
      }
      fieldIndex = 0;  // ready to start over
    }
  }
  */


