const int led=3;

void setup() {

pinMode(led,OUTPUT);

Serial.begin(9600);
}
void loop() {
int potValue = analogRead(A0);
Serial.println(potValue);

delay(1000); 
if(potValue>511)
  {
    digitalWrite(led,HIGH);
  }
else
{
      digitalWrite(led,LOW);

}

}
