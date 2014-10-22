
#ifndef _VERTEXSEARCH_H__
#define _VERTEXSEARCH_H__

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


//corner detection
cv::Mat detectCorners(cv::Mat src);

//line detection
cv::Mat lineDetection(cv::Mat src);

cv::vector<cv::Vec2f> findLineFamily(cv::Mat graySrc);
cv::vector<cv::Vec4f> mergeLines(cv::vector<cv::Vec4i> lines, cv::vector<cv::Vec2f> line_family);
void vectorSort(cv::vector<cv::Vec2f> &vec);
void insertionSort(cv::vector<cv::Vec2f> &vec);
bool inRange(cv::Vec2f center, cv::Vec2f point);
void findEndpoints(cv::vector<cv::Vec4i> endpoint_vec);

#endif
