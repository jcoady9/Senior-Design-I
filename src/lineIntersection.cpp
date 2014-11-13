/*//lineIntersection.cpp

//#include <stddef>
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/vertex.cpp"
#include "../include/line.cpp"

int numLines = 0;

lineIntersection(cv::Vec2f v)
{
	//Sort the points from left to right according to the x coordinate
	for(int i=0; i<v.size()-1; i++)
	{
		if(v[i][0] > v[i+1][0])
		{
			temp = v[i];
			v[i] = v[i+1];
			v[i+1] = v[i];
		}
	}
	
	//Process all points of lines
	for(i=0; i<2(numLines)-1; i++)
	{
		//If point is left end of line
		if(v[i] == v[i][0])
		{
			
			
			//Check to see if point intersects with its predecessor and successor
			if(intersect())
				return true;
			if(intersect())
				return true;
		}
		//Right end of line
		else
		{
			//Check to see if it intersects with the predecessor or successor
			if()
				return true;
				
			//Delete line from tree
		}
	}
	
	return false;
}

bool intersect(cv::Vec2f a, cv::Vec2f b)
{
	if()
}
*/


