int blinkSpeed = 150;
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
  // put your main code here, to run repeatedly:
//
//  int speedPot;
//  speedPot = analogRead(A3);
//  blinkSpeed = speedPot / 10 + 10;
//
//  int patternPot;
//  patternPot = analogRead(A2);
//  value = map(patternPot, 0, 1024, 1, 6);
//  Serial.println(value);
//
//  if ( value == 1)
//  {
//    blinkRow();
//  }
//  else if (value == 2)
//  {
//    blinkColumn();
//  }
//  else if (value == 3)
//  {
//    paintRow();
//  }
//  else if (value == 4)
//  {
//    paintColumn();
//  }
//  else if (value == 5)
//  {
//    zoomOut();
//  }
  //    blinkRow();
  //blinkColumn();
  //paintRow();
  //paintColumn();
  //oneByOne();
  allButOne();
}

void blinkRow()
{

  setAllLow();
  for (int j = 9; j <= 13; j++)
  {

    delay(blinkSpeed);
    digitalWrite(j, HIGH);

    delay(blinkSpeed);
    digitalWrite(j, LOW);
  }


}

void blinkColumn()
{
  setAllHigh();
  //display the columns one by one
  for (int j = 2; j <= 6; j++)
  {

    delay(blinkSpeed);
    digitalWrite(j, LOW);

    delay(blinkSpeed);
    digitalWrite(j, HIGH);
  }
}


void paintRow()
{

  setAllLow();
  for (int j = 9; j <= 13; j++)
  {

    digitalWrite(j, LOW);
    delay(blinkSpeed);

    digitalWrite(j, HIGH);
    delay(blinkSpeed);
  }
}

void paintColumn()
{
  setAllHigh();
  //paint the columns one by one
  for (int j = 2; j <= 6; j++)
  {

    digitalWrite(j, HIGH);
    delay(blinkSpeed);

    digitalWrite(j, LOW);
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

void oneByOne()
{


  for (int j = 9; j <= 13; j++)
  {
    setAllIn();
    setOut(j);
    digitalWrite(j, HIGH);
    for (int i = 2; i <= 6; i++)
    {
      setOut(i);
      digitalWrite(i, LOW);
      delay(blinkSpeed);
      digitalWrite(i, HIGH);
    }

  }

  setAllOut();

}


void allButOne()
{

setAllIn();
  for (int j = 9; j <= 13; j++)
  {
    //setAllIn();
    setOut(j);
    digitalWrite(j, HIGH);
    for (int i = 2; i <= 6; i++)
    {
      setOut(i);
      digitalWrite(i, LOW);
      delay(blinkSpeed);
      digitalWrite(i, HIGH);
    }

  }

 // setAllOut();

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

void zoomOut()
{

  setAllIn();
  setOut(11);
  setOut(4);
  digitalWrite(11, HIGH);
  digitalWrite(4, LOW);
  delay(blinkSpeed * 2);

  setOut(5);
  setOut(3);
  setOut(10);
  setOut(12);
  digitalWrite(10, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(3, LOW);
  delay(blinkSpeed * 2);

  setOut(6);
  setOut(2);
  setOut(9);
  setOut(13);
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(2, LOW);
  delay(blinkSpeed * 2);

  setAllOut();

}

