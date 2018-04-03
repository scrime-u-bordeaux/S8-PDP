#ifndef TEST_COEFFSCALAR
#define TEST_COEFFSCALAR

#include <cstdlib>
#include <vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../process/Coeff/CoeffScalar.hpp"

class TestCoeffScalar : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestCoeffScalar);
  CPPUNIT_TEST(testCoeff);
  CPPUNIT_TEST_SUITE_END();

private:
  vector<float> s1;
  vector<float> s2;
  void testCoeff();
};

#endif // TEST_COEFFSCALAR
