#include<Servo.h>
Servo Myservo1;
Servo Myservo2;
Servo Myservo3;
int pos;
void setup()
{
Myservo1.attach(A0);
Myservo2.attach(A1);
Myservo3.attach(A5);
}

void loop()
{
//  Myservo1.write(0);
//  Myservo2.write(0);
//  Myservo3.write(0);
//  delay(2000);
//  Myservo1.write(90);
//  Myservo2.write(90);
//  Myservo3.write(90);
//  delay(2000);
//  Myservo1.write(180);
//  Myservo2.write(180);
//  Myservo3.write(180);
//  delay(2000);

//  Myservo3.write(0);
//  delay(2000);
//  Myservo3.write(90);
//  delay(2000);
  
//  Myservo.write(0);
//  delay(2000);
//  Myservo.write(90);
//  delay(2000);
//  Myservo.write(180);
//  delay(2000);
//  
  for(pos=0;pos<=180;pos++){
    //Myservo.write(pos);
    Myservo1.write(pos);
    Myservo2.write(pos);
    Myservo3.write(pos);
    delay(15);
  }
  delay(1000);
  
  for(pos=180;pos>=0;pos--){
    //Myservo.write(pos);
    Myservo1.write(pos);
    Myservo2.write(pos);
    Myservo3.write(pos);
    delay(15);
  }
  delay(1000);
  
}
