#ifndef TEST_COLORGREENTORED
#define TEST_COLORGREENTORED

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../RGB.hpp"
#include "../../process/Color/ColorGreenToRed.hpp"

class TestColorGreenToRed : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestColorGreenToRed);
  CPPUNIT_TEST(testColor);
  CPPUNIT_TEST_SUITE_END();

private:
  float input1;
  float input2;
  float input3;
  void testColor();
};

#endif // TEST_COLORGREENTORED
