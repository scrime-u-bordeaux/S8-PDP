#include "TestMixMinCorrelated.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMixMinCorrelated);

void TestMixMinCorrelated::setUp(){
  input = new SquareMatrix<float>(3);
  input->setCase(0,0,0.2f);
  input->setCase(0,1,0.3f);
  input->setCase(0,2,0.4f);
  input->setCase(1,0,0.5f);
  input->setCase(1,1,0.6f);
  input->setCase(1,2,0.7f);
  input->setCase(2,0,0.8f);
  input->setCase(2,1,0.9f);
  input->setCase(2,2,1.0f);
}

void TestMixMinCorrelated::tearDown(){
  delete input;
}

void  TestMixMinCorrelated::testMix(){
  vector<float> output;
  output = MixMinCorrelated(*input);
  CPPUNIT_ASSERT(output[0] > 0.433333f);
  CPPUNIT_ASSERT(output[0] < 0.433334f);
  CPPUNIT_ASSERT(output[1] > 0.266666f);
  CPPUNIT_ASSERT(output[1] < 0.266667f);
  CPPUNIT_ASSERT_EQUAL(output[2], 0.1f);
}
