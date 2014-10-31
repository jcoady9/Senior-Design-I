#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>
#include <stdlib.h>

// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

int i, num;
char input;
int buff[10]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int points[4]; 
int j,p;

void setup(){
    i = 512;
    j=-1;
    p=0;
    SetPosition(3, 450);
    Serial.begin(9600); //start serial communications at 38400bps
}

void loop(){

  if(Serial.available()>0){
    readCoordinates();
  }
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
      }
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
  
  while(Serial.available()>0)
    {
          input=Serial.read();
   
          if(input == ','){
             num = calc();
            j=-1;
          }else{
              j++;
              buff[j]= input;
              points[p] =  input - '0'; 
              //Serial.print("P= ");
             // Serial.println(points[p]);
              p++; 
         }
          
    }
    int checksum = points[0] + points[1] + points[2] + points[3];
    //Serial.write("DONE(");
    //Serial.write("1");
   // Serial.write(")\n");
   // Serial.flush();
   // Serial.end();
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
