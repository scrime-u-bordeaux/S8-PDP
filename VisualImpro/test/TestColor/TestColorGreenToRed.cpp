/**
 *  @file    TestColorGreenToRed.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This test is used to show us that our default preprocessing function is
 *  doing its job. Here we pass a Matrix as parameter to our neutral mix function
 *  and we assure that every element in our result Matrix has the same value as
 *  out initial Matrix, which is 5.0 in this case
 *
 */

#include "TestColorGreenToRed.hpp"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestColorGreenToRed);

void TestColorGreenToRed::setUp(){
  input1 = 0.0f;
  input2 = 0.5f;
  input3 = 1.0f;
}

void TestColorGreenToRed::tearDown(){

}

void TestColorGreenToRed::testColor(){
  RGB color1(0,0,0);
  RGB color2(0,0,0);
  RGB color3(0,0,0);
  color1 = ColorGreenToRed(input1);
  color2 = ColorGreenToRed(input2);
  color3 = ColorGreenToRed(input3);
  CPPUNIT_ASSERT(color1.toString() == "#0");
  CPPUNIT_ASSERT(color2.toString() == "#16775700");
  CPPUNIT_ASSERT(color3.toString() == "#1374740");
}
