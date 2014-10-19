
#ifndef _VERTEXSEARCH_H__
#define _VERTEXSEARCH_H__

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


//corner detection
cv::Mat detectCorners(cv::Mat src);

//line detection
cv::Mat lineDetection(cv::Mat src);


bool inRange(cv::Vec4i center, cv::Vec4i point);
void findEndpoints(cv::vector<cv::Vec4i> endpoint_vec);

#endif
