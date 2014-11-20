#ifndef Robot_h
#define Robot_h

/*
  Robot.h - Library header file for Robot object to control arm movements
  Created by Shane Bonner, November 17, 2014
  Released into the public domain.

*/

class Robot
{
 public:
  Robot();
  void penUp();
  void penDown();
  void relaxArm();
  void topRightCorner();
  void bottomLeftCorner();
  void bottomRightCorner();
  void toDeadCenter();
  void drawLine(int x1, int y1, int x2, int y2);
    
  int frontMotor;
  int backMotor;
  
  int topRight[2];
  int bottomLeft[2];
  int bottomRight[2];
  int deadCenter[2];
    
   
  private:
    
    
  
};

#endif //Robot_h
