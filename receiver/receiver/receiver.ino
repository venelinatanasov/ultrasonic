#define irsig 10
#define trig 8
#define echo 9


void setup() {
  pinMode(irsig, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

}

void loop() {
  
  unsigned long t;
  float dist;
  while(digitalRead(irsig)==HIGH){}
  while(digitalRead(irsig)==LOW){}
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t=pulseIn(echo, HIGH, 8000);
  //t=t/1000000;
  //dist=(340*t);
  Serial.println(t);
  

}
