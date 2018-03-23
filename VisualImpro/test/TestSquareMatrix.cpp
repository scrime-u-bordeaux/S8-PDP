/**
 * @file TestSquareMatrix.cpp
 * @author Lucas VIVAS
*/

#include "TestSquareMatrix.hpp"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestSquareMatrix);

void TestSquareMatrix::setUp(){
  intMatrix = new SquareMatrix<int>(5);
  floatMatrix = new SquareMatrix<float>(5.0f);
}

void TestSquareMatrix::tearDown(){
  delete intMatrix;
}

void  TestSquareMatrix::testConstructor()
{
  intMatrix = new SquareMatrix<int>(3);

  CPPUNIT_ASSERT_EQUAL(0,  intMatrix->getCase(0,0));
  CPPUNIT_ASSERT_EQUAL(0,  intMatrix->getCase(2,2));
  CPPUNIT_ASSERT(1 != intMatrix->getCase(1,1));
}

void TestSquareMatrix::testSetCase(){
  CPPUNIT_ASSERT_EQUAL(0,  intMatrix->getCase(0,0));
  intMatrix->setCase(0,0,3);
  CPPUNIT_ASSERT_EQUAL(3,  intMatrix->getCase(0,0));
}

void TestSquareMatrix::testGetCase(){
  CPPUNIT_ASSERT(intMatrix->getCase(0,0) == 0);
  CPPUNIT_ASSERT(intMatrix->getCase(0,1) == 0);
  CPPUNIT_ASSERT(intMatrix->getCase(1,0) == 0);
  floatMatrix->setCase(0,2,5.2f);
  CPPUNIT_ASSERT(floatMatrix->getCase(0,2) == 5.2f);
}

void TestSquareMatrix::testToString(){
  CPPUNIT_ASSERT(intMatrix->toString() == "SquareMatrix");
}
