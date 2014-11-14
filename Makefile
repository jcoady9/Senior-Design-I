#A makefile for the senior design project

CC=g++

#compiler flags
CFLAGS= -Wall -ggdb

EXE= project

TEST_EXE= vertextest linetest vec2vertexTest drawtest imageProcTest scaleTest drawLineTest

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
	$(CC) $(CFLAGS) src/vertex.cpp src/line.cpp src/draw.cpp src/drawImageSimulator.cpp src/vec2vertex.cpp tests/vec2vertexTest.cpp src/RobotComm.cpp -o vec2vertexTest $(LIBS) $(LFLAGS)
	$(CC) $(CFLAGS) src/vertex.cpp src/line.cpp src/drawImageSimulator.cpp tests/drawLineTest.cpp -o drawLineTest $(LIBS) $(LFLAGS)
	$(CC) $(CFLAGS) src/vertex.cpp src/line.cpp  src/drawImageSimulator.cpp src/RobotComm.cpp src/draw.cpp tests/drawTests.cpp  -o drawtest  $(LIBS) $(LFLAGS)
	$(CC) $(CFLAGS) src/vertexSearch.cpp tests/imageProcTests.cpp  -o imageProcTest $(LIBS) $(LFLAGS)
	$(CC) $(CFLAGS) src/vertex.cpp src/line.cpp src/scale.cpp tests/scaleTest.cpp -o scaleTest
	

#clean the project directory of all object & executable files
clean:
	rm -f *.o *.exe *~ */*.cpp~ */*.h~ $(EXE) $(TEST_EXE)
