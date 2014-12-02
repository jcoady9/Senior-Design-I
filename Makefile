#A makefile for the senior design project

CC=g++

#compiler flags
CFLAGS= -Wall -ggdb

EXE= project

TEST_EXE= vertextest vec2vertexTest drawtest imageProcTest scaleTest drawLineTest imageProcUnitTests

#location directory of opencv library files
LFLAGS= -L /usr/local/lib
#opencv library files being used
LIBS= -l opencv_core -l opencv_highgui -l opencv_imgproc

#compile all project code
all :
	$(CC) $(CFLAGS) src/*.cpp -o project $(LIBS) $(LFLAGS)

#compile all test code
test:
	$(CC) $(CFLAGS) src/vertex.cpp tests/vertexTests.cpp -o vertextest
	$(CC) $(CFLAGS) src/vertex.cpp src/Line.cpp tests/LineTests.cpp -o LineTest
	$(CC) $(CFLAGS) src/relaxCommand.cpp src/RobotComm.cpp src/commandInterface.cpp tests/robotRelaxTest.cpp -o relaxtest
	$(CC) $(CFLAGS) src/quitCommand.cpp src/RobotComm.cpp src/commandInterface.cpp tests/robotQuitTest.cpp -o quittest
	$(CC) $(CFLAGS) src/vertex.cpp  src/Line.cpp src/RobotComm.cpp src/commandInterface.cpp src/drawLineCommand.cpp tests/drawLineTest.cpp  -o drawLineTest  $(LIBS) $(LFLAGS)
	$(CC) $(CFLAGS) src/imageProcessor.cpp src/drawing.cpp src/vertex.cpp src/Line.cpp tests/imageProcUnitTests.cpp  -o imageProcUnitTests $(LIBS) $(LFLAGS)

#clean the project directory of all object & executable files
clean:
	rm -f */*.o */*.exe *~ */*.cpp~ */*.h~ $(EXE) $(TEST_EXE)
