#ifndef Robot_h
#define Robot_h

/*
  Robot.h - Library header file for Robot object to control arm movements
  Created November 17, 2014
  Released into the public domain.

*/


class Robot
{
	public:
		Robot();
		
		//methods to move the arm to specific/important locations on the drawing plane
		void penUp();
		void penDown();
		void relaxArm(BioloidController bioloid);
		void topRightCorner();
		void bottomLeftCorner();
		void bottomRightCorner();
		void toDeadCenter();

		//main drawing function(s)		
		void drawLine(int x1, int y1, int x2, int y2, BioloidController bioloid);
		
		//field containing the position location of each dynamixel servo
		int frontMotor;
		int backMotor;
		
		//arrays to store important locations on the drawing plane
		int topRight[2];
		int bottomLeft[2];
		int bottomRight[2];
		int deadCenter[2];
		int relaxed[2];  
		int upOrDown[2]; //used for penUp/penDown
                int prevousCoord[2];
                int previousMotorAngle[2];

	private:
  
};

#endif //Robot_h
