#include <Servo.h>

Servo Hand ;
Servo Elbow ;
int handPos = 90 ;
int MAX = 160 ;
int MIN = 20 ;
int elbowPos = 90 ;
char value ;

void setup() {
  Serial.begin(9600);
  Hand.attach(9) ;
  Elbow.attach(10) ;
  Hand.write(handPos) ;
  Elbow.write(elbowPos) ;
}

void loop() {
  if (Serial.available() > 0) {
    value = Serial.read();
    if (value == 'o' && handPos < MAX) {
      handPos = handPos + 10 ;
      Hand.write(handPos);
      Serial.print("Hand opened: ");
      Serial.println(handPos) ;
    } 
    else if (value == 'O') {
       Hand.write(MAX) ; 
       Serial.println("Hand opened") ;
    }
    else if ( value == 'c' && handPos > MIN){
      handPos = handPos - 10 ;
      Hand.write(handPos);
      Serial.print("Hand closed: ");
      Serial.println(handPos) ;
    }
    else if (value == 'C'){
      Hand.write(MIN) ;
      Serial.println("Hand closed");
    }
    else if ( value == 'f' && elbowPos < 160) {
      elbowPos = elbowPos + 10 ;
      Elbow.write(elbowPos) ;
      Serial.print("Hand moved foreward: ");
      Serial.println(elbowPos) ;
    }
    else if (value == 'F'){
       Elbow.write(MAX) ;
       Serial.println("Arm fully extened") ; 
    }
    else if (value == 'b' && elbowPos > MIN){
      elbowPos = elbowPos - 10 ;
      Elbow.write(elbowPos) ; 
      Serial.print("Hand moved backward: ");
      Serial.println(elbowPos) ;
    }
    else if (value == 'B'){
       Elbow.write(MIN) ;
       Serial.println("Arm fully contracted") ; 
    }
    else if (value == 'r'){
      Elbow.write(90) ;
      Hand.write(90) ;
      Serial.println("Servos reset");
    }
    else {
      Serial.println("Values out of range");
    }
  }
  delay(500);
}
