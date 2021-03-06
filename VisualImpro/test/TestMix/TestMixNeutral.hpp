#ifndef TEST_MIXNEUTRAL
#define TEST_MIXNEUTRAL

#include<vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../Matrix.hpp"
#include "../../process/Mix/MixNeutral.hpp"
#include "../../RGB.hpp"

class TestMixNeutral : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMixNeutral);
  CPPUNIT_TEST(testMix);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<float>* input;
  void testMix();
};

#endif // TEST_MIXNEUTRAL
