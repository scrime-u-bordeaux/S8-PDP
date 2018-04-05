/**
 * \file TestMatrix.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef TEST_BUILDER
#define TEST_BUILDER

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../../GUI/src/settingWindow/fileSetting/GUIConfigFileSettingBuilder.hpp"

class TestGUIConfigFileSettingBuilder : public CppUnit::TestFixture {

public:
  void setUp();
  void tearDown();
  CPPUNIT_TEST_SUITE(TestGUIConfigFileSettingBuilder);
  CPPUNIT_TEST(testBuilder);
  CPPUNIT_TEST_SUITE_END();

private:
  GUIConfigFileSettingBuilder* builder;
  void testBuilder();
};

#endif // TEST_BUILDER
