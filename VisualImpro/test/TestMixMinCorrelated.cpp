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
