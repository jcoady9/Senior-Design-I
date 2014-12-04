/*
  Robot.cpp - Library for Robot object to control arm outside of main
  Created November 17, 2014
  Released into the public domain.

*/

#include <BioloidController.h>
#include <ax12.h>
#include <Robot.h>
#include <Motors2.h>
#include <stdlib.h>
#include <math.h>

Robot::Robot()
//vertex arrays for important coordinates on the plane of drawing
	: topRight {534, 404},
	  bottomLeft {795, 179},
	  bottomRight {762, 98},
	  deadCenter {684, 233},
	  relaxed {538, 520},
	  upOrDown {350, 525}
{
	 //starting coordinates for the motors to position to top left of drawing area
	 backMotor = relaxed[1];
	 frontMotor = relaxed[2];


}

//lift the pen
void Robot::penUp()
{
  	SetPosition(3, upOrDown[1]);
}

//drop the pen
void Robot::penDown()
{
  	SetPosition(3, upOrDown[2]); 
}

//move the arm back to the top left corner
void Robot::relaxArm(BioloidController bioloid)
{
	penUp();
	bioloid.poseSize = 1; 
	bioloid.readPose();//find where the servos are currently
	bioloid.setNextPose(1, relaxed[1]);  
	bioloid.setNextPose(2, relaxed[2]); 
	
	bioloid.interpolateSetup(500); // setup for interpolation from current->next

	while(bioloid.interpolating > 0)
	{ 
	 // do this while we have not reached our new pose
	 bioloid.interpolateStep();     // move servos, if necessary. 
	 delay(3);
	}
}

//move the arm to the top right corner of the drawing plane
void Robot::topRightCorner()
{
	  backMotor = topRight[0];
	  frontMotor = topRight[1];
	  SetPosition(1, backMotor);
	  SetPosition(2, frontMotor);  
}


//move to the bottom right corner of the drawing plane
void Robot::bottomRightCorner()
{
	  backMotor = bottomRight[0];
	  frontMotor = bottomRight[1];
	  SetPosition(1, backMotor);
	  SetPosition(2, frontMotor);
}

//move to the bottom left corner of the drawing plane
void Robot::bottomLeftCorner()
{
	  backMotor = bottomLeft[0];
	  frontMotor = bottomLeft[1];
	  SetPosition(1, backMotor);
	  SetPosition(2, frontMotor);
}

//move the the very center of the drawing plane
void Robot::toDeadCenter()
{
	 backMotor = deadCenter[0];
	 frontMotor = deadCenter[1];
	 SetPosition(1, backMotor);
	 SetPosition(2, frontMotor); 
}

void Robot::drawLine(int x1, int y1, int x2, int y2, BioloidController bioloid)
{
	       
	bioloid.poseSize = 2; // load two poses in, one for each vertex
	bioloid.readPose();//find where the servos are currently
	
	bioloid.setNextPose(1, x1);  //set the coordinates for the vertex to which the arm is moving first
	bioloid.setNextPose(2, y1); 

	bioloid.interpolateSetup(500); // setup for interpolation from current->next

	while(bioloid.interpolating > 0)
	{ 
	 // do this while we have not reached our new pose
	 bioloid.interpolateStep();     // move servos, if necessary. 
	 delay(3);
	}

	penDown();

	bioloid.readPose();//find where the servos are currently
	bioloid.setNextPose(1, x2);  
	bioloid.setNextPose(2, y2); 

	bioloid.interpolateSetup(1000); // setup for interpolation from current->next over 1/2 a second
	while(bioloid.interpolating > 0)
	{  
	// do this while we have not reached our new pose
	 bioloid.interpolateStep();     // move servos, if necessary. 
	 delay(3);
	}
} 


