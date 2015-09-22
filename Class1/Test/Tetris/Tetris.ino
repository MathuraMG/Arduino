int blinkSpeed = 1;
int gameSpeed = 500;
int count = -10;
int totalCount = 5;
int value = 0;
int test[5][5];
int test1[5][5] = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
int exist[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
int test2[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
int bottom[5] = {4, 4, 4, 4, 4};
int potVal;
int sideVal;
int pixX = -1;
int pixY = 0;
int pixOld = -1;
int flag = 1;

void setup() {
  // put your setup code here, to run once:
  setAllOut();
  pinMode(7, INPUT);
  Serial.begin(9600);

}

void loop() {
  count++;
  potVal = analogRead(A3);
  sideVal = analogRead(A2);

  gameSpeed = potVal / 2 + 20;
  game();

}




void matrixPrint(int arr[5][5])
{
  for (int i = 0; i <= 4; i++)
  {
    for (int j = 0; j <= 4; j++)
    {
      if (arr[i][j] > 0 )
      {
        delay(blinkSpeed);
        justOne(4 - i + 1, j + 1);
      }
    }
  }
}



void justOne(int i, int j)
{
  i = i + 1;
  j = j + 8;
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

void testPattern1()
{
  /*
  * o o o o x
  * o o o o o
  * o o o o o
  * o o o o o
  * x x x x x
  */
  int test[5][5] = {{0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}};
  matrixPrint(test);
}
void testPattern2()
{
  /*
  * x o o o x
  * o x o x o
  * o o x o o
  * o x o x o
  * x o o o x
  */
  int test[5][5] = {{1, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 0, 1}};
  matrixPrint(test);
}


void gameOver()
{
  zoomOut();
}

void game()
{
  if (flag == 1)
  {

    matrixPrint(test2);


    if (count % gameSpeed == 0)
    {
      test[pixX][pixOld] = 0;
      pixY = sideVal / 250;

      if (exist[pixX + 1][pixY] == 2 || pixX == 4)
      {
        test[pixX][pixY] = 0;
        exist[pixX][pixY] = 2;
        pixX = 0;
        test[pixX][pixY] = 1;
        pixOld = pixY;

      }
      else
      {
        test[pixX][pixY] = 0;
        test[pixX + 1][pixY] = 1;
        pixOld = pixY;
        pixX++;
      }
      checkRow(exist);
      for (int i = 0; i <= 4; i++)
      {
        for (int j = 0; j <= 4; j++)
        {

          test2[i][j] = exist[i][j] + test[i][j];
          //Serial.print(count);
          //Serial.print(test2[i][j]);
          //Serial.print(" ");
          if (test2[i][j] == 3)
          {

            flag = 0;
          }

        }
        //Serial.print("\n");
      }
      //Serial.print("\n\n");
    }


  }
  if (flag == 0)
  {
    gameOver();
    if ( digitalRead(7) == HIGH)
    {
      reset();
    }
  }

}

void zoomOut()
{

  setAllIn();
  setOut(11);
  setOut(4);
  digitalWrite(11, HIGH);
  digitalWrite(4, LOW);
  delay(gameSpeed * 2);

  setOut(5);
  setOut(3);
  setOut(10);
  setOut(12);
  digitalWrite(10, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(3, LOW);
  delay(gameSpeed * 2);

  setOut(6);
  setOut(2);
  setOut(9);
  setOut(13);
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(2, LOW);
  delay(gameSpeed * 2);

  setAllOut();

}

void checkRow(int arr[5][5])
{
  int total = 0;
  for (int i = 0; i <= 4; i++)
    total += arr[4][i];

  if (total == 10)
  {
    //shift the array down
    for (int i = 4; i >= 1; i--)
    {
      for (int j = 0; j <= 4; j++)
      {
        arr[i][j] = arr[i - 1][j];
      }
    }
  }
}

void reset()
{
  // Restarts program from beginning but does not reset the peripherals and registers

  asm volatile ("  jmp 0");

  //  //setAllIn();
  //  count = -10;
  //  for (int i = 0; i <= 4; i++)
  //    {
  //      for (int j = 0; j <= 4; j++)
  //      {
  //        exist[i][j] = 0;
  //        test2[i][j] =0;
  //
  //      }
  //    }
  //
  //    flag = 1;
}

