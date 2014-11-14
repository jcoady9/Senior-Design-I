
#ifndef _VERTEXSEARCH_H__
#define _VERTEXSEARCH_H__

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//run all image processing methods
cv::vector<cv::Vec4i> processImage(cv::Mat image);

//corner detection
void detectCorners(cv::Mat src, cv::Mat & dst);

//line detection
cv::vector<cv::Vec4i> lineDetection(cv::Mat & src);

//detect contours (curved lines)
void contourDetection(cv::Mat src, cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> & hierarchy);

//thins thicker lines to reduce detection of invalid lines
void thinningIteration(cv::Mat& im, int iter);
void thinning(cv::Mat& im);

cv::vector< cv::vector<cv::Point> > removeRedundantContours(cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> lines);
double distance(const cv::Point & p1, const cv::Point & p2);

//converts vector<vector<point>> to vector<vec4i>
cv::vector<cv::Vec4i> pointsToVec4i(cv::vector< cv::vector<cv::Point> > contours);

#endif //VERTEXSEARCH_H
