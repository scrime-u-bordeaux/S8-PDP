/**
 * \file TestGUIConfigFileSettingBuilder.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include "TestGUIConfigFileSettingBuilder.hpp"

#include <string>

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

}

void  TestGUIConfigFileSettingBuilder::testBuilder()
{
   string strResult = builder->getResult();
   string strExpected = "# Configuration file for ./VisualImpro\n\
PORT 12345\n\
ADDRESS 192.168.7.1\n\
PROCESSLEN 32768\n\
EFFECTS N\n\
EFFECT_BUFFER_LEN 32\n\
ANALOG 5\n\
AUDIO 1\n\
FILE /dir/wav1.wav\n\
FILE /dir/wav2.wav\n\
COEFF functionCoeff\n\
PREPROC functionPreProc\n\
COLOR functionColor\n\
MIX functionMix\n";
   CPPUNIT_ASSERT_EQUAL(strResult, strExpected);
}
