
// defining L293D motor driver pins
const int in3 = 2;     
const int in4 = 3;

void setup()
{
 pinMode(in3, OUTPUT);      // for L293D motor driver which is connected to Air Pump
  pinMode(in4, OUTPUT);
}

void loop() 
{
  FillAir();
  delay(5000);
  StopAir();
  delay(2000);
 }

    void FillAir()
    {
      digitalWrite(in3, HIGH);          
      digitalWrite(in4, LOW);
    }

   void StopAir()
   {
     digitalWrite(in3, LOW);           
     digitalWrite(in4, LOW);
   }
