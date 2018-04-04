/**
 *  \file    PreprocStrengthEnergy.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief Test program of the CoeffScalar function.
 *
 *  This test is used to show us that our scalar correlation function is
 *  functionning well.
 *
 */

#include "TestCoeffScalar.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestCoeffScalar);

void TestCoeffScalar::setUp(){
  s1 = vector<float>(300);
  s2 = vector<float>(300);
  for(unsigned int i=0; i<s1.size(); i++){
    float randomval = rand()/(RAND_MAX);
    s1[i] = randomval;
    s2[i] = randomval;
  }
}

void TestCoeffScalar::tearDown(){
  vector<float> v;
  v.swap(s1);
  v.swap(s2);
}

void  TestCoeffScalar::testCoeff(){
  float result = 0.0f;
  result = CoeffScalar(s1,s2);
  CPPUNIT_ASSERT(result == 0.0f);
  CPPUNIT_ASSERT_EQUAL(result, 0.0f);
}

/*BOOST_AUTO_TEST_CASE(coeff_scalar_test) {
  std::vector<float> v(N, 1.0f);
  BOOST_CHECK(CoeffScalar(v, v) == 1.0f);
}*/
