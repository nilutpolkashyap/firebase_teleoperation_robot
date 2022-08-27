
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
}

void loop() {
  int value;

  if (Serial.available() > 0) {
    receivedChar = Serial.readStringUntil('\n');
  }
  
  int direction = receivedChar.toInt();
  Serial.println(direction);

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
