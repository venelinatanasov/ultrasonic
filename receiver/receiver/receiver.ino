#define irsig 12
#define trig 8
#define echo 9
#define led 11
#define irtolerance 0.1
int all;

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(irsig,INPUT);
  //digitalWrite(trig,LOW);
  pinMode(echo, INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  //all=calibrate();

}

void loop() {
  //delay(100);
  unsigned long t;
  float dist;
  while(digitalRead(irsig)){}
  while(!digitalRead(irsig)){}
 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t=pulseIn(echo, HIGH,10000);
  if(!t){return;}
  dist=(340*t);
  dist/=10000;
  //dist+=10;
  Serial.println("dist");
  Serial.println(dist);
 

}
/*int calibrate(){
  int a;
  unsigned long all1;
 for(int i=0;i<100;i++){
   a=analogRead(irsig);
   delay(1);
   all1+=a;
 }
 all1=all1/100;
  return all1;
  
}*/
