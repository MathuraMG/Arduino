#include <SD.h>

void setup() {
  pinMode(2, INPUT);    // set the switch pin to be an input
  pinMode(3, OUTPUT);   // set the yellow LED pin to be an output
  pinMode(4, OUTPUT);   // set the red LED pin to be an output
}
int count = 0;
void loop() {
  // put your main code here, to run repeatedly:
  SD.open("C:/ITP/PCom/log.txt");
  if(digitalRead(2)==HIGH)
  {
    count++;
    if(count%100)
    {
      digitalWrite(3, LOW);     // turn off the yellow LED
      digitalWrite(4, HIGH);
    }
    else
    {
      digitalWrite(4, LOW);     // turn on the yellow LED
      digitalWrite(3, HIGH);      
    }
    
  }
  else
  {
      digitalWrite(4, LOW);     // turn on the yellow LED
      digitalWrite(3, LOW);
  }

}
