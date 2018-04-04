/**
 *  \file    TestCoeffScalar.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief Test program of the CoeffScalar function.
 *
 *  This test is used to show us that our scalar correlation function is
 *  functionning well. The scalar correlation function works as the
 *  operation given in an assertion in the testCoeff test function.
 *
 */

#include "TestCoeffScalar.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestCoeffScalar);

void TestCoeffScalar::setUp(){
  s1 = vector<float>(100, 0.5f);
  s2 = vector<float>(100, 1.0f);
}

void TestCoeffScalar::tearDown(){
  vector<float> v;
  v.swap(s1);
  v.swap(s2);
}

void TestCoeffScalar::testCoeff(){
  float result = 0.0f;
  result = CoeffScalar(s1,s2);
  float norm1 = 0.0;
  for (unsigned int i = 0; i < s1.size(); i++){
    norm1 += s1[i]*s1[i];
  }
  float norm2 = 0.0;
  for (unsigned int i = 0; i < s2.size(); i++){
    norm2 += s2[i]*s2[i];
  }
  float scal = 0.0;
  for (unsigned int i = 0; i < s1.size(); i++){
    scal += s1[i]*s2[i];
  }
  CPPUNIT_ASSERT(result == fabs(scal)/sqrt(norm1*norm2));
}
