#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>
#include <stdlib.h>


// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);


int i, i1;
const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields

int num;
char input;
int buff[10]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int points[5]; 
int j,p;


void setup(){
    i = 700;
    i1 = 300;
    j=-1;
    SetPosition(3, 450);
    Serial.begin(9600); //start serial communications at 38400bps
}

void loop(){

 if(Serial.available()>0){
   delay(20); //wait for all information
   readCoordinates();
  }
    // SetPosition(1,i);
    // SetPosition(2,i1);

  /*while(i<600){
     delay(35);
     SetPosition(1,i);
     SetPosition(2,i);
     i++;*/
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
         
         case 'm':
            i+= 10; //moves down and to rightn
            break; 
            
         case 'n':
            i-= 10; //moves to left in arch
            break; 
          
           case 'b':
            i1+= 10; //moves down and to rightn
            break; 
          
           case 'v':
            i1-= 10; //moves down and to rightn
            break; 
          
          case 'l':
           i +=5;
           SetPosition(1,i);
           i1-=20;
            SetPosition(2,i1);
            break;  
          
           case 'r':
            relaxArm();
            break;    
      }
      /* Serial.print("motor 1 = ");
       Serial.println(i);
       Serial.print("motor 2 = ");
       Serial.println(i1);*/
   /*}
   
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
     }*/
}

void relaxArm(){
    i=700; 
   i1=300; 
    SetPosition(2,i);
    SetPosition(1,i1);
    SetPosition(3,450);
}

void penUp(){
    SetPosition(3, 350);
}

void penDown(){
    SetPosition(3, 480);
}

void readCoordinates(){
  p=0;
  while(Serial.available()>0 && p<5)
    {
        input=Serial.read();

        if(input == ','){
        }
        else{
          points[p] =  input - '0'; 
         /*test current points are recieved */
         Serial.print("P");
         Serial.print(p);
         Serial.print("= ");
         Serial.println(points[p]);
          p++; 
       }
    }      
   int checksum = points[0] + points[1] + points[2] + points[3];
     if(checksum == points[4]){
       //TODO: call draw line method here
       Serial.print("y"); //correct checksum and line is drawn
     }else{
        Serial.print("n"); //wrong checksum, resend 
     }
      Serial.flush();
   
}

int determineLineLength(){
  
}
//methond to convert char to an int
int calc()
{
  int num=0,x=0;
 
    for(x;x<=j;x++){
          num=num+(buff[x]-48)*pow(10,j-x);
    }     
     
    return num;
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

