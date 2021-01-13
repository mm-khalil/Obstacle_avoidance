#include <Arduino.h>

//Declare all the variables being used here:
int centerIR;
int leftIR;
int rightIR;

int leftFlag;
int centerFlag;
int rightFlag;

//Declare all the functions being used here:
void deviateRight();
void deviateLeft();
void forward();
void reverse();

void setup()
{
  // put your setup code here, to run once:
  pinMode(6 ,  OUTPUT);
  pinMode(9 ,  OUTPUT);
  pinMode(10,  OUTPUT);
  pinMode(11,  OUTPUT);

  pinMode     (7, OUTPUT);
  pinMode     (8, OUTPUT);
  digitalWrite(7,   HIGH);
  digitalWrite(8,   HIGH);

  
}

void loop()
{
  // put your main code here, to run repeatedly:
  centerIR = analogRead (A0);
  leftIR   = analogRead (A1);
  rightIR  = analogRead (A2);


  if (leftIR < 200)
  {  leftFlag = 1;  }
  else
  {  leftFlag = 0;  }


  if (rightIR < 200)
  {  rightFlag = 1; }
   else
  {  rightFlag = 0; }


  if (centerIR < 200)
  {  centerFlag = 1;  }
  else
  {  centerFlag = 0;  }


  if ((leftFlag == 1) || (rightFlag == 1) || (centerFlag == 1))
  {  if (centerFlag == 1)
     {  if (leftFlag == 1)
        {  deviateRight();  }


      else if (rightFlag == 1)
        deviateLeft();
      else
        deviateLeft();   }

        
    else if (leftFlag == 1)
    {  deviateRight();  }
    else if (rightFlag == 1)
    {  deviateLeft();   }
    else
    {  deviateLeft();  }  }
  else
  {  forward();  }  }


//Function definitions go here:
void reverse()
{ digitalWrite(9 , LOW);
  analogWrite (6 ,  75);
  analogWrite (11,  75);
  digitalWrite(10, LOW);
  delay(1000);              }


void deviateRight()
{ reverse();
  digitalWrite(6 , LOW);
  digitalWrite(9 , LOW);
  digitalWrite(11, LOW);
  analogWrite(10 , 350);
  delay(300);               }


void deviateLeft()
{ reverse();
  analogWrite (9 , 350);
  digitalWrite(6 , LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(300);               }

void forward()
{ analogWrite  (9 ,   75);
  digitalWrite (6 ,  LOW);
  digitalWrite (11,  LOW);
  analogWrite  (10,   75);  }
