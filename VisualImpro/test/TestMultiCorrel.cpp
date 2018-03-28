#include "TestMultiCorrel.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMultiCorrel);

void TestMultiCorrel::setUp(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
    buffer = new SquareMatrix<float>(3);
    buffer->setCase(0,0,0.0f);
    buffer->setCase(0,1,1.0f);
    buffer->setCase(0,2,2.0f);
    buffer->setCase(1,0,3.0f);
    buffer->setCase(1,1,4.0f);
    buffer->setCase(1,2,5.0f);
    buffer->setCase(2,0,6.0f);
    buffer->setCase(2,1,7.0f);
    buffer->setCase(2,2,8.0f);
    meanCorrelations = std::vector<float>(3, 0.0f);
    conn = new Connection();
}

void TestMultiCorrel::tearDown(){
  delete p;
}

void TestMultiCorrel::testConstructor(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixRandomValues);
  p->setMix(MixMinCorrelated);
  CPPUNIT_ASSERT(p->getMix() == MixMinCorrelated);
}

void TestMultiCorrel::testProcess() {
  //p->process(*buffer, meanCorrelations, *conn);
}

void TestMultiCorrel::testCalculCorrel(){

}

void TestMultiCorrel::testProcessVolume(){

}

void TestMultiCorrel::testColorMatrix(){

}
