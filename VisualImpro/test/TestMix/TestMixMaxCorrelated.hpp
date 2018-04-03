#ifndef TEST_MIXMAXCORRELATED
#define TEST_MIXMAXCORRELATED

#include <cmath>
#include <vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../Matrix.hpp"
#include "../../process/Mix/MixMaxCorrelated.hpp"
#include "../../RGB.hpp"

class TestMixMaxCorrelated : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMixMaxCorrelated);
  CPPUNIT_TEST(testMix);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<float>* input;
  void testMix();
};

#endif // TEST_MIXMAXCORRELATED
