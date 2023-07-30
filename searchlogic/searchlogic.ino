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
 

  
  // for motor control  
  pinMode(in1, OUTPUT);         // motor 1
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);          // motor 2
  pinMode(in4, OUTPUT);
  
  // for ultrasonic sensor
  pinMode(trigPin, OUTPUT);    // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);     // Sets the echoPin as an Input   
    Serial.begin(9600);         // for displaying results on laptop screen
}

void loop()
{  detectdistance();
   left();
   
   if ( distance<70)
   {
        forward();
        detectdistance();
        if (distance<=13)
        {
          halt();
          delay(8000);
        } 
        if (distance>70)
     {
      right();
     }
   }
  // else if (distance>80)
   //{
     // right();
    
   }
                    //else 
                //{
                 // left();
                   //delay(1000);
              //halt();
    //detectdistance();
    //delay(4000);
   // goto again;
// }
  
 




void detectdistance()
{
   
   digitalWrite(trigPin, LOW);         // Clears the trigPin   
   delayMicroseconds(10);
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


void left()
{  digitalWrite(in1, HIGH);              // turn on motor 1 forward direction
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);             // turn on motor 2 froward direction
   digitalWrite(in4, HIGH);
   
}
void right()
{  digitalWrite(in1, LOW);              // turn on motor 1 forward direction
   digitalWrite(in2, HIGH);
   digitalWrite(in3, HIGH);             // turn on motor 2 froward direction
   digitalWrite(in4, LOW);
   
}
  
