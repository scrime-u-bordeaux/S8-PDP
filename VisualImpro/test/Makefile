CXX = g++
CXXFLAGS = -lcppunit -Wall

all: test.bin

test.bin: TestMultiCorrel.o TestMain.o
	$(CXX) -o test.bin TestMultiCorrel.o TestMain.o $(CXXFLAGS)

TestMultiCorrel.o: TestMultiCorrel.cpp
	$(CXX) TestMultiCorrel.cpp -c $(CXXFLAGS) -o TestMultiCorrel.o

TestMain.o: TestMain.cpp
	$(CXX) TestMain.cpp -c $(CXXFLAGS) -o TestMain.o

clean:
	rm -rf *.o test.bin
