int leds[] = {13, 12, 14, 27, 33, 32};

void setup() {

  for(int i=0;i<6;i++)
  {
    pinMode(leds[i],OUTPUT);
  }
}

void loop() {

  for(int i=0;i<6;i++)
  {
    digitalWrite(leds[i],HIGH);
    delay(500);
    digitalWrite(leds[i],LOW);
  }
}

//Testing code for led