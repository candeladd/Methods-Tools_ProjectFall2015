//Upload this sketch to the Arduino 
//(using the 'Upload' button, File | Upload or Ctrl+U).

//Turn on the Serial Monitor 
//(using the 'Serial Monitor' button, Tools | 
//Serial Monitor or Ctrl+Shift+M) 

//read Serial Monitor that will saying Test ___ Failed
///Test ___ passed 

#line 2  "sketch.io"
#include <ArduinoUnit.h>
test(ok) 
{
  int x=3;
  int y=3;
  assertEqual(x,y);
}

test(bad)
{
  int x=3;
  int y=3;
  assertNotEqual(x,y);
}

void setup()
{
  Serial.begin(9600);
  while(!Serial); // for the Arduino Leonardo/Micro only
}

void loop()
{
  Test::run();
}
