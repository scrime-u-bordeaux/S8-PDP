/**
 * \file TestMain.cpp
 * @brief Main test program.
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
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
