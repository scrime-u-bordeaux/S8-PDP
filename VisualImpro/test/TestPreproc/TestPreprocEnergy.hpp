#ifndef TEST_PREPROCENERGY
#define TEST_PREPROCENERGY

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../Matrix.hpp"
#include "../../process/Preproc/PreprocEnergy.hpp"

class TestPreprocEnergy : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestPreprocEnergy);
  CPPUNIT_TEST(testPreproc);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<float>* input;
  void testPreproc();
};

#endif // TEST_PREPROCENERGY
