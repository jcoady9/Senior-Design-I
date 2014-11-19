/*
  Robot.cpp - Library for Robot object to control arm outside of main
  Created by Shane Bonner, November 17, 2014
  Released into the public domain.
*/
/*
#include <BioloidController.h>
#include <ax12.h>
#include <Motors2.h>
#include <stdlib.h>
#include "../include/Robot.h"

Robot::Robot()
//vertice arrays for important coordinates on the plane of drawing
: topRight {355, 730},
  bottomLeft {995, 100},
  bottomRight {815, 100},
  deadCenter {765, 230} 
{
 backMotor = 425;
 frontMotor =  730;
 
 //vertices for important coordinates on the plane of drawing
 //topRight = {355, 730}; 
 //bottomLeft = {995, 100};
 //bottomRight = {815, 100}; //TopLeft is not needed because of the relaxArm() function
 //deadCenter = {765, 230};

}

void Robot::penUp()
{
  SetPosition(3, 350);
}

void Robot::penDown()
{
  SetPosition(3, 480); 
}

void Robot::relaxArm()
{
  backMotor = 425;
  frontMotor = 730;
  SetPosition(1, backMotor);
  SetPosition(2, frontMotor);
  SetPosition(3, 450);  
}

void Robot::topRightCorner()
{
  backMotor = topRight[0];
  frontMotor = topRight[1];
  SetPosition(1, backMotor);
  SetPosition(2, frontMotor);  
}

void Robot::bottomRightCorner()
{
  backMotor = bottomRight[0];
  frontMotor = bottomRight[1];
  SetPosition(1, backMotor);
  SetPosition(2, frontMotor);
}

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

*/

