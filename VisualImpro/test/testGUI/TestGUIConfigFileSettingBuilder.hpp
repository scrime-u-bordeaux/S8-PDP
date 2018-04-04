/**
 * \file TestMatrix.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef TEST_
#define TEST_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../src/settingWindow/fileSetting/GUIConfigFileSettingBuilder.hpp"

class TestGUIConfigFileSettingBuilder : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestGUIConfigFileSettingBuilder);
  CPPUNIT_TEST(testBeginFile);
  CPPUNIT_TEST(testAddSetting);
  CPPUNIT_TEST(testEndFile);
  CPPUNIT_TEST_SUITE_END();

private:
  GUIConfigFileSettingBuilder* builder;
  void testBeginFile();
  void testAddSetting();
  void testEndFile();
};

#endif // TEST_
