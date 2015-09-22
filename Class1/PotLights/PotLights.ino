#define LED1 5
#define LED2 6
#define LED3 7
#define LED4 8
#define pot A5
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
}

void loop() {
  int potVal;
  potVal = analogRead(A5);
  Serial.println(potVal);
  for(int thisPin = 5; thisPin <=8; thisPin++)
  {
    digitalWrite(thisPin, LOW);
  }

  if (potVal < 256 && potVal >= 0)
  {
    digitalWrite(LED1, HIGH);
  }
  else if (potVal < 512 && potVal >= 256)
  {
    digitalWrite(LED2, HIGH);
  }
  else if (potVal < 768 && potVal >= 512)
  {
    digitalWrite(LED3, HIGH);
  }
  else if (potVal < 1024 && potVal >= 768)
  {
    digitalWrite(LED4, HIGH);
  }
}
