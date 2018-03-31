#ifndef TEST_MULTICORREL
#define TEST_MULTICORREL

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../Matrix.hpp"
#include "../RGB.hpp"
#include "../ProcessMultiCorrel.hpp"
#include "../process/MixMaxCorrelated.hpp"
#include "../process/MixMinCorrelated.hpp"
#include "../process/PreprocStrengthEnergy.hpp"
#include "../process/PreprocEnergy.hpp"
#include "../process/ColorGreenToRed.hpp"
#include "../process/ColorBlackToWhite.hpp"
#include "../process/CoeffScalar.hpp"
#include "../process/CoeffRandom.hpp"

class TestMultiCorrel : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMultiCorrel);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(TestProcess);
  CPPUNIT_TEST(testSetPreproc);
  CPPUNIT_TEST(testGetPreproc);
  CPPUNIT_TEST(testSetCoeff);
  CPPUNIT_TEST(testGetCoeff);
  CPPUNIT_TEST(testSetMix);
  CPPUNIT_TEST(testGetMix);
  CPPUNIT_TEST(testSetColor);
  CPPUNIT_TEST(testGetColor);
  CPPUNIT_TEST_SUITE_END();

private:
  ProcessMultiCorrel *p;
  Matrix<float>* buffer;
  vector<float> meanCorrelations;
  Connection* conn;
  void testConstructor();
  void TestProcess();
  void testSetPreproc();
  void testGetPreproc();
  void testSetCoeff();
  void testGetCoeff();
  void testSetMix();
  void testGetMix();
  void testSetColor();
  void testGetColor();
};

#endif // TEST_MULTICORREL
