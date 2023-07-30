
#include <Servo.h>              
Servo myservo;               
 int pos = 0;                  


#define S0 4                 
#define S1 5                 
#define S2 7                
define S3 6                 
#define sensorOut 8
 int frequency1 = 0;            
 int frequency2 = 0;             
 int frequency3 = 0;             


const int in1 = 2;
const int in2 = 3;


const int in3 = 10;
const int in4 = 11;


const int trigPin = 12;
const int echoPin = 13;

long duration;
int distance;


void setup()

{ 
  
  
  myservo.attach(9);       
  
    pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);           
  digitalWrite(S1,LOW);
                                                                                             
  
 
  pinMode(in1, OUTPUT);           
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);           
  pinMode(in4, OUTPUT);
  
 
  pinMode(trigPin, OUTPUT);      
  pinMode(echoPin, INPUT);          
                                                                                              
  

}
 
 

void loop()

{    
     detectdistance();  
     left();                            
  
 

if ( distance<=40 )              
{      
    forward();                              
    detectdistance();  
      if (distance > 3 && distance <= 13)       
    { 
        halt();            
        delay(1000);
        
         detectcolor();                      
         delay(5000);                       
  
     if (frequency1>30 && frequency1<270)            
    { 
    
    myservo.write(-80);                          
    delay(2000);
    forward();
    delay(190);
    halt();
    delay(2000);                        
    myservo.write(80);                  
    delay(2000);                       
    
  
     backward();
     delay(2000);                      
    left();                            
    delay(2000);                      
   
     halt();                          
    delay(1000);

    
     forward();                          
     delay(400);
     halt();
     delay(1000);
    myservo.write(-80);                       
    delay(2000);                    
    backward();                               
    delay(700);
    halt();                                
    delay(1000);
    myservo.write(80);                 
    delay(2000);                          
    
    right();                          
    delay(4000);                    
    halt();                                   
    delay(5000);                        
    
 
 }    
 

      else                      
      {
         backward();   
         delay(2000);
         
         right();        
         delay(2000);
        
        
         halt();
        delay(5000);
   
       }   
 
    }  
 }      

}      



  
  void detectcolor()
{ 
   
   
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    frequency1= pulseIn(sensorOut, LOW);              
  
   
     digitalWrite(S2,HIGH);
     digitalWrite(S3,HIGH);
     frequency2 = pulseIn(sensorOut, LOW);            
  
   
   digitalWrite(S2,LOW);
   digitalWrite(S3,HIGH);
   frequency3 = pulseIn(sensorOut, LOW);          
  
}


void detectdistance()
{
   
   digitalWrite(trigPin, LOW);         
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);        
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH); 
   distance= duration*0.034/2;         
                                                                 
}

 void forward()
   {
       digitalWrite(in1, HIGH);              
       digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);            
      digitalWrite(in4, HIGH);
  }

void halt()
{
   digitalWrite(in1, LOW);              
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);            
  digitalWrite(in4, LOW);
}

void backward()
{
  digitalWrite(in1, LOW);               
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);               
  digitalWrite(in4, LOW);
}

void left()
{  digitalWrite(in1, LOW);              
   digitalWrite(in2, HIGH);
  
}
void right()
{  digitalWrite(in1, LOW);             
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);             
   digitalWrite(in4, HIGH);
   
}
  
