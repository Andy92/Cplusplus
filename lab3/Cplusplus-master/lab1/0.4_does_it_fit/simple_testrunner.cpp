/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "simple.cxxtest.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "simple.cxxtest.cpp", 6, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test1" ) {}
 void runTest() { suite_MyTestSuite.test1(); }
} testDescription_MyTestSuite_test1;

static class TestDescription_MyTestSuite_test2 : public CxxTest::RealTestDescription {
public:
TestDescription_MyTestSuite_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test2" ) {}
 void runTest() { suite_MyTestSuite.test2(); }
} testDescription_MyTestSuite_test2;

static class TestDescription_MyTestSuite_test3 : public CxxTest::RealTestDescription {
public:
TestDescription_MyTestSuite_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test3" ) {}
 void runTest() { suite_MyTestSuite.test3(); }
} testDescription_MyTestSuite_test3;



#include <cxxtest/Root.cpp>
