/*
  Robot.cpp - Library for Robot object to control arm outside of main
  Created by Shane Bonner, November 17, 2014
  Released into the public domain.


#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>
#include <stdlib.h>
#include <math.h>
#include "Robot.h"



Robot::Robot()
//vertice arrays for important coordinates on the plane of drawingHello
: topRight {355, 730},
  bottomLeft {995, 100},
  bottomRight {815, 100},
  deadCenter {765, 230} 
{
 //starting coordinates for the motors to position to top left of drawing area
 backMotor = 425;
 frontMotor =  730;


}

Robot::~Robot()
{
 //Deallocate memory
 delete[] topRight;
 delete[] bottomLeft;
 delete[] bottomRight;
 delete[] deadCenter;
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
 penUp();
 backMotor = x1;
 frontMotor = y1;
 SetPosition(1, backMotor);
 SetPosition(2, frontMotor);

 //as x increases on the plane, y decreases
 //double xDiff = x2 - x1;
 //double distance = sqrt(((pow(xDiff, 2)) + (pow(yDiff,2))); 
// delay(100);

 penDown();
 backMotor = x2;
 frontMotor = y2;
 SetPosition(1, backMotor);
 SetPosition(2, frontMotor);
 

}
*/

