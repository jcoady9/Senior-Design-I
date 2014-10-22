
#include <opencv2/highgui/highgui.hpp>

void heapsort(cv::vector<cv::Vec2f> &vec);
void buildMaxHeap(cv::vector<cv::Vec2f> &vec);
void maxHeapify(cv::vector<cv::Vec2f> &vec, size_t pos, size_t size);
