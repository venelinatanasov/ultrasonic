#define irsig A0
#define irtolerance 0.2
#define led 11
unsigned long all;
void setup() {
  
  Serial.begin(9600);
  all=calibrate();
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long a=millis();
  int ref=(irtolerance*all);
  Serial.println(all);
  Serial.println(ref);
  while(analogRead(irsig)<(all+ref))
  {
     if(millis()-a>1000){
      all=calibrate();
      return;
     }
  }
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
}
int calibrate(){
  int a;
  unsigned long all1;
 for(int i=0;i<100;i++){
   a=analogRead(irsig);
   all1+=a;
 }
 all1=all1/100;
  return all1;
  
}
