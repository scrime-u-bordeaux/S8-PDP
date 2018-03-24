#ifndef TEST_MIXRANDOMVALUES
#define TEST_MIXRANDOMVALUES

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../SquareMatrix.hpp"
#include "../RGB.hpp"
#include "../process/MixRandomValues.hpp"

class TestMixRandomValues : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMixRandomValues);
  CPPUNIT_TEST(testMix);
  CPPUNIT_TEST_SUITE_END();

private:
  void testMix();
};

#endif // TEST_MIXRANDOMVALUES
