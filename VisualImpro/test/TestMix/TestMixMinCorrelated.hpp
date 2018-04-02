#ifndef TEST_MIXMINCORRELATED
#define TEST_MIXMINCORRELATED

#include<vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../Matrix.hpp"
#include "../../process/Mix/MixMinCorrelated.hpp"
#include "../../RGB.hpp"

class TestMixMinCorrelated : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMixMinCorrelated);
  CPPUNIT_TEST(testMix);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<float>* input;
  void testMix();
};

#endif // TEST_MIXMINCORRELATED
