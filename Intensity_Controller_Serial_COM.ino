#include "bsec.h"

#define LED_GREEN 35
#define LED_BLUE 36

int IncomingData_Int = 0, LED_Intensity = 0;

int interpolate_value(int value){
  return int(float(value/100.0)*255.0);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial){
    digitalWrite(LED_GREEN, HIGH);
  }
  
  while(Serial.available()){
    IncomingData_Int = Serial.parseInt();
    LED_Intensity = interpolate_value(IncomingData_Int);
    Serial.write(LED_Intensity);
    analogWrite(LED_BLUE, LED_Intensity);
  }
}
