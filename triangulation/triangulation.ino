#include <math.h>
#define echo1 13 //orange
#define echo2 12 //black
#define trig 7 //blue
#define step 50
#define dist3 4.7
#define latchPin  9
#define clockPin  10
#define dataPin  8

char c;
int time_1;
int time_2;

void setup()
{
    pinMode(trig, OUTPUT);
    digitalWrite(trig, LOW);
    pinMode(echo1,INPUT);
    pinMode(echo2,INPUT);
    Serial.begin(9600);
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
   
        
}

void loop()

{
  
    
    float sum1=0;
    float sum2=0;
    for(int i=0;i<step;i++)
    {
        delay(1);
        float dist1 = measure_distance(echo1);
        if(!dist1){i--;continue;}

        delay(1);
        float dist2 = measure_distance(echo2);
        if(!dist2){i--;continue;}
        if((dist1/dist2>2)||(dist2/dist1>2)){i--;continue;}
        sum1+=dist1;
        sum2+=dist2;

    }
    float dist1=sum1/step;
    float dist2=sum2/step;
    float Angle=angle(dist2,dist1);
    if(isnan(Angle)){return;}
    
    //Serial.println(Angle);
    display(Angle);

}

float measure_distance(int sensorpin)
{
    trigger();
    float time = pulseIn(sensorpin, HIGH, 8000);
    time=time/1000;
    return 34*time;



}

void trigger()
{
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
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


void display(float angle)
{
  int leds=0;
  bitSet(leds,angletodiode(angle)); 

  updateShiftRegister(leds);
}

void updateShiftRegister(int leds)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   shiftOut(dataPin, clockPin, LSBFIRST, (leds>>8));
   digitalWrite(latchPin, HIGH);
}

int angletodiode(float angle)
{
  if(angle>173){return 15;}
  int step1=180/16;
  int diode=angle/step1;
    return diode;
  
}
