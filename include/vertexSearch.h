
#ifndef _VERTEXSEARCH_H__
#define _VERTEXSEARCH_H__

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::vector<cv::Vec4i> processImage(cv::Mat image);

//corner detection
void detectCorners(cv::Mat src, cv::Mat & dst);

//line detection
cv::vector<cv::Vec4i> lineDetection(cv::Mat & src);

//detect contours (curved lines)
void contourDetection(cv::Mat src, cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> & hierarchy);

void thinningIteration(cv::Mat& im, int iter);
void thinning(cv::Mat& im);

cv::vector< cv::vector<cv::Point> > removeRedundantContours(cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> lines);
double distance(cv::Point p1, cv::Point p2);

#endif //VERTEXSEARCH_H
