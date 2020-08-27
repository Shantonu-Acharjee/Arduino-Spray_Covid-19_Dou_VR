int trigPinA =A0;
int echoPinA =A1;

int vr  = A2;
int vrA = A3;
int tr = A4;

long durationA;
int distanceA;

int va;
int val;
int vaA;
int valA;

int LED = 13;
int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPinA,OUTPUT);
  pinMode(echoPinA,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(vr,INPUT);
  pinMode(vrA,INPUT);
 
  
   
}



void loop() {
   digitalWrite(trigPinA,LOW);
   delayMicroseconds(2);

   digitalWrite(trigPinA,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinA,LOW);

   durationA=pulseIn(echoPinA,HIGH);
  
   distanceA = durationA*0.034/2;
   
   //Serial.println(distanceA);

   va = analogRead(vr);
   val = map(va,0,1023,100,30000);
   

   vaA = analogRead(vrA);
   valA = map(vaA,0,1023,10,150);
  



   if(distanceA <= valA && flag == 0){
    flag = 1;
    digitalWrite(LED,HIGH);
    delay(val);
    digitalWrite(LED,LOW);
   }
   else{
    digitalWrite(LED,LOW);
    delay(1000);
   }


   

   if(distanceA > valA){
    flag = 0;
   }

}
