/**
 * @file TestSquareMatrix.hpp
 * @author Lucas VIVAS
*/

#ifndef TEST_SQUAREMATRIX
#define TEST_SQUAREMATRIX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../RGB.hpp"
#include "../SquareMatrix.hpp"

class TestSquareMatrix : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestSquareMatrix);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testSetCase);
  CPPUNIT_TEST(testGetCase);
  CPPUNIT_TEST(testToString);
  CPPUNIT_TEST_SUITE_END();

private:
  SquareMatrix<int>* intMatrix;
  SquareMatrix<float>* floatMatrix;
  SquareMatrix<RGB>* RGBmatrix;
  void testConstructor();
  void testSetCase();
  void testGetCase();
  void testToString();
};

#endif // TEST_SQUAREMATRIX
