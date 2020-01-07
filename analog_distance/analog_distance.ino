#define analogPin A0
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
//int values[900];
void setup() {
  // put your setup code here, to run once:
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  cbi(ADCSRA, ADPS0);
  Serial.begin(230400);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  unsigned long avr=0;
  unsigned long avr2=0;
  
  
  for(int z=0;z<10;z++){
    
    for(int i=0;i<500;i++)
    {
      //a=analogRead(analogPin);
      //if(a>maxa){maxa=a;}
      avr+=analogRead(analogPin);
    }
    avr/=500;
    avr2+=avr;
  }
  avr2/=10;
  Serial.println(avr2);
  
  
}
