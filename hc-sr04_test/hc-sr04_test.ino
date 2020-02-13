#define trig 9
#define echo 8
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(200);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  float t= pulseIn(echo, HIGH);
  float dist=340*(t/10000)/2;
  Serial.println(dist);

}
