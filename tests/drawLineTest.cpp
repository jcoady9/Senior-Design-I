#include<stdio.h>
#include<errno.h>

#include "../include/drawLine.h"

using namespace std;
const char * filename = "testOutput.txt";
int drawLine();

int main(){
	printf("-----------------------------------------------\n");
	printf("\Testing the drawLine simulation...\n");
	printf("-----------------------------------------------\n");

	//Run it
	drawLine();

	

}

