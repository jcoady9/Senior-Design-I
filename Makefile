#A makefile for the senior design project

CC=g++

#compiler flags
CFLAGS= -Wall -ggdb

#location directory of opencv library files
LFLAGS= -L /usr/local/lib

#opencv library files being used
LIBS= -l opencv_core -l opencv_highgui

#compile all project code
all :
	$(CC) $(CFLAGS) src/*.cpp -o project $(LIBS) $(LFLAGS)

#compile all test code
test:
	$(CC) $(CFLAGS) tests/*.cpp -o vertextest

