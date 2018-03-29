#include "TestMultiCorrel.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestMultiCorrel);

void TestMultiCorrel::setUp(){
    ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
    buffer = new Matrix<float>(3, 0.0f);
    buffer->setCase(0,0,0.0f);
    buffer->setCase(0,1,0.1f);
    buffer->setCase(0,2,0.1f);
    buffer->setCase(1,0,0.1f);
    buffer->setCase(1,1,0.0f);
    buffer->setCase(1,2,0.1f);
    buffer->setCase(2,0,0.1f);
    buffer->setCase(2,1,0.1f);
    buffer->setCase(2,2,0.0f);
    meanCorrelations = std::vector<float>(3, 0.0f);
    conn = new Connection();
    p->setMix(MixMinCorrelated);
}

void TestMultiCorrel::tearDown(){
  delete p;
}

void TestMultiCorrel::testConstructor(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
    CPPUNIT_ASSERT(p->getPreproc() == PreprocEnergy);
    CPPUNIT_ASSERT(p->getCoeff() == CoeffScalar);
    CPPUNIT_ASSERT(p->getMix() == MixMaxCorrelated);
    CPPUNIT_ASSERT(p->getColor() == ColorGreenToRed);
}

void TestMultiCorrel::TestProcess(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
    p->process(*buffer, meanCorrelations, *conn);
}

void TestMultiCorrel::testSetPreproc(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  p->setPreproc(PreprocStrengthEnergy);
  CPPUNIT_ASSERT(p->getPreproc() != PreprocEnergy);
  CPPUNIT_ASSERT(p->getPreproc() == PreprocStrengthEnergy);
}

void TestMultiCorrel::testGetPreproc(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  CPPUNIT_ASSERT(p->getPreproc() == PreprocEnergy);
  CPPUNIT_ASSERT(p->getPreproc() != PreprocStrengthEnergy);
}

void TestMultiCorrel::testSetCoeff(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  p->setCoeff(CoeffRandom);
  CPPUNIT_ASSERT(p->getCoeff() != CoeffScalar);
  CPPUNIT_ASSERT(p->getCoeff() == CoeffRandom);
}

void TestMultiCorrel::testGetCoeff(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  CPPUNIT_ASSERT(p->getCoeff() == CoeffScalar);
  CPPUNIT_ASSERT(p->getCoeff() != CoeffRandom);
}

void TestMultiCorrel::testSetMix(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  p->setMix(MixMinCorrelated);
  CPPUNIT_ASSERT(p->getMix() != MixMaxCorrelated);
  CPPUNIT_ASSERT(p->getMix() == MixMinCorrelated);
}

void TestMultiCorrel::testGetMix(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  CPPUNIT_ASSERT(p->getMix() == MixMaxCorrelated);
  CPPUNIT_ASSERT(p->getMix() != MixMinCorrelated);
}

void TestMultiCorrel::testGetColor(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  p->setColor(ColorBlackToWhite);
  CPPUNIT_ASSERT(p->getColor() != ColorGreenToRed);
  CPPUNIT_ASSERT(p->getColor() == ColorBlackToWhite);
}

void TestMultiCorrel::testSetColor(){
  ProcessMultiCorrel *p = new ProcessMultiCorrel(CoeffScalar,
    ColorGreenToRed, PreprocEnergy, MixMaxCorrelated);
  CPPUNIT_ASSERT(p->getColor() == ColorGreenToRed);
  CPPUNIT_ASSERT(p->getColor() != ColorBlackToWhite);
}
