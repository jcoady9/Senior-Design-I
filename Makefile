#A makefile for the senior design project

CC=g++

#compiler flags
CFLAGS= -Wall -ggdb

EXE= project
TEST_EXE= vertextest linetest

#location directory of opencv library files
LFLAGS= -L /usr/local/lib
#opencv library files being used
LIBS= -l opencv_core -l opencv_highgui -l opencv_imgproc

#compile all project code
all :
	$(CC) $(CFLAGS) src/*.cpp -o project $(LIBS) $(LFLAGS)

#compile all test code
test:
	$(CC) $(CFLAGS) src/vertex.cpp src/line.cpp tests/vertexTests.cpp -o vertextest
	$(CC) $(CFLAGS) src/vertex.cpp src/line.cpp tests/lineTests.cpp -o linetest
	$(CC) $(CFLAGS) src/vertex.cpp src/line.cpp src/dfs.cpp tests/dfsTests.cpp src/RobotComm.cpp -o dfstest

#clean the project directory of all object & executable files
clean:
	rm -f *.o *.exe *~ $(EXE) $(TEST_EXE)
