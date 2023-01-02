
#include <Arduino.h>

//#define SEND_PWM_BY_TIMER         // Disable carrier PWM generation in software and use (restricted) hardware PWM.
//#define USE_NO_SEND_PWM           // Use no carrier PWM, just simulate an active low receiver signal. Overrides SEND_PWM_BY_TIMER definition

#include "PinDefinitionsAndMore.h" // Define macros for input and output pin etc.
#include <IRremote.hpp>

void setup() {
    pinMode(6,INPUT_PULLUP); 
    pinMode(7,INPUT_PULLUP); 
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    IrSender.begin(); // Start with IR_SEND_PIN as send pin and if NO_LED_FEEDBACK_CODE is NOT defined, enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}


uint16_t sAddress = 0xEF00;
uint8_t sCommand = 0x3;
uint8_t sRepeats = 0;

uint16_t ssAddress = 0xEF00;
uint8_t ssCommand = 0x2;
uint8_t ssRepeats = 0;

void loop() {
 
  
   /* // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    if (digitalRead(5) == HIGH){
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    delay(1000);
    }

    if (digitalRead(5) == HIGH){
    IrSender.sendNEC(ssAddress, ssCommand, ssRepeats);
    delay(1000);
    }
    //Serial.println(F("Send NECRaw 0xCB340102"));
    //IrSender.sendNECRaw(0xE01F4040, sRepeats);
*/

     // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal

      if (digitalRead(6) == LOW){
      IrSender.sendNEC(ssAddress, ssCommand, ssRepeats);  // change these unique code to yours but in decimal 
      delay(30);
      } 

  else if (digitalRead(7) == LOW){
      IrSender.sendNEC(sAddress, sCommand, sRepeats);
      delay(30);
      } 
 
  else{
      Serial.println("Nothing to send");
      delay(30);
      } 

   delay(100);
  
  }
