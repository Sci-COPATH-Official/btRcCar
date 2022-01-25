#define light_FR 9   //Front Light   Digital pin 9
#define light_BR 10  //Rear Light   Digital pin 10
#define horn_Buzz 11 //Horn    Digital pin 11
#define light_EX 12  //Extra Light    Digital pin 12

//L293 Connection
const int motorAspeed = 3;
const int motorA1 = 4;
const int motorA2 = 5;
const int motorB1 = 6;
const int motorB2 = 7;
const int motorBspeed = 8;

int command;
int vSpeed = 255; // Default speed, from 0 to 255
boolean lightFront = false;
boolean lightBack = false;
boolean horn = false;
boolean lightExtra = false;

void setup()
{
  // Set pins as outputs:
  pinMode(light_FR, OUTPUT);
  pinMode(light_EX, OUTPUT);
  pinMode(light_BR, OUTPUT);
  pinMode(horn_Buzz, OUTPUT);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);
}

/********Forward*********/
//If state is equal with letter 'F', car will go forward!
void goAhead()
{
  digitalWrite(motorA1, LOW);
  delay(1);
  digitalWrite(motorA2, HIGH);
  delay(1);

  digitalWrite(motorB1, HIGH);
  delay(1);
  digitalWrite(motorB2, LOW);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}
/*******Forward Left*********/
//If state is equal with letter 'I', car will go forward left
void goAheadLeft()
{
  digitalWrite(motorA1, LOW);
  delay(1);
  digitalWrite(motorA2, HIGH);
  delay(1);

  digitalWrite(motorB1, HIGH);
  delay(1);
  digitalWrite(motorB2, LOW);

  analogWrite(motorAspeed, 0);
  analogWrite(motorBspeed, vSpeed);
}
/*******Forward Right*********/
//If state is equal with letter 'G', car will go forward right
void goAheadRight()
{
  digitalWrite(motorA1, LOW);
  delay(1);
  digitalWrite(motorA2, HIGH);
  delay(1);

  digitalWrite(motorB1, HIGH);
  delay(1);
  digitalWrite(motorB2, LOW);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, 0);
}
/********Backward*********/
//If state is equal with letter 'B', car will go backward
void goBack()
{
  digitalWrite(motorA1, HIGH);
  delay(1);
  digitalWrite(motorA2, LOW);
  delay(1);

  digitalWrite(motorB1, LOW);
  delay(1);
  digitalWrite(motorB2, HIGH);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}
/*******Backward Left*********/
//If state is equal with letter 'J', car will go backward left
void goBackLeft()
{
  digitalWrite(motorA1, HIGH);
  delay(1);
  digitalWrite(motorA2, LOW);
  delay(1);

  digitalWrite(motorB1, LOW);
  delay(1);
  digitalWrite(motorB2, HIGH);

  analogWrite(motorAspeed, 0);
  analogWrite(motorBspeed, vSpeed);
}
/*******Backward Right*********/
//If state is equal with letter 'H', car will go backward right
void goBackRight()
{
  digitalWrite(motorA1, HIGH);
  delay(1);
  digitalWrite(motorA2, LOW);
  delay(1);

  digitalWrite(motorB1, LOW);
  delay(1);
  digitalWrite(motorB2, HIGH);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, 0);
}
/**********Left**********/
//If state is equal with letter 'L', wheels will turn left
void goLeft()
{
  digitalWrite(motorA2, LOW);
  delay(1);
  digitalWrite(motorA1, HIGH);
  delay(1);

  digitalWrite(motorB2, LOW);
  delay(1);
  digitalWrite(motorB1, HIGH);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}
/**********Right**********/
//If state is equal with letter 'R', wheels will turn right
void goRight()
{
  digitalWrite(motorA2, HIGH);
  delay(1);
  digitalWrite(motorA1, LOW);
  delay(1);

  digitalWrite(motorB2, HIGH);
  delay(1);
  digitalWrite(motorB1, LOW);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}

/*********Stop**********/
//If state is equal with letter 'S', stop the car
void stopRobot()
{
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

void loop()
{

  if (Serial.available() > 0)
  {
    command = Serial.read();
    stopRobot(); //Initialize with motors stopped.

    if (lightFront)
    {
      digitalWrite(light_FR, HIGH);
    }
    if (!lightFront)
    {
      digitalWrite(light_FR, LOW);
    }
    if (lightBack)
    {
      digitalWrite(light_BR, HIGH);
    }
    if (!lightBack)
    {
      digitalWrite(light_BR, LOW);
    }
    if (horn)
    {
      digitalWrite(horn_Buzz, HIGH);
    }
    if (!horn)
    {
      digitalWrite(horn_Buzz, LOW);
    }
    if (lightExtra)
    {
      digitalWrite(light_EX, HIGH);
    }
    if (!lightExtra)
    {
      digitalWrite(light_EX, LOW);
    }

    switch (command)
    {
    case 'F':
      goAhead();
      break;
    case 'B':
      goBack();
      break;
    case 'L':
      goLeft();
      break;
    case 'R':
      goRight();
      break;
    case 'I':
      goAheadRight();
      break;
    case 'G':
      goAheadLeft();
      break;
    case 'J':
      goBackRight();
      break;
    case 'H':
      goBackLeft();
      break;
    case '0':
      vSpeed = 100;
      break;
    case '1':
      vSpeed = 115;
      break;
    case '2':
      vSpeed = 130;
      break;
    case '3':
      vSpeed = 145;
      break;
    case '4':
      vSpeed = 160;
      break;
    case '5':
      vSpeed = 175;
      break;
    case '6':
      vSpeed = 190;
      break;
    case '7':
      vSpeed = 205;
      break;
    case '8':
      vSpeed = 220;
      break;
    case '9':
      vSpeed = 235;
      break;
    case 'q':
      vSpeed = 255;
      break;
    case 'W':
      lightFront = true;
      break;
    case 'w':
      lightFront = false;
      break;
    case 'U':
      lightBack = true;
      break;
    case 'u':
      lightBack = false;
      break;
    case 'V':
      horn = true;
      break;
    case 'v':
      horn = false;
      break;
    case 'X':
      lightExtra = true;
      break;
    case 'x':
      lightExtra = false;
      break;
    }
  }
}