#include "TestMixMaxCorrelated.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMixMaxCorrelated);

void TestMixMaxCorrelated::setUp(){
  input = new Matrix<float>(3);
  input->setCase(0,0,0.0f);
  input->setCase(0,1,0.9f);
  input->setCase(0,2,0.7f);
  input->setCase(1,0,0.5f);
  input->setCase(1,1,0.0f);
  input->setCase(1,2,0.7f);
  input->setCase(2,0,0.8f);
  input->setCase(2,1,0.9f);
  input->setCase(2,2,0.0f);
}

void TestMixMaxCorrelated::tearDown(){
  delete input;
}

void  TestMixMaxCorrelated::testMix(){
  vector<float> output(input->getSize(), 0.0f);
  output = MixMaxCorrelated(*input);
  float epsilon = 0.00001f;
  CPPUNIT_ASSERT(std::abs(output[0]-0.8f) <= epsilon);
  CPPUNIT_ASSERT_EQUAL(output[1], 0.6f);
  CPPUNIT_ASSERT_EQUAL(output[2], 0.85f);
}
