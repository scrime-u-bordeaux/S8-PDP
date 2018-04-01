#ifndef TEST_PREPROCDEFAULT
#define TEST_PREPROCDEFAULT

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../Matrix.hpp"
#include "../../process/Preproc/PreprocDefault.hpp"

class TestPreprocDefault : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestPreprocDefault);
  CPPUNIT_TEST(testPreproc);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<float>* input;
  void testPreproc();
};

#endif // TEST_PREPROCDEFAULT
