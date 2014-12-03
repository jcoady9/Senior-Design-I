#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>
#include <stdlib.h>
#include <Robot.h>

// we always need to create an instance of the bioloid control, usually with baud = 1Mbps.
BioloidController bioloid = BioloidController(1000000);

char input;
char buff[5], ack ='0';
int points[5] = {0,0,0,0,0}; 
int testPoints[5] = {560,350,685,200,2080};
int p, b, num, j;

Robot robot; //TESTING OUT MODEL OBJECT

void setup(){
    
  //robot is already set to topLeft coordinates
    robot.penUp();
    Serial.begin(9600); //start serial communications at 38400bps
}

void loop(){

  delay(50);
  Serial.print(ack);
  Serial.flush();
  /*Serial.print(robot.backMotor);
  Serial.println();
  Serial.print(robot.frontMotor);
  Serial.println();*/
  
    // SetPosition(1,robot.backMotor);
    // SetPosition(2,robot.frontMotor);
   if(Serial.available()>0){
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
            
         case 't': //test case
                  
               
               bioloid.poseSize = 2;//
               bioloid.readPose();//find where the servos are currently
               Serial.println("First Pose");
                bioloid.setNextPose(1, testPoints[0]);  
                bioloid.setNextPose(2,testPoints[1]); 
                
                bioloid.interpolateSetup(5000); // setup for interpolation from current->next over 1/2 a second
               while(bioloid.interpolating > 0)
               {  // do this while we have not reached our new pose
                 bioloid.interpolateStep();     // move servos, if necessary. 
                 delay(3);
               }
               robot.penDown();
               Serial.println("Next position");
               bioloid.readPose();//find where the servos are currently
               
                bioloid.setNextPose(1,testPoints[2]);  
                bioloid.setNextPose(2, testPoints[3]); 
                
                bioloid.interpolateSetup(5000); // setup for interpolation from current->next over 1/2 a second
               while(bioloid.interpolating > 0)
               {  // do this while we have not reached our new pose
                 bioloid.interpolateStep();     // move servos, if necessary. 
                 delay(3);
               }
           //robot.drawLine(testPoints[0],testPoints[1],testPoints[2],testPoints[3]); //TEST LINE WITHOUT PROCESSING
           break;
         
         
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
            
           case 'a': //coordinates have been sent
            //wait for all information
              delay(50); 
              //reset buffer each time new points come in
              j=0;
              for(j;j<5;j++){
                  buff[j] = '0';
                  points[j] = -1; 
              }
              readCoordinates();
    
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
}

void readCoordinates(){
  p=0;
  b=-1;
  ack = '0';
  while(Serial.available()>0)
    {
        input=Serial.read();
        
        if(input == ','){//comma has been reached, convert numbers from buffer to in
         points[p] = calc();
         b=-1;
         //Serial.println(points[p]);
         p++;
        }
        else{//value is not a comma, add to buffer
          b++;
          buff[b]=input;
       }
    }     
    
    int checksum = points[0] + points[1] + points[2] + points[3];
    if(checksum == points[4]){
      //draw the line here
      robot.drawLine(points[0],points[1],points[2],points[3]);
      Serial.print("y"); //correct checksum and line is drawn
      ack = 'y';
    }else{
      Serial.print("n"); //wrong checksum, resend 
      ack = 'n';
    }
    Serial.flush();
   
}

//methond to convert char to an int
int calc()
{
    int num=0,x=0;
 
    for(x;x<=b;x++){
          num=num+(buff[x]-'0')*pow(10,b-x);
    }
    if(num > 100){
     num=num+1;  
    }
    return num;
}


