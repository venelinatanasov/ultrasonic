#define irsig A1


void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(irsig);
  Serial.println(a);
}
