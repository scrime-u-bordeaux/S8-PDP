/**
 *  \file    PreprocStrengthEnergy.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief Test program of the CoeffRandom function.
 *
 *  This test is used to show us that our random correlation function is
 *  functionning well. As we can't realy test precisely the result values, what
 *  we're doing here is that we verify if the returned value is in our range of
 *  expected output values.
 *
 */

#include "TestCoeffRandom.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestCoeffRandom);

void TestCoeffRandom::setUp(){
  s1 = vector<float>(300);
  s2 = vector<float>(300);
  for(unsigned int i=0; i<s1.size(); i++){
    float randomval = rand()/(RAND_MAX);
    s1[i] = randomval;
    s2[i] = randomval;
  }
}

void TestCoeffRandom::tearDown(){
  vector<float> v;
  v.swap(s1);
  v.swap(s2);
}

void  TestCoeffRandom::testCoeff(){
  float result;
  result = CoeffRandom(s1,s2);
  CPPUNIT_ASSERT(result >= 0.0f);
  CPPUNIT_ASSERT(result <= 1.0f);
}
