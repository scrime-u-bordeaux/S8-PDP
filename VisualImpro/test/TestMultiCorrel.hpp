#ifndef TEST_MULTICORREL
#define TEST_MULTICORREL

#include<vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestMultiCorrel : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMultiCorrel);
  CPPUNIT_TEST(testProcess);
  CPPUNIT_TEST_SUITE_END();

private:
  std::vector<std::vector<float> > matrix;
  void testProcess();
};

#endif // TEST_MULTICORREL
