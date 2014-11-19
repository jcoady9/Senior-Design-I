#include <Robot.h>

#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>
#include <stdlib.h>


// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields
char input;
char  buff[5], ack ='0';
int points[5] = {0,0,0,0,0}; 
int p, b, num, j;

Robot robot; //TESTING OUT MODEL OBJECT

void setup(){
    
  //robot is already set to topLeft coordinates
    robot.penUp();
    
    Serial.begin(9600); //start serial communications at 38400bps
}

void loop(){

 if(Serial.available()>0){
   //wait for all information
   delay(50); 
   
   //reset buffer each time new points come in
   j=0;
   for(j;j<6;j++){
     buff[j] = '0';
     points[j] = -1; 
   }
     readCoordinates();
  }
  delay(50);
  Serial.print(ack);
  Serial.println();
  Serial.print(robot.backMotor);
  Serial.println();
  Serial.print(robot.frontMotor);
  Serial.println();
  Serial.flush();
     SetPosition(1,robot.backMotor);
     SetPosition(2,robot.frontMotor);

        int inByte = Serial.read();
        switch (inByte)
        {
          case 'q':    
            robot.relaxArm();
            exit(0);
            break;    
          
          case 'u':
            robot.penUp();
            break;
          
          case 'd':
            robot.penDown();
            break; 
            
         case 't': //experimental case using the stored array points for quick access.
                   //all four corners should have this for easy maneuvering around the area of drawing
                   
           robot.topRightCorner();
           break;
         
         //TODO (SHANE WILL DO THIS) : finish the last few test cases for important corners/points
         //also we must better organize the test case letters 
         
         case 'm':
            robot.backMotor+= 10; //moves down and to rightn
            break; 
            
         case 'n':
            robot.backMotor-= 10; //moves to left in arch
            break; 
          
           case 'b':
            robot.frontMotor+= 10; //moves down and to rightn
            break; 
          
           case 'v':
            robot.frontMotor-= 10; //moves down and to rightn
            break; 
            
           case 'a':
            robot.drawLine(points[0],points[1],points[2],points[3]);
            break;
          
          case 'l':
           robot.backMotor +=5;
           SetPosition(1,robot.backMotor);
           robot.frontMotor-=20;
           SetPosition(2,robot.frontMotor);
           break;  
          
           case 'r':
            robot.relaxArm();
            break;    
      }
  
}

void readCoordinates(){
  p=0;
  b=0;
  ack = '0';
  while(Serial.available()>0 && p<5)
    {
        input=Serial.read();
        
        if(input == ','){//comma has been reached, convert numbers from buffer to int
         points[p] = calc();
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
    delay(5000);
    Serial.print("y\n"); //correct checksum and line is drawn
    ack = 'y';
    }else{
    Serial.print("n"); //wrong checksum, resend 
    ack = 'n';
    }
    Serial.flush();
   
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


