CXX = g++
CXXFLAGS = -std=c++11 -ldl -lsndfile -lcppunit -Wall -Wextra

EXEC= tests
SRC= TestMain.cpp $(wildcard TestCoeff/*.cpp) $(wildcard TestMix/*.cpp)\
$(wildcard TestPreproc/*.cpp) $(wildcard TestColor/*.cpp)\
$(wildcard ../process/*/*.cpp) $(wildcard TestClasses/*.cpp)
INC = ../Matrix.cpp ../RGB.cpp ../ProcessMultiCorrel.cpp ../Connection.cpp
OBJ= $(SRC:.cpp=.o) $(INC:.cpp=.o)

all: $(EXEC)

tests : $(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@mv $(OBJ) obj/

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

.PHONY: clean

clean:
	rm -rf *.o */*.o ../*.o ../process/*/*.o obj/*.o tests
