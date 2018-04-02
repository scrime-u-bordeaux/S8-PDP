#ifndef TEST_COEFFRANDOM
#define TEST_COEFFRANDOM

#include <cstdlib>
#include <vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../process/Coeff/CoeffRandom.hpp"

class TestCoeffRandom : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestCoeffRandom);
  CPPUNIT_TEST(testCoeff);
  CPPUNIT_TEST_SUITE_END();

private:
  vector<float> s1;
  vector<float> s2;
  void testCoeff();
};

#endif // TEST_COEFFRANDOM
