/**
 *  @file    PreprocStrengthEnergy.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our Matrix object if functionning as we
 *  intended. Our tests here stand for operations on cases, rows and columns.
 *  We either get or set values, and swap rows, columns, or the entire matrix.
 *
 */

#include "TestMatrix.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMatrix);

void TestMatrix::setUp(){
  intMatrix = new Matrix<int>(5);
  floatMatrix = new Matrix<float>(5);
  RGBmatrix = new Matrix<RGB>(5);
}

void TestMatrix::tearDown(){
  delete intMatrix;
}

void  TestMatrix::testConstructor()
{
  intMatrix = new Matrix<int>(3);

  CPPUNIT_ASSERT_EQUAL(0,  intMatrix->getCase(0,0));
  CPPUNIT_ASSERT_EQUAL(0,  intMatrix->getCase(2,2));
  CPPUNIT_ASSERT(1 != intMatrix->getCase(1,1));
}

void TestMatrix::testSetCase(){
  CPPUNIT_ASSERT_EQUAL(0,  intMatrix->getCase(0,0));
  intMatrix->setCase(0,0,3);
  CPPUNIT_ASSERT_EQUAL(3,  intMatrix->getCase(0,0));
}

void TestMatrix::testGetCase(){
  CPPUNIT_ASSERT(intMatrix->getCase(0,0) == 0);
  CPPUNIT_ASSERT(intMatrix->getCase(0,1) == 0);
  CPPUNIT_ASSERT(intMatrix->getCase(1,0) == 0);
  floatMatrix->setCase(0,2,5.2f);
  CPPUNIT_ASSERT(floatMatrix->getCase(0,2) == 5.2f);
}

void TestMatrix::testToString(){
  CPPUNIT_ASSERT(intMatrix->toString() == "Matrix");
}
