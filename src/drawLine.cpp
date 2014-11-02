#include <stdio.h>
#include <errno.h>
#include <vector>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int drawPic(){

	FILE *file;
	file = fopen(filename,"w"); 
	Mat img;

	if(!file){
		cout << "Test file does not exist" << "\n";
		exit(1);
	}
	
	string coordinates;
	char data[128];

	ifstream filestream;
	filestream.open(filename);
	
	data[0]=0; // read in each line of the file until we're done 
	do{ 
		if(!isspace(data[0]) && data[0] != 0) {
		    lastLine = data; 
		}
		 
        }while (filestream.getline(data, 256)); 

	//End of file reached, close stream
	filestream.close(); 
	
	cout << "data = " << lastLine << "\n";

	std::vector<int> vect;

	std::stringstream ss(str);

	int i;

	while (ss >> i)
	{
	    vect.push_back(i);

	    if (ss.peek() == ',')
		ss.ignore();
	}
	
	//create a black image
	img = np.zeros((512,512,3), np.uint8);

	//draw a diagonal blue line with the parsed coordinates
	cv2.line(img,(0,0),(vec[0],vect[1]),(vect[2],vect[3]),5);

	
	//alternative attempt at drawing the line
	//IplImage* imageScribble = cvCreateImage(cvSize(320,240),8,3);
	//cvZero(imgScribble);
	//cvSet(imgScribble, cvScalar(0,0,0); *****Used to set any color*****
	//cv2.line(img,(0,0),(vec[0],vect[1]),(vect[2],vect[3]),5);

	
}	
