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
