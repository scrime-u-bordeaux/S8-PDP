/**
 *  @file    TestColorBlackToWhite.cpp
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

#include "TestColorBlackToWhite.hpp"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestColorBlackToWhite);

void TestColorBlackToWhite::setUp(){
  input1 = 0.0f;
  input2 = 0.5f;
  input3 = 1.0f;
}

void TestColorBlackToWhite::tearDown(){

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
