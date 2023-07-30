// defining Sound sensor
int micpin = A0;   // arduino analog pin A0 connected to sound sensor A0 pin 
int m[50];
int i;


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

{ Serial.begin(9600);  
  pinMode(micpin,INPUT);     // gives input signals to the arduino board micvalue1 and micvalaue2
 // Serial.begin(9600);        // for displaying into serial monitor
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
delay(1000);

}
 
 

void loop()

{       
      digitalWrite(redled, HIGH); 
//        Listen();                                                        // microphone starts to liten to snoring

     
      for ( int i=0;i<50;i++)
      {   m[i]= analogRead(micpin);
      
        Serial.println(m[i]);  
        delay(1);             
          
      
      if (m[i]<300&&m[i+1]<300)          // micvalue1-micvalue2>100&&||micvalue1-micvalue2>100  // when snoring starts then get inside loop
       {                                                               //Serial.println("snoring starts------- filling air into pillow ");
          FillAir();                                                   // air starts to fill inside air bag of pillow        
          delay(2000);//delay(35000);  // fill air for 35 seconds
          StopAir();
          delay(2000);
          
       

//          Listenalarm();
//          delay(4000);
//          
       
//            if(m1<300||m2<300||m3<300||m4<300||m5<300||m6<300||m7<300)  //||micvalue1-micvalue2>950)         ||micvalue1-micvalue2>100     // if snoring is too loud to prevent then wake the person
//           {                                                             //Serial.println("snoring too loud !!!!!!!!!! raising alarm ");
//             PlayAlarm();                // all sequence for alarm only
//             StopAlarm();
//             PlayAlarm();
//             StopAlarm();
//             PlayAlarm();
//             StopAlarm();            
//             PlayAlarm();
//             StopAlarm();
//             PlayAlarm();
//             StopAlarm();
//             PlayAlarm();
//             StopAlarm();
//             PlayAlarm();
//             StopAlarm();
//             PlayAlarm();
//             StopAlarm();
//             PlayAlarm();
//             StopAlarm();
//             delay(2000);
             
//             Listen();            
//          
//             }
       }
      }
 }  //loop function closed

    
    // all functions defined here
    
//    void Listen()
//    {  //digitalWrite(blueled, HIGH);
//       //m1 = analogRead(micpin);            //Serial.println(micvalue1);   
//       //delay(70);
//      
//       
//     }

//      void Listenalarm()
//    {  digitalWrite(blueled, HIGH);
//       m1 = analogRead(micpin);            //Serial.println(micvalue1);   
//       delay(70);
//       m2 = analogRead(micpin);
//       delay(70);
//       m3 = analogRead(micpin);
//       delay(70);
//       m4 = analogRead(micpin);
//       delay(70);
//       m5 = analogRead(micpin);
//       delay(70);
//       m6 = analogRead(micpin);
//       delay(500);
//       m7 = analogRead(micpin);
//       
//       
//     }
     
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
