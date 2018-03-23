#ifndef TEST_MULTICORREL
#define TEST_MULTICORREL

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../SquareMatrix.hpp"
#include "../ProcessMultiCorrel.hpp"
#include "../process/MixMaxCorrelated.cpp"
#include "../process/MixMinCorrelated.cpp"
#include "../process/MixRandomValues.cpp"
#include "../process/PreprocEnergy.cpp"
#include "../process/ColorGreenToRed.cpp"
#include "../process/CoeffScalar.cpp"

class TestMultiCorrel : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMultiCorrel);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testProcess);
  CPPUNIT_TEST(testCalculCorrel);
  CPPUNIT_TEST(testProcessVolume);
  CPPUNIT_TEST(testColorMatrix);
  CPPUNIT_TEST_SUITE_END();

private:
  ProcessMultiCorrel *p;
  SquareMatrix<float>* buffer;
  vector<float> meanCorrelations;
  void testConstructor();
  void testProcess();
  void testCalculCorrel();
  void testProcessVolume();
  void testColorMatrix();
};

#endif // TEST_MULTICORREL
