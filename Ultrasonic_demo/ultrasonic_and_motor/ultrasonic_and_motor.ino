 // defining my motor 1
const int in1 = 9;
const int in2 = 8;

// defining my motor 2
const int in3 = 7;
const int in4 = 6;

// defining Ultrasonic sensor pin  numbers
const int trigPin = 13;
const int echoPin = 2;

// defining variables for Ultrasonic sensor
long duration;
int distance;

void setup()
{
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
  Serial.begin(9600); 
  // Starts the serial communication for Serial monitor display
}
 
 void loop() 
{  
dist();
if (distance <= 200)
{
// turn on motor 1 forward direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
// turn on motor 2 froward direction
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  

if (distance <= 7)
{
  // turn motor off
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }
}

}

void dist(){
 // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
