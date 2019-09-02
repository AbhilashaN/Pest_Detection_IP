void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  DDRB=0xFF;
  Serial.write('1'); 
}

char x;
void loop(){ 
   initialise1(); 
   OCR1A=10;
   
    
  if(Serial.available() > 0){      // if data present, blink
    x=Serial.read();
    if(x=='1')
    PORTB=0b00001110;
    else if(x=='2')
    PORTB=0b00100110;
    else if(x=='3')
    PORTB=0b00001110;
    else if(x=='4')
    PORTB=0b00000000;
    else if(x=='5')
    PORTB=0b00101110;   
   Serial.write('0');
  }
} 

