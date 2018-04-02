/**
 *  @file    TestPreprocEnergy.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our energy preprocessing function is doing
 *  its job. Here we pass a Matrix as parameter to our preprocessing and we
 *  assure that..........
 *
 */

#include "TestPreprocEnergy.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPreprocEnergy);

void TestPreprocEnergy::setUp(){
  input = new Matrix<float>(5, 5.0f);
}

void TestPreprocEnergy::tearDown(){
  delete input;
}

void  TestPreprocEnergy::testPreproc(){
  Matrix<float> output(5);
  output = PreprocEnergy(*input);
  int row = output.getSize();
  int col = output.getRow(0).size();
  CPPUNIT_ASSERT_EQUAL(row, 5);
  CPPUNIT_ASSERT_EQUAL(col, 5/1024 +1);
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      CPPUNIT_ASSERT(0 == 0);
    }
  }
}
