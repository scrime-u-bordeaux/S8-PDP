#include "TestMixRandomValues.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMixRandomValues);

void TestMixRandomValues::setUp(){
  input = new SquareMatrix<float>(300);
}

void TestMixRandomValues::tearDown(){
  delete input;
}

void  TestMixRandomValues::testMix(){
  vector<float> output;
  output = MixRandomValues(*input);
  int size = output.size();
  for(int i=0; i<size; i++){
    CPPUNIT_ASSERT(output[i] >= 0.2f);
    CPPUNIT_ASSERT(output[i] <= 1.0f);
  }
}
