// defining Sound sensor
int micpin = A0;   // arduino analog pin A0 connected to sound sensor A0 pin 
 int mic1=  1000;
 int mic2 = 1000;
 int mic3 = 1000;
 int mic4 = 1000;
// int mic5 = 1000;
// int mic6 = 0;
// int mic7 = 0;
// int mic8 = 0;
// int mic9 = 0;
// int mic10 = 0;
// int mic11 = 0;
// int mic12 = 0;
// int mic13 = 0;
// int mic14 = 0;
// int mic15 = 0;
// defining L293D motor driver pins
const int in3 = 2;     
const int in4 = 3;

// defining buzzer
const int buzzer = 4;

// defining leds
int greenled = 5;   //for showing air filling
int blueled =6;     // for showing snoring detetection
int redled =7;     // for showing power on or off




void setup()

{ 
  pinMode(micpin,INPUT);     // gives input signals to the arduino board micvalue1 and micvalaue2
 
  pinMode(buzzer, OUTPUT);   // for buzzer
  pinMode(in3, OUTPUT);      // for L293D motor driver which is connected to Air Pump
  pinMode(in4, OUTPUT);      // for L293D motor driver which is connected to Air Pump
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
   pinMode(redled, OUTPUT);

// all system check
digitalWrite(redled, HIGH);
digitalWrite(blueled, HIGH); 
digitalWrite(greenled, HIGH);
tone(buzzer, 1000); 
delay(100);
noTone(buzzer);     
delay(1000);
digitalWrite(blueled, LOW); 
digitalWrite(greenled, LOW);
digitalWrite(redled, LOW);
delay(3000);

}
 
 

void loop()

{       
      digitalWrite(redled, HIGH); 
        Listen();                                                        // microphone starts to liten to snoring
        
      if (mic1<300&&mic2<300&&mic3<300&&mic4<300)
       {   FillAir();                                                   // air starts to fill inside air bag of pillow        
          delay(1000);//delay(35000);  // fill air for 35 seconds
          StopAir();
          delay(3000);
         
       }
}
         // Listen();
          //Listen();
         // Listen();
       
       // if(m2-m1>80||m1-m2>80)  //||micvalue1-micvalue2>950)              // if snoring is too loud to prevent then wake the person
         // {                                                             //Serial.println("snoring too loud !!!!!!!!!! raising alarm ");
          //  PlayAlarm();                // all sequence for alarm only
          //   StopAlarm();
           // PlayAlarm();
           //  StopAlarm();
             //PlayAlarm();
            // StopAlarm();            
             //PlayAlarm();
            // StopAlarm();
            // PlayAlarm();
            // StopAlarm();
             //PlayAlarm();
             //StopAlarm();
             //PlayAlarm();
             //StopAlarm();
             //PlayAlarm();
            // StopAlarm();
            // PlayAlarm();
            // StopAlarm();
            // delay(2000);
            // Listen();            
          
         // }
        
  //loop function closed

    
    // all functions defined here
    
    void Listen()
    {  
      digitalWrite(blueled, HIGH); 
      mic1 = analogRead(micpin);
       delay(1); 
      mic2 = analogRead(micpin);
       delay(1);                                         
       mic3 = analogRead(micpin);
       delay(1);                                         
       mic4 = analogRead(micpin);
//       delay(1);                                         
//       mic5 = analogRead(micpin);
//       delay(1);                                         
//       mic6 = analogRead(micpin);
//      delay(1);                                         
//       mic7 = analogRead(micpin);
//      delay(1);                                         
//       mic8 = analogRead(micpin);
//      delay(1);                                         
//       mic9 = analogRead(micpin);
//      delay(1);                                         
//       mic10 = analogRead(micpin);
//      delay(1);                                         
//       mic11 = analogRead(micpin);
//   delay(1);                                         
//       mic12 = analogRead(micpin);
//   delay(1);                                         
//       mic13 = analogRead(micpin);
//   delay(1);                                         
//       mic14 = analogRead(micpin);
//   delay(1);                                         
//       mic15 = analogRead(micpin);
//   
   
    }                                          
       
     
                                                         
    
     
    void PlayAlarm()
     {  digitalWrite(blueled, HIGH); 
        digitalWrite(greenled, HIGH);
        tone(buzzer, 1000); 
        delay(500);        // ...for 1 sec
     }
     
     void StopAlarm()     
     {  
         digitalWrite(blueled, LOW); 
        digitalWrite(greenled, LOW);      
         noTone(buzzer);     // Stop sound...
        delay(500);        // ...for 1sec
     }
 
   void FillAir()
    { digitalWrite(blueled, LOW); 
      digitalWrite(greenled, HIGH);
      digitalWrite(in3, HIGH);          
      digitalWrite(in4, LOW);
    }

   void StopAir()
   {  digitalWrite(greenled, LOW);
      digitalWrite(in3, LOW);           
      digitalWrite(in4, LOW);
   }

