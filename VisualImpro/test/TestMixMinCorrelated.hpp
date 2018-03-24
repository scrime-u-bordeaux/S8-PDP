#ifndef TEST_MIXMINCORRELATED
#define TEST_MIXMINCORRELATED

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../SquareMatrix.hpp"
#include "../RGB.hpp"
#include "../process/MixMinCorrelated.hpp"

class TestMixMinCorrelated : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMixMinCorrelated);
  CPPUNIT_TEST(testMix);
  CPPUNIT_TEST_SUITE_END();

private:
  void testMix();
};

#endif // TEST_MIXMINCORRELATED
