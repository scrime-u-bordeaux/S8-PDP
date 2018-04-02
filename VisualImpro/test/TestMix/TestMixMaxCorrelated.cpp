/**
 *  @file    PreprocStrengthEnergy.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our mix based on maximal correlations is
 *  functionning well. Indeed, here we setup a 3x3 matrix with a custom values
 *  on every case and we assure that the result is the same as expected for each
 *  case of our result vector in the testMix function.
 *
 */

#include "TestMixMaxCorrelated.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMixMaxCorrelated);

void TestMixMaxCorrelated::setUp(){
  input = new Matrix<float>(3);
  input->setCase(0,0,0.0f);
  input->setCase(0,1,0.9f);
  input->setCase(0,2,0.7f);
  input->setCase(1,0,0.5f);
  input->setCase(1,1,0.0f);
  input->setCase(1,2,0.7f);
  input->setCase(2,0,0.8f);
  input->setCase(2,1,0.9f);
  input->setCase(2,2,0.0f);
}

void TestMixMaxCorrelated::tearDown(){
  delete input;
}

void  TestMixMaxCorrelated::testMix(){
  vector<float> output(input->getSize(), 0.0f);
  output = MixMaxCorrelated(*input);
  float epsilon = 0.00001f;
  CPPUNIT_ASSERT(std::abs(output[0]-0.8f) <= epsilon);
  CPPUNIT_ASSERT_EQUAL(output[1], 0.6f);
  CPPUNIT_ASSERT_EQUAL(output[2], 0.85f);
}
