#ifndef TEST_RGB
#define TEST_RGB

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../Matrix.hpp"
#include "../../RGB.hpp"

class TestRGB : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestRGB);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testSetColor);
  CPPUNIT_TEST(testGetColor);
  CPPUNIT_TEST(testToString);
  CPPUNIT_TEST_SUITE_END();

private:
  RGB* black;
  RGB* white;
  void testConstructor();
  void testSetColor();
  void testGetColor();
  void testToString();
};

#endif // TEST_RGB
