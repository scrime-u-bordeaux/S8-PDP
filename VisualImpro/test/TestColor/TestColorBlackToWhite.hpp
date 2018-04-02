#ifndef TEST_COLORBLACKTOWHITE
#define TEST_COLORBLACKTOWHITE

#include<vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../process/Color/ColorBlackToWhite.hpp"
#include "../../RGB.hpp"

class TestColorBlackToWhite : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestColorBlackToWhite);
  CPPUNIT_TEST(testColor);
  CPPUNIT_TEST_SUITE_END();

private:
  float input1;
  float input2;
  float input3;
  void testColor();
};

#endif // TEST_COLORBLACKTOWHITE
