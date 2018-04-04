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
  CPPUNIT_TEST(testGetSize);
  CPPUNIT_TEST(testGetRow);
  CPPUNIT_TEST(testSetRow);
  CPPUNIT_TEST(testSwap);
  CPPUNIT_TEST(testToString);
  CPPUNIT_TEST_SUITE_END();

private:
  Matrix<int>* intMatrix;
  Matrix<float>* floatMatrix;
  Matrix<float>* floatSwapMatrix;
  Matrix<RGB>* RGBmatrix;
  void testConstructor();
  void testSetCase();
  void testGetCase();
  void testGetSize();
  void testGetRow();
  void testSetRow();
  void testSwap();
  void testToString();
};

#endif // TEST_MATRIX
