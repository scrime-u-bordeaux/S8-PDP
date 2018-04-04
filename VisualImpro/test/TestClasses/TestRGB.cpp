/**
 *  \file    TestRGB.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief Test program of the RGB
 *
 *  This test is used to show us that our RGB object is functionning well. We
 *  test operations on the constructor, getting and setting colors, and printing
 *  a RGB triplet.
 *
 */

#include "TestRGB.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestRGB);

void TestRGB::setUp(){
  black = new RGB(0,0,0);
  white = new RGB(255,255,255);
}

void TestRGB::tearDown(){
  delete black;
  delete white;
}

void  TestRGB::testConstructor(){
  black = new RGB(1,1,1);
  CPPUNIT_ASSERT(black->getRed() != 0);
}

void TestRGB::testSetColor(){
  CPPUNIT_ASSERT_EQUAL(0,  black->getGreen());
  black->setGreen(10);
  CPPUNIT_ASSERT_EQUAL(10, black->getGreen());
}

void TestRGB::testGetColor(){
  CPPUNIT_ASSERT(white->getRed() == 255);
  CPPUNIT_ASSERT(white->getGreen() == 255);
  CPPUNIT_ASSERT(white->getBlue() == 255);
  white->setBlue(250);
  CPPUNIT_ASSERT(white->getBlue() == 250);
}

void TestRGB::testToString(){
  CPPUNIT_ASSERT(black->toString() == "#000000");
  CPPUNIT_ASSERT(white->toString() == "#FFFFFF");
}
