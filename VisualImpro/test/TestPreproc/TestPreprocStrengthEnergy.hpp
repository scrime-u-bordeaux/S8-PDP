#ifndef TEST_PREPROCSTRENGTHENERGY
#define TEST_PREPROCSTRENGTHENERGY

#include <math.h>
#include <vector>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../Matrix.hpp"
#include "../../process/Preproc/PreprocStrengthEnergy.hpp"

class TestPreprocStrengthEnergy : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestPreprocStrengthEnergy);
  CPPUNIT_TEST(testPreproc);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<float>* input;
  void testPreproc();
};

#endif // TEST_PREPROCSTRENGTHENERGY
