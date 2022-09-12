#include<Servo.h>
Servo Myservo1;
Servo Myservo2;
Servo Myservo3;
int pos;

/**set control port**/
const int E1Pin = 10;
const int M1Pin = 12;
const int E2Pin = 11;
const int M2Pin = 13;

String receivedChar;

/**inner definition**/
typedef struct {
  byte enPin;
  byte directionPin;
} MotorContrl;

const int M1 = 0;
const int M2 = 1;
const int MotorNum = 2;

const MotorContrl MotorPin[] = { {E1Pin, M1Pin}, {E2Pin, M2Pin} } ;

const int Forward = LOW;
const int Backward = HIGH;

/**program**/
void setup() {
  Serial.begin(9600);
  initMotor();
  
  Myservo1.attach(A0);
  Myservo2.attach(A1);
  Myservo3.attach(A3);
}

void loop() {
  int value;

  if (Serial.available() > 0) {
    receivedChar = Serial.readStringUntil('\n');
    Serial.println(receivedChar[0]);
  }
  
  if(receivedChar[0] == 'M')
  {
    //char direc = receivedChar[1];
    //int direction = receivedChar.toInt();
    //int direction = direc.toInt();
    int direction = receivedChar[1] - '0';
    Serial.println(direction);
    //Serial.println(direction);
    
    if(direction == 0)
    {
      setMotorDirection( M1, Forward );
      setMotorDirection( M2, Forward );
      setMotorSpeed( M1, 0 );
      setMotorSpeed( M2, 0 );
    }
  
    if(direction == 1)
    {
      setMotorDirection( M1, Forward );
      setMotorDirection( M2, Forward );
      setMotorSpeed( M1, 100 );
      setMotorSpeed( M2, 100 );
    }
  
    if(direction == 2)
    {
      setMotorDirection( M1, Backward );
      setMotorDirection( M2, Backward );
      setMotorSpeed( M1, 100 );
      setMotorSpeed( M2, 100 );
    }
    
    if(direction == 3)
    {
      setMotorDirection( M1, Forward );
      setMotorDirection( M2, Backward );
      setMotorSpeed( M1, 100 );
      setMotorSpeed( M2, 100 );
    }
    
    if(direction == 4)
    {
      setMotorDirection( M1, Backward );
      setMotorDirection( M2, Forward );
      setMotorSpeed( M1, 100 );
      setMotorSpeed( M2, 100 );
    }
  }
  
  if(receivedChar[0] == 'A')
  {
    int angle = receivedChar[1] - '0';
    
    if(angle == 0)
    {
      Servo1_write(angle*10);
      Serial.println("ARM0");
    }
    if(angle == 1)
    {
      Servo1_write(angle*10);
      Serial.println("ARM1");
    }
    if(angle == 2)
    {
      Servo1_write(angle*10);
      Serial.println("ARM2");
    }
    if(angle == 3)
    {
      Servo1_write(angle*10);
      Serial.println("ARM3");
    }
    //Servo1_write(angle*10);
  }
  
  if(receivedChar[0] == 'G')
  {
    int angle = receivedChar[1] - '0';
    
    if(angle == 0)
    {
      Servo2_write(angle*10);
      Serial.println("GRP0");
    }
    if(angle == 1)
    {
      Servo2_write(angle*10);
      Serial.println("GRP1");
    }
    if(angle == 2)
    {
      Servo2_write(angle*10);
      Serial.println("GRP2");
    }
    if(angle == 3)
    {
      Servo2_write(angle*10);
      Serial.println("GRP3");
    }
    if(angle == 4)
    {
      Servo2_write(angle*10);
      Serial.println("GRP3");
    }
    if(angle == 5)
    {
      Servo2_write(angle*10);
      Serial.println("GRP3");
    }
    //Servo2_write(angle*10);
  }
  
//  if(receivedChar[0] == 'Z')
//  {
//    int angle = receivedChar[1] - '0';
//    Servo3_write(angle*10);
//  }
}

void Servo1_write(int pos)
{
  Myservo1.write(pos);
}

void Servo2_write(int pos)
{
  Myservo2.write(pos);
}

void Servo3_write(int pos)
{
  Myservo3.write(pos);
}

/**functions**/
void initMotor( ) {
  int i;
  for ( i = 0; i < MotorNum; i++ ) {
    digitalWrite(MotorPin[i].enPin, LOW);

    pinMode(MotorPin[i].enPin, OUTPUT);
    pinMode(MotorPin[i].directionPin, OUTPUT);
  }
}

/**  motorNumber: M1, M2
direction:          Forward, Backward **/
void setMotorDirection( int motorNumber, int direction ) {
  digitalWrite( MotorPin[motorNumber].directionPin, direction);
}

/** speed:  0-100   * */
inline void setMotorSpeed( int motorNumber, int speed ) {
  analogWrite(MotorPin[motorNumber].enPin, 255.0 * (speed / 100.0) ); //PWM
}
