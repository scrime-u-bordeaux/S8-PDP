#ifndef TEST_MATRIX
#define TEST_MATRIX

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "../../Matrix.hpp"
#include "../../RGB.hpp"

class TestMatrix : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestMatrix);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testSetCase);
  CPPUNIT_TEST(testGetCase);
  CPPUNIT_TEST(testToString);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<int>* intMatrix;
  Matrix<float>* floatMatrix;
  Matrix<RGB>* RGBmatrix;
  void testConstructor();
  void testSetCase();
  void testGetCase();
  void testToString();
};

#endif // TEST_MATRIX
