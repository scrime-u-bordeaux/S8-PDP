#ifndef TEST_MIXMAXCORRELATED
#define TEST_MIXMAXCORRELATED

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../SquareMatrix.hpp"
#include "../RGB.hpp"
#include "../process/MixMaxCorrelated.hpp"

class TestMixMaxCorrelated : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMixMaxCorrelated);
  CPPUNIT_TEST(testMix);
  CPPUNIT_TEST_SUITE_END();

private:
  void testMix();
};

#endif // TEST_MIXMAXCORRELATED