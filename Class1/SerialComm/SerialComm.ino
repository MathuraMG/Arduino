#define switchPin 2
int count = 0;
int switchState;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
}

void loop() {
  count++;
  switchState = digitalRead(switchPin);
  // put your main code here, to run repeatedly:
  Serial.print("State of my switch : ");
  Serial.println(switchState);
  Serial.print("Count :  ");
  Serial.println(count);

}
