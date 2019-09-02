#include <VirtualWire.h>
const int datain = 12;
int ledPin = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  vw_set_ptt_inverted(true);
    vw_set_rx_pin(datain);
    vw_setup(2000);
    vw_rx_start();
}

char x;
void loop(){
 
  uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      digitalWrite(ledPin,HIGH);
      delay(2000);
    }  
    else{
      digitalWrite(ledPin,LOW);
      }
} 

