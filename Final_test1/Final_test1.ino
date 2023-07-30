#include <Servo.h>              // for servo motor
Servo myservo;                  // for servo motor


#define S0 4                      //pins of color sensor
#define S1 5                //pins of color sensor
#define S2 6                 //pins of color sensor
#define S3 7                 //pins of color sensor
#define sensorOut 8
 int frequency1 = 0;             // for red diode
 int frequency2 = 0;             // for green diode
 int frequency3 = 0;             // for blue diode

 int pos = 0;             // for servo motor

// defining my motor 1
const int in1 = 9;
const int in2 = 10;

// defining my motor 2
const int in3 = 11;
const int in4 = 12;

// defining Ultrasonic sensor pin  numbers
const int trigPin = 13;
const int echoPin = 2;

// defining variables for Ultrasonic sensor
long duration;
int distance;

void setup()
{ 
  myservo.attach(3);       // pin for servo motor
  
  // pins for color sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20% of color sensor
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);         // for displaying results on laptop screen
  
  // for motor control  
  // motor 1
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // motor 2
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // for ultrasonic sensor
  pinMode(trigPin, OUTPUT);    // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);     // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication for Serial monitor display
}
 
 void loop() 
{

// STEP 1: FOR CALCULATING DISTANCE


digitalWrite(trigPin, LOW);                  // Clears the trigPin
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);                    // Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);               // Reads the echoPin, returns the sound wave travel time in microseconds

distance= duration*0.034/2;                  // Calculating the distance

Serial.print("Distance: ");                  //Prints the distance on the Serial Monitor
Serial.println(distance);

// STEP 2: MOVE THE BOT FORWARD


  digitalWrite(in1, HIGH);              // turn on motor 1 forward direction
  digitalWrite(in2, LOW);
  

  digitalWrite(in3, LOW);             // turn on motor 2 froward direction
  digitalWrite(in4, HIGH);


// STEP 3: STOPPING NEAR THE OBJECT

if (distance < 2)
{
  // turn motors off that is stop the bot 
  // motor 1 OFF
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Motor 2 OFF
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // COLOR DETECTION PROCESS STARTS
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency1= pulseIn(sensorOut, LOW);              // Reading the output frequency of red color
  
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequency2 = pulseIn(sensorOut, LOW);             // Reading the output frequency of green color
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequency3 = pulseIn(sensorOut, LOW);                // Reading the output frequency o blue color
  

   // STEP 4: DETECTING RED COLOR AND PICKING THE OBJECT
    
    if ( frequency1<40 && frequency1>0)
  { 
    
    //Serial.println(" red");
    
    myservo.write(200);              // tell servo to go to position in variable 'pos' and gripper starts to hold object
    delay(5000); 
    
   // turn on motor 1 reverse direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
   // turn on motor 2 reverse  direction
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(4000);
  
  // turn motor off
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(3000);
  myservo.write(0);            // open the gripper
  delay(3000);
    
    }   //if color ends

    else                // if not red color then go back to original postition
   {  
       // turn on motor 1 reverse direction
       digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
  
      // turn on motor 2 reverse  direction
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(2000);   // go back till 2 sec 
   }
 
  } // if distance ends

} // loop ends

 
 
