CXX = g++
CXXFLAGS = -lcppunit -Wall -Wextra

EXEC=test.bin
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

test.bin: $(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	@$(CXX) $< -c $(CXXFLAGS) -o $@

.PHONY: clean

clean:
	rm -rf *.o test.bin
