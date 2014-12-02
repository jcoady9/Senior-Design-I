
#ifndef _VERTEXSEARCH_H__
#define _VERTEXSEARCH_H__

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "drawing.h"
#include "vertex.h"
#include "Line.h"

/*
 *class for processing an image
*/
class ImageProcessor {

public:

	ImageProcessor(); //constructor
	~ImageProcessor(); //destructor

	//run all image processing methods
	Drawing* processImage(cv::Mat & image);

	//line detection
	cv::vector<cv::Vec4i> lineDetection(cv::Mat & src);

	//detect contours (curved lines)
	void contourDetection(const cv::Mat & src, cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> & hierarchy);

	//thins lines to help reduce detecting invalid lines
	void thinning(cv::Mat& im);

	//removes redundant contours
	cv::vector< cv::vector<cv::Point> > removeRedundantContours(cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> lines);

	//computes the distance between two points
	double distance(const cv::Point & p1, const cv::Point & p2);

	//converts vector<vector<point>> to vector<vec4i>
	cv::vector<cv::Vec4i> pointsToVec4i(const cv::vector< cv::vector<cv::Point> > & contours);

	//Convert Vec4i into two verticies, then append them.
	Line vec2Vertex(cv::Vec4i vec);

private:

	//helper function to thin thicker lines to reduce detection of invalid lines
	void thinningIteration(cv::Mat& im, int iter);

};

#endif //VERTEXSEARCH_H
