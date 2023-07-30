#include <Servo.h>              // for servo motor
Servo myservo;                  // for servo motor

#define S0 4                 //pins of color sensor
#define S1 5                //pins of color sensor
#define S2 6                 //pins of color sensor
#define S3 7                 //pins of color sensor
#define sensorOut 8
 int frequency1 = 0;             // for red diode
 int frequency2 = 0;             // for green diode
 int frequency3 = 0;             // for blue diode

 int pos = 0;             //  position for servo motor

// defining my motor 1
const int in1 = 2;
const int in2 = 3;

// defining my motor 2
const int in3 = 11;
const int in4 = 12;

// defines pins numbers for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;
// defines variables for ultrasonic sensor
long duration;
int distance;


void setup()

{ 
  
  //for servo motor
  myservo.attach(13);       
  
  // pins for color sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);           // Setting frequency-scaling to 20% of color sensor
  digitalWrite(S1,LOW);
  Serial.begin(9600);         // for displaying results on laptop screen
  
  // for motor control  
  pinMode(in1, OUTPUT);         // motor 1
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);          // motor 2
  pinMode(in4, OUTPUT);
  
  // for ultrasonic sensor
  pinMode(trigPin, OUTPUT);    // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);     // Sets the echoPin as an Input   
  Serial.begin(9600);        // for displaying in the monitor
  

}
 
 

void loop()

{  
   detectdistance();                 // calling detect distance function
  
  
  // bot starts to move forward 
  forward();
  
 if (distance > 3 && distance <= 13)
{ 
  
  // bot stops
  halt();
  delay(1000);
  
  detectcolor();                      // calling detectcolor function to detect color using tcs 3200
  delay(4000);                        // wait for 2 second to detect color
  
  if (frequency1>30 && frequency1<300)            // settting condition for checking if object has RED color 
  { 
    Serial.println(" detected red color object ");   // printing on the screen
    myservo.write(-80);                             // open up the gripper
    delay(2000);
    forward();
    delay(500);
    halt();
    delay(500);// wait for 2 second  
    myservo.write(80);                              // close the gripper
    delay(2000);                                     //wait for 2 second
    
   //  as red color is detected now bot goes backward to original location
  // bot reverses
     backward();
   delay(2000);                       // bot goes back for 2 second
  
  // now bot stops
  halt();
  delay(1000);
 
 // bot keeps the object in ground  
    myservo.write(-80);             // grips open
    delay(2000);                    // wait for 2 second
    myservo.write(80);              // grips closed
    delay(8000);                     // wait for 8 second to start process again
    
  }    // if condtion closed  
 

else               // if red color was not detected then go back to original location
 
 {
  backward();
  delay(2000);

  // turn motors off
 halt();
  delay(1000);
   
    }   //else condtion closed 
  } // if condition closed
}// loop function closed

 
  
  void detectcolor()
{ 
   //COLOR DETECTION PROCESS STARTS
   //Setting red filtered photodiodes to be read
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    frequency1= pulseIn(sensorOut, LOW);              // Reading the output frequency of red color
  
   //Setting Green filtered photodiodes to be read
       digitalWrite(S2,HIGH);
     digitalWrite(S3,HIGH);
     frequency2 = pulseIn(sensorOut, LOW);             // Reading the output frequency of green color
  
   //Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
   frequency3 = pulseIn(sensorOut, LOW);                // Reading the output frequency o blue color
  
  
}


void detectdistance()
{
   
   digitalWrite(trigPin, LOW);         // Clears the trigPin   
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);        // Sets the trigPin on HIGH state for 10 micro seconds
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
   distance= duration*0.034/2;         // Calculating the distance
   Serial.print("Distance: ");         // Prints the distance on the Serial Monitor
   Serial.println(distance);

}

void forward()
{
   digitalWrite(in1, HIGH);              // turn on motor 1 forward direction
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);             // turn on motor 2 froward direction
  digitalWrite(in4, LOW);
}

void halt()
{
   digitalWrite(in1, LOW);              // turn on motor 1 off
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);             // turn on motor 2 off
  digitalWrite(in4, LOW);
}

void backward()
{
  digitalWrite(in1, LOW);                // turn on motor 1 reverse direction
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);               // turn on motor 2 reverse  direction
  digitalWrite(in4, HIGH);
}
