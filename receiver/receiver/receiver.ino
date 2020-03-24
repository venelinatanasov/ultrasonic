#define irsig 10
#define trig 8
#define echo 9
#define led 11
#define IRtolerance 0.2
int all;

void setup() {
  pinMode(irsig, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  all=calibrate();

}

void loop() {
  
  unsigned long t;
  float dist;
  while(digitalRead(irsig)==HIGH){}
  unsigned long x=millis();
  while(digitalRead(irsig)==LOW){
    if(millis()-x>1000){all=calibrate();return;}
  }
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t=pulseIn(echo, HIGH, 80000);
  if(!t){return;}
  dist=(340*t);
  dist/=10000;
  
  Serial.println(dist);
  

}
int calibrate(){
  int a;
  unsigned long all=0;
 for(int i=0;i<100;i++){
   a=analogRead(A0);
   all+=a;
 }
 all=all/100;
 return all;
 
  
}
