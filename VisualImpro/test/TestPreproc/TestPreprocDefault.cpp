/**
 *  @file    TestPreprocDefault.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our default preprocessing function is
 *  doing its job. Here we pass a Matrix as parameter to our neutral mix function
 *  and we assure that every element in our result Matrix has the same value as
 *  out initial Matrix, which is 5.0 in this case
 *
 */

#include "TestPreprocDefault.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPreprocDefault);

void TestPreprocDefault::setUp(){
  input = new Matrix<float>(5, 5.0f);
}

void TestPreprocDefault::tearDown(){
  delete input;
}

void TestPreprocDefault::testPreproc(){
  Matrix<float> output(5);
  output = PreprocDefault(*input);
  int row = output.getSize();
  int col = output.getRow(0).size();
  CPPUNIT_ASSERT_EQUAL(row, 5);
  CPPUNIT_ASSERT_EQUAL(col, 5);
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      CPPUNIT_ASSERT_EQUAL(output.getCase(i, j), 5.0f);
    }
  }
}
