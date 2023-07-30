
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//int pos;    // variable to store the servo position

void setup()
{
  myservo.attach(3);
  serv();
  // attaches the servo on pin 9 to the servo object
}
void serv()
{  myservo.write(70);   //hold 
   delay(2000);
   myservo.write(0);     // drop
  //for (pos = 0; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
   // myservo.write(pos);              // tell servo to go to position in variable 'pos'
   // delay(5);                       // waits 15ms for the servo to reach the position
  //}
  //for (pos =80; pos >= 0; pos -= 1) 
  //{ 
    //myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(5);                       // waits 15ms for the servo to reach the position
 //}
}
void loop()
{
}


