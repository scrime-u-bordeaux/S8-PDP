#ifndef TEST_MULTICORREL
#define TEST_MULTICORREL

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../SquareMatrix.hpp"
#include "../RGB.hpp"
#include "../ProcessMultiCorrel.hpp"
#include "../process/MixMaxCorrelated.hpp"
#include "../process/MixMinCorrelated.hpp"
#include "../process/MixRandomValues.hpp"
#include "../process/PreprocEnergy.hpp"
#include "../process/ColorGreenToRed.hpp"
#include "../process/CoeffScalar.hpp"

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
  Connection* conn;
  void testConstructor();
  void testProcess();
  void testCalculCorrel();
  void testProcessVolume();
  void testColorMatrix();
};

#endif // TEST_MULTICORREL
