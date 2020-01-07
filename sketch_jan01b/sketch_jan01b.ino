#define pin 7
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long all = 0;
  for(int i=0;i<1000;i++){
  unsigned long a = pulseIn(pin,HIGH,2000000);
  all+=a;
  }
  all/=100;
  Serial.println(all);
}
