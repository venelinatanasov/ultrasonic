#define trig 10
#define echo 12

//unsigned long synchro;
unsigned long t1;
unsigned long t2;
unsigned long T;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  
  pinMode(echo,INPUT);
  t1=synchronize();
  //delayMicroseconds(500);
  //delay(500);
  t2=synchronize();
  T=t2-t1;
}

void loop() {
  Serial.print("First: ");
  Serial.println(t1);
  Serial.print("Second:");
  Serial.println(t2);
  Serial.print("Period: ");
  Serial.println(T);

}

unsigned long synchronize()
{
  while(1){
    unsigned long a;
    pinMode(trig, HIGH);
    delayMicroseconds(10);
    pinMode(trig,LOW);
    //delayMicroseconds(15);
    a=pulseIn(echo,HIGH,11000);
    if(a){return micros()-a;}
    
    
  }
}
