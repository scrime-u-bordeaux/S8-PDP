OBJ_DIR = ../obj
SRC_DIR = ../src

CXX = g++
CXXFLAGS = -lcppunit -Wall -Wextra

EXEC= tests
SRC_TEST= $(wildcard *.cpp)
OBJ_TEST= $(SRC_TEST:.cpp=.o)
SRC= $(SRC_DIR)/settingWindow/fileSetting/GUIConfigFileSettingBuilder.cpp
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

tests : $(OBJ_TEST) $(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@mv *.o $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)

GUIConfigFileSettingBuilder.o : GUIConfigFileSettingBuilder.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)$(OBJ_TEST) tests
