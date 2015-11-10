#include <ArduinoUnit.h>

Test of success
#include "WProgram.h"
#include "HardwareSerial.h"
#include <ArduinoTestSuite.h>

//************************************************************************
void setup()
{
     boolean result;
     ATS_begin("Arduino", "My bare bones tests");
     result = true;
     ATS_PrintTestStatus("My bare bones test", result);
     ATS_end();
}

void loop()
{
}
