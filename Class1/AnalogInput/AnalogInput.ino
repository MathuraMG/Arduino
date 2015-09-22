#define redLED 3
#define yellowLED 4
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED , OUTPUT);
  pinMode(yellowLED , OUTPUT);
}

void loop() {
  int potVal;
  potVal = analogRead(A0);
  Serial.println(potVal);
  if (potVal > 512)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
  }
  else
  {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
  }
}
