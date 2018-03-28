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
  CPPUNIT_ASSERT(result >= 0.2f);
  CPPUNIT_ASSERT(result <= 1.0f);
}
