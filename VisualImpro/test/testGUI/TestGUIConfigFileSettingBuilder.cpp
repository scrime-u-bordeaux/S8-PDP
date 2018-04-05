/**
 * \file TestGUIConfigFileSettingBuilder.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include "TestGUIConfigFileSettingBuilder.hpp"

#include <string>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestGUIConfigFileSettingBuilder);

void TestGUIConfigFileSettingBuilder::setUp(){
    builder = new GUIConfigFileSettingBuilder();
    builder->beginFile();
  builder->addPort(12345);
  builder->addAddress("192.168.7.1");
  builder->addProcessLen(32768);
  builder->addEffect(false, 32);
  builder->addAnalogInput(5);
  builder->addAudioInput(1);
  builder->addWavFile("/dir/wav1.wav");
  builder->addWavFile("/dir/wav2.wav");
  builder->addCoeffFunction("functionCoeff");
  builder->addPreProcFunction("functionPreProc");
  builder->addColorFunction("functionColor");
  builder->addMixFunction("functionMix");
  builder->endFile();
}

void TestGUIConfigFileSettingBuilder::tearDown(){
   delete builder;
}

void  TestGUIConfigFileSettingBuilder::testBuilder()
{
   string strResult = builder->getResult();
  // CPPUNIT_ASSERT(intMatrix->toString() == "Matrix");
}
