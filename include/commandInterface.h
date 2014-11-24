#ifndef COMMANDINTERFACE_h
#define COMMANDINTERFACE_h

/*
@author Shane Bonner
Class interface that will be used to abstract all commands sent from C code
to the arduino robot. Commands will mostly consist of a single char character
sent through by the toString() method.


*/

#include <stdio.h>
#include <string>

class commandInterface
{
	public:
		std::string toString(){
			return "";
		}


};





#endif //COMMANDINTERFACE
