#ifndef TEST_COLORGREENTORED
#define TEST_COLORGREENTORED

#include<vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../process/Color/ColorGreenToRed.hpp"
#include "../../RGB.hpp"

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
