
int buzzer = 9; //BUZZER
int ledPin = 11   ; //LED          
int inputPin = 10; //PIR               
int pirState = LOW;            
int val = 0;                    


// change setup.h to switch between buffered and pixel-by-pixel processing
#include "setup.h"


void setup() {
  // This is not necessary and has no effect for ATMEGA based Arduinos.
  // WAVGAT Nano has slower clock rate by default. We want to reset it to maximum speed
  CLKPR = 0x80; // enter clock rate change mode
  CLKPR = 0; // set prescaler to 0. WAVGAT MCU has it 3 by default.
   Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(buzzer, OUTPUT);  

  initializeScreenAndCamera();
}
 void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on

digitalWrite(buzzer,HIGH);
     delay(100);
      
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of

      digitalWrite(buzzer,LOW); 
      delay(100);
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  processFrame();
}
