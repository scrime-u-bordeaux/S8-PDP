INC_DIR = ../utilities

CXX = g++
CXXFLAGS = -std=c++11 -lsndfile -lcppunit -Wall -Wextra

EXEC=test.bin
SRC= $(wildcard *.cpp) ../ProcessMultiCorrel.cpp ../Connection.cpp ../utilities.cpp
OBJ= $(SRC:.cpp=.o)
#OBJDIR= ./obj

all: $(EXEC)

test.bin : $(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@mv *.o ../*.o obj/

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@



.PHONY: clean

clean:
	rm -rf *.o ../*.o obj/*.o test.bin
