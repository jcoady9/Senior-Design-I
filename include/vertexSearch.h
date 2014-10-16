
#ifndef _VERTEXSEARCH_H__
#define _VERTEXSEARCH_H__

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


//corner detection
cv::Mat detectCorners(cv::Mat src);

//line detection
cv::Mat lineDetection(cv::Mat src);

#endif
