CPPFLAGS = -O3
LIBS = 

all : compile

compile : 
	g++ -shared $(CPPFLAGS) $(LIBS) -fPIC Preproc*.cpp Coeff*.cpp Color*.cpp -o libprocess.so

clean :
	rm -rf *.o
