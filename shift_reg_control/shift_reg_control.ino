#define latchPin 9
#define clockPin 10
#define dataPin 11
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin,LOW);

}

void loop() {
  for(int num=0;num<65536;num++)
  {
     digitalWrite(latchPin, LOW);
     
     shiftOut(dataPin, clockPin, MSBFIRST, (num>>8));
     
     shiftOut(dataPin, clockPin, MSBFIRST, num);
     num++;
     digitalWrite(latchPin, HIGH);
     delay(500);
  }

}
