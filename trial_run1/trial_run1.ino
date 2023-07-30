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
const int in1 = 9;
const int in2 = 10;

// defining my motor 2
const int in3 = 11;
const int in4 = 12;


void setup()
{ 
  myservo.attach(3);       // pin for servo motor
  
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
  

}
 
 

void loop()

{  
  
   delay(5000);                   // giving some time to bot to start the process
   //detectcolor();                  // calling detect color function
  
  // bot starts to move forward for 2 seconds
  digitalWrite(in1, HIGH);              // turn on motor 1 forward direction
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);             // turn on motor 2 froward direction
  digitalWrite(in4, LOW);
  delay(2000);                           // moving forward for 2 seconds
  
  // bot stops for 1 second
  digitalWrite(in1, LOW);              // turn on motor 1 off
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);             // turn on motor 2 off
  digitalWrite(in4, LOW);
  delay(1000);                        // stoping for 1 second
  
  detectcolor();                      // calling detectcolor function to detect color using tcs 3200
  delay(4000);                        // wait for 2 second to detect color
  
if (frequency1>30 && frequency1<300)            // settting condition for checking if object has RED color 
  { 
    Serial.println(" detected red color object ");   // printing on the screen
    myservo.write(-80);                             // open up the gripper
    delay(2000);                                     // wait for 2 second  
    myservo.write(80);                              // close the gripper
    delay(2000);                                     //wait for 2 second
    
   //  as red color is detected now bot goes backward to original location
  
  digitalWrite(in1, LOW);                // turn on motor 1 reverse direction
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);               // turn on motor 2 reverse  direction
  digitalWrite(in4, HIGH);
   delay(2000);                       // bot goes back for 2 second
  
  // now bot stops
  // motor 1
  digitalWrite(in1, LOW);          // motor 1 turns off
  digitalWrite(in2, LOW);
  // Motor 2
  digitalWrite(in3, LOW);           // motor 2 turns off
  digitalWrite(in4, LOW);
  delay(1000);
  
  // TAKES RIGHT TURN
  // turn on motor 1 on
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
//turn on motor 2 on
digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 delay(1200);
 // motor 1
  digitalWrite(in1, LOW);          // motor 1 turns off
  digitalWrite(in2, LOW);
  // Motor 2
  digitalWrite(in3, LOW);           // motor 2 turns off
  digitalWrite(in4, LOW);
  delay(1000);

  
 
 // bot keeps the object in ground  
    myservo.write(-80);             // grips open
    delay(2000);                    // wait for 2 second
    myservo.write(80);              // grips closed
    delay(2000);  // wait for 2 second to start process again
// turn on motor 1 on
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
//turn on motor 2 on
digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 delay(1200);
 // motor 1
  digitalWrite(in1, LOW);          // motor 1 turns off
  digitalWrite(in2, LOW);
  // Motor 2
  digitalWrite(in3, LOW);           // motor 2 turns off
  digitalWrite(in4, LOW);
  delay(1000);

    
    
  }    // if fucntion closed  
 

else                         // if red color was not detected then go back to original location
 
 {
  // turn on motor 1 reverse direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
   // turn on motor 2 reverse  direction
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);

  // turn motor off
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
   
   }   //else function closed 
}
// loop function closed

 
  
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
  
  
  
 
   

 


