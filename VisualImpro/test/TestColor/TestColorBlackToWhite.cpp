/**
 *  @file    TestColorBlackToWhite.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our color function taking a float as
 *  parameter and returning an RGB triplet representing a color between black
 *  and white is working well. To demonstrate that, we take three float with the
 *  minimal expected value, the maximal expected value and the medium expected
 *  value and then pass them as parameter to our color function. The test is
 *  satisfied if the string corresponding of the color results are the same as
 *  expected on the three assertions int the testColor function.
 *
 */

#include "TestColorBlackToWhite.hpp"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestColorBlackToWhite);

void TestColorBlackToWhite::setUp(){
  input1 = 0.0f;
  input2 = 0.5f;
  input3 = 1.0f;
}

void TestColorBlackToWhite::tearDown(){
  // Nothing to delete here
}

void TestColorBlackToWhite::testColor(){
  RGB color1(0,0,0);
  RGB color2(0,0,0);
  RGB color3(0,0,0);
  color1 = ColorBlackToWhite(input1);
  color2 = ColorBlackToWhite(input2);
  color3 = ColorBlackToWhite(input3);
  CPPUNIT_ASSERT(color1.toString() == "#0");
  CPPUNIT_ASSERT(color2.toString() == "#8355711");
  CPPUNIT_ASSERT(color3.toString() == "#16777215");
}
