/**
 * @file TestGUIConfigFileSettingBuilder.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include "TestGUIConfigFileSettingBuilder.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestGUIConfigFileSettingBuilder);

void TestGUIConfigFileSettingBuilder::setUp(){
    builder = new GUIConfigFileSettingBuilder();
}

void TestGUIConfigFileSettingBuilder::tearDown(){
  // delete intMatrix;
}

void  TestGUIConfigFileSettingBuilder::testBeginFile()
{

}

void TestGUIConfigFileSettingBuilder::testAddSetting(){
  // CPPUNIT_ASSERT_EQUAL(0,  intMatrix->getCase(0,0));
  // intMatrix->setCase(0,0,3);
  // CPPUNIT_ASSERT_EQUAL(3,  intMatrix->getCase(0,0));
}

void TestGUIConfigFileSettingBuilder::testEndFile(){
  // CPPUNIT_ASSERT(intMatrix->toString() == "Matrix");
}
