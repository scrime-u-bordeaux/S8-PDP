/**
 * @file TestSquareMatrix.hpp
 * @author Lucas VIVAS
*/

#ifndef TEST_SQUAREMATRIX
#define TEST_SQUAREMATRIX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "SquareMatrix.hpp"

class TestSquareMatrix : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestSquareMatrix);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testGetCase);
  CPPUNIT_TEST(testSetCase);
  CPPUNIT_TEST(testToString);
  CPPUNIT_TEST(testDestructor);
  CPPUNIT_TEST_SUITE_END();

private:
//  SquareMatrix matrix;

  void testConstructor();
  void testGetCase();
  void testSetCase();
  void testToString();
  void testDestructor();
};

#endif // TEST_SQUAREMATRIX
