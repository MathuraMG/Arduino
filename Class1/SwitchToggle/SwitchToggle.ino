#define redLED  3
#define yellowLED  4
#define switchPin  2



void setup() {
  //set the LED pins
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(switchPin, INPUT);

}

void loop() {
  // Turn the LED on if the switch is on
  if (digitalRead(switchPin) == true ) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, HIGH);
  }
  else
  {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
  }
}
