
const int buzzer = 4;

void setup() 
{
  pinMode(buzzer, OUTPUT);   // put your setup code here, to run once:

}

void loop() 
{


  tone(buzzer, 1000); // Send 1KHz sound signal...
        delay(1000);        // ...for 1 sec
        noTone(buzzer);     // Stop sound...
        delay(1000);        // ...for 1sec
  // put your main code here, to run repeatedly:

}
