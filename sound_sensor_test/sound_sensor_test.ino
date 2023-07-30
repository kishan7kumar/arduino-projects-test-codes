int micpin = A0;   // arduino analog pin A0 connected to sound sensor A0 pin 
int m1 = 0;
int m2 = 0;


void setup() {
  pinMode(micpin,INPUT);     // gives input signals to the arduino board micvalue1 and micvalaue2
 Serial.begin(9600);   
  // put your setup code here, to run once:

}

void loop() 

{
  m1 = analogRead(micpin);            //Serial.println(micvalue1);   
  delay(90);
  Serial.println(m1);
  
       m2 = analogRead(micpin);
         Serial.println(m2);
         if (m1<300||m2<300)
         {
          Serial.println( "snorrrring");
         }
       //delay(70);

}
