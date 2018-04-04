/**
 *  \file    PreprocStrengthEnergy.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief Test program of the MixMinCorrelated function.
 *
 *  This test is used to show us that our mix based on minimal correlations is
 *  functionning well. Indeed, here we setup a 3x3 matrix with a custom values
 *  on every case and we assure that the result is the same as expected for each
 *  case of our result vector in the testMix function.
 *
 */

#include "TestMixMinCorrelated.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMixMinCorrelated);

void TestMixMinCorrelated::setUp(){
  input = new Matrix<float>(3);
  input->setCase(0,0,0.0f);
  input->setCase(0,1,0.3f);
  input->setCase(0,2,0.4f);
  input->setCase(1,0,0.5f);
  input->setCase(1,1,0.0f);
  input->setCase(1,2,0.7f);
  input->setCase(2,0,0.8f);
  input->setCase(2,1,0.9f);
  input->setCase(2,2,0.0f);
}

void TestMixMinCorrelated::tearDown(){
  delete input;
}

void  TestMixMinCorrelated::testMix(){
  vector<float> output;
  output = MixMinCorrelated(*input);
  CPPUNIT_ASSERT_EQUAL(output[0], 0.65f);
  CPPUNIT_ASSERT_EQUAL(output[1], 0.4f);
  CPPUNIT_ASSERT_EQUAL(output[2], 0.15f);
}
