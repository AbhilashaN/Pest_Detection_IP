
#include <SoftwareSerial.h>

#include<avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void usart_int(void) {
  UCSR0A=0x00;
  UCSR0B=(1<< RXEN0)|(1<< TXEN0);//TRANSMIT AND RECEIVE ENABLE
  UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);//ASYNCHRONOUS, 8 BIT TRANSFER
  UBRR0L= 103 ; //BAUD RATE 9600 
}

void usart_send(char ch )
{
  while(UCSR0A!=(UCSR0A|(1<<UDRE0)));//waiting for UDRE to become high
  UDR0= ch;
}

int main(void)
{
  DDRB=0xFF;
  DDRD=0b01001111;
  float  Time;
  int D;
  usart_int();
  unsigned char ch;
  while(1)
  {
    
    while(UCSR0A!= (UCSR0A|(1<<RXC0)));
    
    ch=UDR0;
    usart_send(ch);
    if(ch=='1')
    {
      //usart_send(('1'));
      PORTB=0b00101010;
      _delay_ms(2000);
    }
    if(ch=='0')
    {
      //usart_send(('2'));
      PORTB=0b00000101;
      _delay_ms(6000);
    }
    else if(ch=='0')
    {
      //usart_send(('0'));
      PORTB=0b00000000;
    }
    else if(ch=='4')
    {
      //usart_send(('0'))RIGHT
      PORTB=0b00001010;
      _delay_ms(2000);
      PORTB=0b00000110;
      _delay_ms(750);
      PORTB=0b00001010;
      _delay_ms(4000);
      
    }
    else if(ch=='3')
    {
      //usart_send(('0'));
      PORTB=0b00001010;
      _delay_ms(2000);
      PORTB=0b00001001;
      _delay_ms(750);
      PORTB=0b00001010;
      _delay_ms(4000);
    }
    else if(ch=='5')
   {
       while(1)
        {
          float  Time;
          int D;
          PORTD=0b00000000;
          _delay_ms(10);
          PORTD=0b01000000;
          _delay_ms(10);
          PORTD=0b00000000;
          Time=pulseIn(5,HIGH);
          D=(Time*330)/20000;
          if(D<=10)
          {
            PORTB=0b00000101;
          }
          else if(D>=10&&D<=30)
          {
            PORTB=0b00001010;
          }
          else
          {
            PORTB=0b00000000;
          }
        }
      }
    }
      
  }
  
  

