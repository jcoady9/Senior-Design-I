/*
  Robot.cpp - Library for Robot object to control arm outside of main
  Created November 17, 2014
  Released into the public domain.


#include <BioloidController.h>
#include <ax12.h>
#include <Robot.h>
#include <Motors2.h>
#include <stdlib.h>
#include <math.h>




Robot::Robot()
//vertex arrays for important coordinates on the plane of drawing
: topRight {566, 460},
  bottomLeft {995, 100},
  bottomRight {815, 160},
  deadCenter {699, 225} 
{
 //starting coordinates for the motors to position to top left of drawing area
 backMotor = 566;
 frontMotor = 460;


}

//lift the pen
void Robot::penUp()
{
  SetPosition(3, 350);
}

//drop the pen
void Robot::penDown()
{
  SetPosition(3, 525); 
}

//move the arm back to the top left corner
void Robot::relaxArm()
{
  backMotor = 566;
  frontMotor = 460;
  SetPosition(1, backMotor);
  SetPosition(2, frontMotor);
  SetPosition(3, 450);  
}

//move the arm to the top right corner
void Robot::topRightCorner()
{
  backMotor = topRight[0];
  frontMotor = topRight[1];
  SetPosition(1, backMotor);
  SetPosition(2, frontMotor);  
}


//move to the bottom right corner
void Robot::bottomRightCorner()
{
  backMotor = bottomRight[0];
  frontMotor = bottomRight[1];
  SetPosition(1, backMotor);
  SetPosition(2, frontMotor);
}

//move to the bottom left corner
void Robot::bottomLeftCorner()
{
  backMotor = bottomLeft[0];
  frontMotor = bottomLeft[1];
  SetPosition(1, backMotor);
  SetPosition(2, frontMotor);
}

void Robot::toDeadCenter()
{
 backMotor = deadCenter[0];
 frontMotor = deadCenter[1];
 SetPosition(1, backMotor);
 SetPosition(2, frontMotor); 
}

void Robot::drawLine(int x1, int y1, int x2, int y2)
{
// penUp();

 delay(1000);
 backMotor = x1;
 frontMotor = y1;
 SetPosition(1, backMotor);
 delay(1000);
 SetPosition(2, frontMotor);

 //as x increases on the plane, y decreases
 penDown();
 double xDiff = (double) x2 - (double) x1;
 double yDiff = (double) y2 - (double) y1;
 double distance = sqrt((xDiff * xDiff)+(yDiff*yDiff)); //distance formula
// Serial.println();
 Serial.println(distance);
 double slope = yDiff / xDiff;
 //Serial.println(slope);
 double distanceMoved = 0;
 double hypotenuse = 0;
 double slopeMod = ((5)*slope); //modified value of slope to add 
// Serial.println(slopeMod);
 double pythag = 0;

 while(distanceMoved < distance){ //&& backMotor >= 355 && backMotor <= 995 && frontMotor <= 730 && frontMotor >= 100){
  //if(slope < 0){
	
	IK(backMotor,frontMotor, x2,y2);
	delay(50);
	backMotor += 5;
	frontMotor += slopeMod; //slope is negative so add the slopeMod

 	Serial.println(backMotor);

	Serial.println(frontMotor);

	SetPosition(1,backMotor);
  	SetPosition(2,frontMotor); 

	pythag = sqrt((slopeMod*slopeMod)+(5*5)); //moving down then over, so the hypotenuse of the triangle
 	Serial.println(pythag);
	
	hypotenuse = 0; //reset each time
  	hypotenuse += pythag; //sqrt((frontMotor*frontMotor)+(backMotor * backMotor));
	
	Serial.println(hypotenuse);  	
	
	distanceMoved += hypotenuse;

	Serial.println(distanceMoved);

	Serial.println("END ROUND");

 // }else{
	delay(50);
	backMotor += 5; 
	SetPosition(1,backMotor);
	frontMotor += slopeMod; //slope is positive, still add the slopeMod
	SetPosition(2,frontMotor); 
	hypotenuse += sqrt((frontMotor*frontMotor)+(backMotor * backMotor));
	distanceMoved += hypotenuse;
  //}
 }

 penUp();

} 

int Robot::IK(long Xcurrent, long Ycurrent, long Xnext, long Ynext){//where the robot is moving to 

 float B = 0.0;                                    //distance that is needed to move
 float q1= 0.0;                                   //angle between X-axis and line to be drawn
 float q2= 0.0;                                   //angle of front motor link l1
 float Q1= 0.0;                                   //Q1: angle between x-axis and "l1"
 float Q2= 0.0;                                   //Q2: angle between "l1" and "l2"
 long l1 = 60;                              //l1: length first bracket
 long l2 = 70;                            //l2: length of tip bracket

//Where the robot is going
 long Xpos= 0.0;                                  //x coordinate where the arm should move to
 long Ypos= 0.0;                                  //y corrdinate where the arm should move to      



 Xpos = abs(Xcurrent-Xnext);                                 //relative distance to travel on x
 Ypos = abs(Ycurrent-Ynext);                                 //relative distance to travel on y

  B = sqrt(Xpos*Xpos + Ypos*Ypos);                        //the Pythagorean theorem
 q1 = atan2(Ypos,Xpos);
 q2 = acos((l1*l1 - l2*l2 + B*B)/(2*l1*B));              //the law of cosines         
 Q1 = degrees(q2) - degrees(q1) + 90;                                     
 Q2 = degrees(acos((l1*l1 + l2*l2 - B*B)/(2*l1*l2)));    //the law of cosines    


 //---------------------------------------------------------------------------------------------------------------------------
 //-----------------------------------------------| trouble shooting| --------------------------------------------------------
 //---------------------------------------------------------------------------------------------------------------------------

 Serial.println(Q1);
 Serial.println(Q2);
 Serial.println();
 Serial.println(B);
 Serial.println();
 Serial.println(q1);
 Serial.println(q2);
 Serial.println(degrees(q1));
 Serial.println(degrees(q2));
 Serial.println();
 Serial.println(Xpos);
 Serial.println(Ypos);
 Serial.println();
 Serial.println("------------------------------------------------------");
 Serial.println();


 delay(5000);  
}

*/


