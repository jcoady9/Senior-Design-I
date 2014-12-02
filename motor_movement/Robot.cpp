/*
  Robot.cpp - Library for Robot object to control arm outside of main
  Created by Shane Bonner, November 17, 2014
  Released into the public domain.


#include <BioloidController.h>
#include <ax12.h>
#include <Robot.h>
#include <Motors2.h>
#include <stdlib.h>
#include <math.h>




Robot::Robot()
//vertice arrays for important coordinates on the plane of drawing
: topRight {355, 730},
  bottomLeft {995, 100},
  bottomRight {815, 100},
  deadCenter {765, 230} 
{
 //starting coordinates for the motors to position to top left of drawing area
 backMotor = 425;
 frontMotor =  730;


}

//lift the pen
void Robot::penUp()
{
  SetPosition(3, 350);
}

//drop the pen
void Robot::penDown()
{
  SetPosition(3, 480); 
}

//move the arm back to the top left corner
void Robot::relaxArm()
{
  backMotor = 425;
  frontMotor = 730;
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
 Serial.println();

 double slope = yDiff / xDiff;
 Serial.println(slope);
 double distanceMoved = 0;
 double hypotenuse = 0;
 double slopeMod = ((5)*slope); //modified value of slope to add 
 Serial.println(slopeMod);
 double pythag = 0;

 while(distanceMoved < distance){ //&& backMotor >= 355 && backMotor <= 995 && frontMotor <= 730 && frontMotor >= 100){
  if(slope < 0){
	Serial.println(distance);
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

  }else{
	delay(50);
	backMotor += 5; 
	SetPosition(1,backMotor);
	frontMotor += slopeMod; //slope is positive, still add the slopeMod
	SetPosition(2,frontMotor); 
	hypotenuse += sqrt((frontMotor*frontMotor)+(backMotor * backMotor));
	distanceMoved += hypotenuse;
  }
 }

 penUp();

} 
*/



