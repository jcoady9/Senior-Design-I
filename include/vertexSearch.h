
#ifndef _VERTEXSEARCH_H__
#define _VERTEXSEARCH_H__

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::vector<cv::Vec4i> processImage(cv::Mat image);

//corner detection
void detectCorners(cv::Mat src, cv::Mat & dst);

//line detection
cv::vector<cv::Vec4i> lineDetection(cv::Mat src);

void contourDetection(cv::Mat src);

cv::vector<cv::Vec2f> findLineFamily(cv::Mat graySrc);
cv::vector<cv::Vec4f> mergeLines(cv::vector<cv::Vec4i> lines, cv::vector<cv::Vec2f> line_family);
void vectorSort(cv::vector<cv::Vec2f> &vec);
void insertionSort(cv::vector<cv::Vec2f> &vec);
bool inRange(cv::Vec2f center, cv::Vec2f point);

void thinningIteration(cv::Mat& im, int iter);
void thinning(cv::Mat& im);

#endif
