
#define dist3 4.7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(angle(3,4));
}
float angle(float dist2, float dist1)
{
    float a=dist2;
    float b=dist1;
    float c=dist3;
  

  

    float M=sqrt(0.25*(2*a*a+2*b*b-c*c));

    float X = acos(((c/2)*(c/2)+M*M-b*b)/(2*(c/2)*M));
    X=X*57.295779;
    return X;



}
