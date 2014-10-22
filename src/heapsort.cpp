
#include "../include/heapsort.h"

void heapsort(cv::vector<cv::Vec2f> &vec){

	size_t heap_size = vec.size();
	
	buildMaxHeap(vec);	

	for(size_t i = vec.size(); i >= 2; i--){
		cv::Vec2f temp = vec[i];
		vec[i] = vec[0];
		vec[0] = temp;
		heap_size--;
		maxHeapify(vec, 0, heap_size);
	}

	return;

}

void buildMaxHeap(cv::vector<cv::Vec2f> &vec){

	for(size_t i = ((vec.size()) / 2); i >= 1; i--){
		maxHeapify(vec, i, vec.size());
	} 

	return;
}

void maxHeapify(cv::vector<cv::Vec2f> &vec, size_t pos, size_t size){
	
	size_t left, right;
	size_t largest = -1;

	if(pos > 0){
		left = (2 * pos);
		right = left + 1;
	}//else{
		//left = 1; 
		//right = 2;
	//}

	if(left <= size && vec[left][0] > vec[size][0]){
		largest = left;
	}else{
		largest = pos;
	}


	if(right <= size && vec[right][0] > vec[largest][0]){
		largest = right;
	} 

	if(largest != pos){
		cv::Vec2f temp = vec[pos];
		vec[pos] = vec[largest];
		vec[largest] = temp;
		maxHeapify(vec, largest, size);
	}


}
