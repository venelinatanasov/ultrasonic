#define analog A0
#define led 11
#define IRtolerance 0.2
int all;
void setup(){
   pinMode(analog, INPUT);
   pinMode(led,OUTPUT);
    Serial.begin(9600);
   all=calibrate();
}

void loop(){
  
  Serial.println(all);
  int irsig=analogRead(analog);
  if(irsig>(all+IRtolerance*all)){
   digitalWrite(led,HIGH); 
  }else{
    digitalWrite(led,LOW);
  }
  
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
