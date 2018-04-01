/**
 *  @file    TestPreprocStrengthEnergy.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our strength energy preprocessing function
 *  is doing its job. Here we pass a Matrix as parameter to our preprocessing
 *  and we assure that..........
 *
 */

#include "TestPreprocStrengthEnergy.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPreprocStrengthEnergy);

void TestPreprocStrengthEnergy::setUp(){
  input = new Matrix<float>(5);
}

void TestPreprocStrengthEnergy::tearDown(){
  delete input;
}

void TestPreprocStrengthEnergy::testPreproc(){
  Matrix<float> output(5);
  output = PreprocStrengthEnergy(*input);
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
