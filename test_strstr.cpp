#include <iostream>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>

#include "strstr.hpp"

using namespace std;

class NotIncludedTest1 : public CppUnit::TestCase
{
  public:
    NotIncludedTest1() : CppUnit::TestCase("NotIncludedTest1") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("", "abcd") == -1);
    }
};

class NotIncludedTest2 : public CppUnit::TestCase
{
  public:
    NotIncludedTest2() : CppUnit::TestCase("NotIncludedTest2") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("ab", "abcd") == -1);
    }
};

class NotIncludedTest3 : public CppUnit::TestCase
{
  public:
    NotIncludedTest3() : CppUnit::TestCase("NotIncludedTest3") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("abcde", "def") == -1);
    }
};

class EmptyStringTest : public CppUnit::TestCase
{
  public:
    EmptyStringTest() : CppUnit::TestCase("EmptyStringTest") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("abcd", "") == 0);
    }
};

class IncludedTest1 : public CppUnit::TestCase
{
  public:
    IncludedTest1() : CppUnit::TestCase("IncludedTest1") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("abcdef", "bcd") == 1);
    }
};

class IncludedTest2 : public CppUnit::TestCase
{
  public:
    IncludedTest2() : CppUnit::TestCase("IncludedTest2") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("abcdef", "def") == 3);
    }
};

class IncludedTest3 : public CppUnit::TestCase
{
  public:
    IncludedTest3() : CppUnit::TestCase("IncludedTest3") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("hello", "ll") == 2);
    }
};

class EqualTest : public CppUnit::TestCase
{
  public:
    EqualTest() : CppUnit::TestCase("EqualTest") {}

    void runTest()
    {
        CPPUNIT_ASSERT(strStr("a", "a") == 0);
    }
};

class StrStrRunner : public CppUnit::TestRunner
{
    public:
    static CppUnit::TestSuite *suite()
    {
        auto suite = new CppUnit::TestSuite("StrStrTests");
        suite->addTest(new NotIncludedTest1());
        suite->addTest(new NotIncludedTest2());
        suite->addTest(new NotIncludedTest3());
        suite->addTest(new EmptyStringTest());
        suite->addTest(new IncludedTest1());
        suite->addTest(new IncludedTest2());
        suite->addTest(new IncludedTest3());
        suite->addTest(new EqualTest());
        return suite;
    }
};

int main()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(StrStrRunner::suite());
    runner.run();
    return 0;
}