/**
 *  \file    TestPreprocStrengthEnergy.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief Test program of the PreprocStrengthEnergy function.
 *
 *  This test is used to show us that our strength energy preprocessing function
 *  is doing its job. Here we pass a Matrix as parameter to our preprocessing
 *  and we assure that every value of the returned vector is equals to what we
 *  attended as depending of the values we put in the setUp function.
 *
 */

#include "TestPreprocStrengthEnergy.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPreprocStrengthEnergy);

void TestPreprocStrengthEnergy::setUp(){
  input = new Matrix<float>(5, 5.0f);
  input->setRow(0, vector<float>(1024, 1.0f));
  input->setRow(1, vector<float>(1024, 2.0f));
  input->setRow(2, vector<float>(1024, 3.0f));
  input->setRow(3, vector<float>(1024, 4.0f));
  input->setRow(4, vector<float>(1024, 5.0f));
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
  CPPUNIT_ASSERT_EQUAL(col, 1);
  for(int i=0; i<row; i++){
    CPPUNIT_ASSERT_EQUAL(output.getCase(i,0), (float)pow(i+1,2));
  }
}
