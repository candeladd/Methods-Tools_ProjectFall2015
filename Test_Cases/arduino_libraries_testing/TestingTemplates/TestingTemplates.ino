#include <ArduinoUnit.h>


class MyTest : public Test {
public:
  MyTest(const __FlashStringHelper *name) : Test(name) {
    // TODO: construct named test.
    // This should be lightweight - it may be excluded
    //
    // You can set verbosity.
  }
  void setup() {
    // TODO: setup test
    // You can call pass(), fail(), or skip() to immediately resolve test
    // You can make assertions.
    // You can set verbosity.
  }
  void loop() {
    // TODO: run test on each loop
    // You can call pass(), fail(), or skip() to resolve test
    // You can make assertions.
    // You can set verbosity.
  }
};

class MyTestOnce : public TestOnce
{
public:
  MyTestOnce(const char *name) : TestOnce(name) {
  // same as MyTest
  }
  void setup() {
  // same as MyTest
  }
  void once() {
  // same as MyTest::loop(), but will only be called once from loop()
  // if included in the active tests and was not resolved in setup().
  }

}

// create instances of the custom test 
MyTest myTest1(F("myTest1"));
MyTest myTest2(F("myTest2"));

MyTestOnce myTestOnce1("myTestOnce1");
MyTestOnce myTestOnce2("myTestOnce2");
