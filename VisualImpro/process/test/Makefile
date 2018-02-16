CPPFLAGS = -Wall -O3
LIBS = -lboost_unit_test_framework

all : compile

compile :
	g++ $(CPPFLAGS) -c ../CoeffScalar.cpp
	g++ $(CPPFLAGS) -o testCoeffScalar CoeffScalarTest.cpp CoeffScalar.o $(LIBS)

clean :
	rm testCoeffScalar CoeffScalar.o
