#include "../include/RobotComm.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
**method for sending coordinates to the robocontroller
**x1 and y1 are the current vertex's coordinates
**x2 and y2 are the next vertex's coordinates. 
returns -1 if an
*/
void sendCoordinates(int x1, int y1, int x2, int y2){
    FILE *file;
    file = fopen("testfile.txt","w");  //Opening device file(/dev/ttyUSB0)
    fprintf(file,"%d,%d,%d,%d\n",x1,y1,x2,y2); //Writing to the file. Seperate coordinates using commas
    fclose(file);
}
 

/*
**Method for checking if robot is finished drawing last line 
**returns -1 if no acknowledgement from robot is recieved
*/
int receiveACK(){
	fstream file;
	file.open("testfile.txt");
 	char  *data1 = NULL;
    	//file = fopen("testfile.txt","r");//open the file in read only mode
	if(!file.is_open())
	{
		cout << "Problem opening file.\n";
		return -1;
	}
	file.seekg(EOF); // go to the end of file
	while(true)
	{
		file.unget(); //go back two chars
		file.unget();
		char in = file.get();
		if(in == '\n')
		{
                        //get line from file until space is encountered and put it in data1
			file.getline(data1,' ');
			break;
		}
	}
	
	cout << "Data: " << data1 <<  endl; 
	return 0; 
}
