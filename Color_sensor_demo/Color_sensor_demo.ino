#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
 int frequency1 = 0;
int frequency2 = 0;
 int frequency3 = 0;
void setup() 
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() 
{
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency1= pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
 
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency2 = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  
  
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency3 = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  
 
  delay(100);

  if ( frequency3>20 && frequency3<60)
  { Serial.println(" blue ");
  }
   if ( frequency1<40)
  { Serial.println(" red");
  }
  
}
