#include <Servo.h>

Servo servo1; 
Servo servo2;

Servo servo4;


int pos = 0; 
int pos2=0;  

int pos4=0;

void setup() {
  servo1.attach(9);
  servo2.attach(10);

  servo4.attach(12);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  servo2.write(pos2);
 
 
  Serial.begin(9600);
}

void loop() {
  char data=Serial.read();
 
 if(data=='4')
 {
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  delay(10);
 }
 if(data=='0')
 {
    digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  
  
 }
 if(data=='3')
 {
   digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(10);
 }
 if(data=='1')
 {
   
  pos=pos+1;
   
  servo1.write(pos);    
  Serial.println(pos);
 }
 if(data=='2')
 {
 
  pos=pos-1;
  Serial.println(pos);
  servo1.write(pos);
 }
if(data=='5')
{
 pos2=pos2+1;
 servo2.write(pos2);
}

if(data=='6')
{
pos2=pos2-1;
servo2.write(pos2);  
}


  if(data=='9')
  {
      Serial.println("close");
        for (pos4 = 0; pos4 <= 180; pos4 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo4.write(pos4);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
     }
     
                          // waits 15ms for the servo to reach the position
  }
  if(data=='8')
  {
    Serial.println("open");
    for (pos4 = 180; pos4 >= 0; pos4 -= 1) { // goes from 180 degrees to 0 degrees
      servo4.write(pos4);              // tell servo to go to position in variable 'pos'
     delay(15);   
  }
}

 
}
                      
