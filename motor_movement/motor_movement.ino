#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>
#include <stdlib.h>


// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields
char input, ack;
char  buff[4];
int points[5] = {0,0,0,0,0}; 
int p, b, num, j, i, i1;

void setup(){
    i = 700;
    i1 = 300;
    ack = '0'; 
    SetPosition(3, 450);
    Serial.begin(9600); //start serial communications at 38400bps
}

void loop(){

 if(Serial.available()>0){
   delay(20); //wait for all information
   
   j=0;
   for(j;j<5;j++){//reset buffer each time new points come in
     buff[j] = '0'; 
   }
   if(ack != 'y'){
     readCoordinates();
   }
   /*if(ack != '0'){
    delay(50);
    Serial.write(ack); 
    Serial.flush();
  }*/
  }
  if(ack != '0'){
    delay(50);
    Serial.println(ack);
    Serial.flush(); 
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
  b=0;
  ack = '0';
  while(Serial.available()>0 && p<5)
    {
        input=Serial.read();
        if(input == ','){//comma has been reached, convertnumbers from buffer to int
         points[p] =calc();
         b=-1;
       // Serial.println(points[p]);
         p++;
        }
        else{//value is not a comma, add to buffer
          b++;
          buff[b]=input;
         
       }
    }     
    
    int checksum = points[0] + points[1] + points[2] + points[3];
   
    if(checksum == points[4]){
    //TODO: call draw line method here
    delay(1000);
    ack = 'y';
    //Serial.print("y\n"); //correct checksum and line is drawn
    }else{
      ack = 'n'; 
   // Serial.print("n\n"); //wrong checksum, resend 
    }
    //Serial.flush();
   
}

int drawline(){
  //coordinates are stored in the first four values 
  //of the points array
}

//methond to convert char to an int
int calc()
{
    int num=0,x=0;
 
    for(x;x<=b;x++){
          num=num+(buff[x]-48)*pow(10,b-x);
    }
    return num;
}

