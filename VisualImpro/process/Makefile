INC_DIR= ../include

CPPFLAGS = -O3
LIBS =

all : compile

compile :
	g++ -shared $(CPPFLAGS) $(LIBS) -Wl,--no-undefined -fPIC Preproc*.cpp Coeff*.cpp Color*.cpp Mix*.cpp ../SquareMatrix.cpp ../RGB.cpp -o libprocess.so

clean :
	rm -rf *.o libprocess.so
