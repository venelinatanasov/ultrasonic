#define X0 10
#define X1 11
#define X2 12
#define Y0 5
#define Y1 6
#define Y2 7
#define LEDX 6
#define LEDY 3

void setup() {
  pinMode(Y0,INPUT);
  pinMode(Y1,INPUT);
  pinMode(Y2,INPUT);
  pinMode(X0,INPUT);
  pinMode(X1,INPUT);
  pinMode(X2,INPUT);

}
char matrix[1][LEDY][LEDX]={
  {
  {1,1,1,0,1,0},
  {1,0,1,0,1,1},
  {1,0,1,1,1,0}
  }
};

void loop() {
 char z=0;
for(char x=0;x<LEDX;x=x+2)
{
  for(char y=0;y<LEDY;y++)
  {
    flash(z,y,x);
  }
}
}

void flash(char Z, char Y,char X)
{
 
  char pinx=X2;
  char piny=Y+5;
  if(X==0){pinx=X0;}
  if(X==2){pinx=X1;}
  if(matrix[Z][Y][X])
  {
    pinMode(pinx,OUTPUT);
    pinMode(piny,OUTPUT);
    digitalWrite(pinx,LOW);
    digitalWrite(piny,HIGH);
    delay(1);
    digitalWrite(piny,LOW);
    pinMode(pinx,INPUT);
    pinMode(piny,INPUT);    
  }
  else
  {
    delay(1);
    
  }
  if(matrix[Z][Y][X+1])
  {
    pinMode(pinx,OUTPUT);
    pinMode(piny,OUTPUT);
    digitalWrite(piny,LOW);
    digitalWrite(pinx,HIGH);
    delay(1);
    digitalWrite(pinx,LOW);
    pinMode(pinx,INPUT);
    pinMode(piny,INPUT);
    
  }
  else
  {
    delay(1);
  }
}
