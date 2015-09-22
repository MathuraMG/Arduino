int blinkSpeed = 2;
int count = 1;
int totalCount = 5;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  setAllOut();

  pinMode(7, INPUT);

  Serial.begin(9600);

}

void loop() {
  for(int i=1;i<=5;i++)
  {
    justOne(i,i);
    delay(blinkSpeed);
  }
  
}

void setAllHigh()
{
  for (int j = 9; j <= 13; j++)
  {
    digitalWrite(j, HIGH);
  }
  for (int j = 2; j <= 6; j++)
  {
    digitalWrite(j, HIGH);
  }
}

void setAllLow()
{
  //paint the rows one by one
  for (int j = 9; j <= 13; j++)
  {
    digitalWrite(j, LOW);
  }
  for (int j = 2; j <= 6; j++)
  {
    digitalWrite(j, LOW);
  }
}

void justOne(int i, int j)
{
  i=i+1;
  j=j+8;
  Serial.println(j);
  setAllIn();
  setOut(j);
  digitalWrite(j, HIGH);
  setOut(i);
  digitalWrite(i, LOW);


}

void setAllIn()
{
  for (int j = 9; j <= 13; j++)
  {
    pinMode(j, INPUT);
  }
  for (int j = 2; j <= 6; j++)
  {
    pinMode(j, INPUT);
  }
}

void setAllOut()
{
  for (int j = 9; j <= 13; j++)
  {
    pinMode(j, OUTPUT);
  }
  for (int j = 2; j <= 6; j++)
  {
    pinMode(j, OUTPUT);
  }
}

void setOut(int no)
{
  pinMode(no, OUTPUT);
}

