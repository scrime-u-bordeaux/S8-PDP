/**
 *  @file    TestMain.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  The main function standing for all of out tests. It will get the registry
 *  of all of our cppunit testes contained in the Test* folders and print the
 *  results of our tests in the standard output.
 *
 */

#include <iostream>

#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>


int main() {
  CppUnit::TextUi::TestRunner runner;

  CppUnit::TestFactoryRegistry &registry =
      CppUnit::TestFactoryRegistry::getRegistry();

  runner.addTest(registry.makeTest());
  runner.setOutputter(
      new CppUnit::CompilerOutputter(&runner.result(), std::cerr));

  return runner.run() ? 0 : 1;
}
