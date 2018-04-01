CXX = g++
CXXFLAGS = -shared -O3 -std=c++11 -Wl,--no-undefined -fPIC
SRC = $(wildcard Preproc/*.cpp) $(wildcard Color/*.cpp) $(wildcard Coeff/*.cpp)\
$(wildcard Mix/*.cpp)
INC = ../Matrix.cpp ../RGB.cpp
OBJ = $(SRC:.cpp=.o) $(INC:.cpp=.o)
EXEC = libprocess.so

all : $(EXEC)

$(EXEC) : $(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@mv $(OBJ) obj/

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

clean :
	rm -rf ../*.o */*.o libprocess.so
