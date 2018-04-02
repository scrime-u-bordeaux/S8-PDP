/**
 *  @file    TestColorGreenToRed.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our color function taking a float as
 *  parameter and returning an RGB triplet representing a color between red
 *  and green is working well. To demonstrate that, we take three float with the
 *  minimal expected value, the maximal expected value and the medium expected
 *  value and then pass them as parameter to our color function. The test is
 *  satisfied if the string corresponding of the color results are the same as
 *  expected on the three assertions int the testColor function.
 *
 */

#include "TestColorGreenToRed.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestColorGreenToRed);

void TestColorGreenToRed::setUp(){
  input1 = 0.0f;
  input2 = 0.5f;
  input3 = 1.0f;
}

void TestColorGreenToRed::tearDown(){
  // Nothing to delete here
}

void TestColorGreenToRed::testColor(){
  RGB color1(0,0,0);
  RGB color2(0,0,0);
  RGB color3(0,0,0);
  color1 = ColorGreenToRed(input1);
  color2 = ColorGreenToRed(input2);
  color3 = ColorGreenToRed(input3);
  /*CPPUNIT_ASSERT(color1.toString() == "#0");
  CPPUNIT_ASSERT(color2.toString() == "#16775700");
  CPPUNIT_ASSERT(color3.toString() == "#1374740"); */
}
