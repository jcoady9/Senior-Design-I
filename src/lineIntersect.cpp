//lineIntersect.cpp

#include <iostream>
#include <stddef.h>
#include <stdio.h>
#include "opencv2/core/core.hpp"

using namespace std;

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(cv::Vec2f p, cv::Vec2f q, cv::Vec2f r)
{
    if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) &&
        q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1]))
       return true;
 
    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(cv::Vec2f p, cv::Vec2f q, cv::Vec2f r)
{
    // See 10th slides from following link for derivation of the formula
    int val = (q[1] - p[1]) * (r[0] - q[0]) -
              (q[0] - p[0]) * (r[1] - q[1]);
 
    if (val == 0)
		return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool lineIntersect(cv::Vec2f p, cv::Vec2f q)
{
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p[0], q[0], p[1]);
	int o2 = orientation(p[0], q[0], q[1]);
	int o3 = orientation(p[1], q[1], p[0]);
	int o4 = orientation(p[1], q[1], q[0]);
	
	// General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p[0], p[1], q[0]))
		return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p[0], q[1], q[0]))
		return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p[1], p[0], q[1]))
		return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p[1], q[0], q[1]))
		return true;
 
    // Doesn't fall in any of the above cases
    return false; 
}
