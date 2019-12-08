#define latchPin  9
#define clockPin  10
#define dataPin  8

byte leds[2];    


void setup() 
{
  

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds[0] = 0; 
  leds[1]=0;

  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)

  {
    bitSet(leds[0], i);
    bitSet(leds[1], i);   

    updateShiftRegister();
    delay(500);
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds[0]);
   shiftOut(dataPin, clockPin, LSBFIRST, leds[1]);
   digitalWrite(latchPin, HIGH);
}
