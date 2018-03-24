#ifndef TEST_MIXNEUTRAL
#define TEST_MIXNEUTRAL

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../SquareMatrix.hpp"
#include "../RGB.hpp"
#include "../process/TestMixNeutral.cpp"

class TestMixNeutral : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMixRandomValues);
  CPPUNIT_TEST(testMix);
  CPPUNIT_TEST_SUITE_END();

private:
  void testMix();
};

#endif // TEST_MIXNEUTRAL
