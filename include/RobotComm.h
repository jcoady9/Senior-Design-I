//RobotComm.h

#ifndef _ROBOTCOMM_H__
#define _ROBOTCOMM_H__

#include <stdio.h>
#include "../include/Line.h"
#include "../include/commandInterface.h"
#include <string>

class RobotComm {
	private:
		const char * TfileName;//test
		const char * RfileName;//real
		int checkSum;

	public:
		RobotComm();//constructor
		~RobotComm();

		/*
			**Method prototype for sending coordinates to the robocontroller
			**x1 and y1 are the current vertex's coordinates
			**x2 and y2 are the next vertex's coordinates. 
		*/
		void sendCoordinates(std::string coords, FILE * file);  

		/*
			**Method prototype for checking if coordinates were recieved properly through a serialStream. 
			**returns -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
		*/
		int receiveACKSerial(FILE * file);
	
		/*
			**Accepts first vertex and accesses its other vertex via the nextVertex() functionality
			**Send the coordinates to the robot. 
			**Wait for the acknowledgement to come back. 
		*/
		void drawLineWork(std::string coords, FILE * comm);
		
		/*
			**Based on what command was entered, send command to robot
		*/
		void RobotCommunication(commandInterface* c);

};
#endif
