/**
 *  @file    PreprocStrengthEnergy.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our neutral mix is functionning well.
 *  Here we pass a Matrix as parameter to our neutral mix function and we assure
 *  that every element in our result vector has a value of 1.0 as expected.
 *
 */

#include "TestMixNeutral.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMixNeutral);

void TestMixNeutral::setUp(){
  input = new Matrix<float>(5);
}

void TestMixNeutral::tearDown(){
  delete input;
}

void  TestMixNeutral::testMix(){
  vector<float> output;
  output = MixNeutral(*input);
  int size = output.size();
  for(int i=0; i<size; i++){
    CPPUNIT_ASSERT_EQUAL(output[i], 1.0f);
  }
}
