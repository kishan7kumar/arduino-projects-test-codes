
// defining my right 3 motors 

const int in1 = 8;
const int in2 = 9;

// defining my left 3 motors

const int in3 = 10;
const int in4 = 11;


void setup()
{
  // set all the motor control pins to outputs
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 

 
 }
 void loop()
 {


   // turn on motor A forward direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
//turn on motor B froward direction
digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);

 delay(10000);
 
 
 // move right
 digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
 
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 delay(5000);

 }
 
 
 

