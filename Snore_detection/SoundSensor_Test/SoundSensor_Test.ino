int micpin = A0;    // arduino analog pin A0 connected to sound sensor A0 pin 
int micvalue1 =1000;
int micvalue2 =1000;
int micvalue3=1000;

void setup() 
{
  pinMode(micpin,INPUT);     // gives input signals to the arduino board micvalue1 and micvalaue2
  Serial.begin(9600);        // for displaying into serial monitor

}

void loop() 
{     micvalue1 = analogRead(micpin);
       Serial.println(micvalue1);
       delay(70);
       micvalue2 = analogRead(micpin);
       Serial.println(micvalue2);
    if (micvalue1<300&&micvalue2<300&&micvalue3!=micvalue1)
    {
      Serial.println("0000000000snooorreeeeeeeeee");
    }
 
 
 }
