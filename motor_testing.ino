#define MOTOR_PIN 4

void setup()
{
  pinMode(MOTOR_PIN,OUTPUT);
}

void loop()
{
  digitalWrite(MOTOR_PIN,HIGH);
  delay(300);

  digitalWrite(MOTOR_PIN,LOW);
  delay(700);
}
//motor testing code