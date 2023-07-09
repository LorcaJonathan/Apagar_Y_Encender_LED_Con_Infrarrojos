#include <IRremote.h>     
#define Tecla_1 0xF30CFF00    
#define Tecla_2 0xE718FF00  

int IR = 11;   
int LED = 13;     

void setup() {
  Serial.begin(9600);     
  IrReceiver.begin(IR, DISABLE_LED_FEEDBACK); 
  pinMode(LED, OUTPUT); 
} 

void loop() {
  if (IrReceiver.decode()) {        
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); 
    if (IrReceiver.decodedIRData.decodedRawData == Tecla_1)   
    digitalWrite(LED, HIGH); 
    if (IrReceiver.decodedIRData.decodedRawData == Tecla_2)   
    digitalWrite(LED, LOW); 
    
    IrReceiver.resume();       
  }
  delay (100);            
}