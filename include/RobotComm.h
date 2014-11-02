#ifndef _ROBOTCOMM_H__
#define _ROBOTCOMM_H__



/*
**Method prototype for sending coordinates to the robocontroller
**x1 and y1 are the current vertex's coordinates
**x2 and y2 are the next vertex's coordinates. 
returns -1 if an
*/
void sendCoordinates(int x1, int y1, int x2, int y2);  

/*
**Method prototype for checking if coordinates were recieved properly through a filestream. 
**returns -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
*/
int receiveACK();


/*
**Method prototype for checking if coordinates were recieved properly through a serialStream. 
**returns -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
*/
int receiveACKSerial();	


#endif
