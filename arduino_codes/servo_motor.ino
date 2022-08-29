#include<Servo.h>
Servo Myservo1;
Servo Myservo2;
Servo Myservo3;
// Servo Myservo4;
// Servo Myservo5;

int pos;
void setup()
{
//Myservo.attach(3);
Myservo1.attach(A0);
Myservo2.attach(A1);
Myservo3.attach(A2);
// Myservo4.attach(A3);
// Myservo5.attach(A4);
}

void loop()
{
  
  
for(pos=0;pos<=180;pos++){
Myservo1.write(pos);
Myservo2.write(pos);
Myservo3.write(pos);
// Myservo4.write(pos);
// Myservo5.write(pos);
delay(15);
}
//  delay(1000);
  
  for(pos=180;pos>=0;pos--){
Myservo1.write(pos);
Myservo2.write(pos);
Myservo3.write(pos);
// Myservo4.write(pos);
// Myservo5.write(pos);
delay(15);
}
//  delay(1000);
  
}
