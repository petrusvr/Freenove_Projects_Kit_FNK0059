void test6_LED(){
  ledTestDisplay = "F- 6";
  doLedTestDisplay(true);
  Serial.println("Test 6: Blue LED");
  Serial.println("  Requires: D13 -> ON");

  LedDisplay(1000);
  ledTestDisplay = "off";
  LedDisplay(1000);
  ledTestDisplay = "    ";
  doLedTestDisplay();
  
  pinMode(LED_6,OUTPUT);
  int pause = 1000;

  for(int i=0; i<3; i++){
    digitalWrite(LED_6, HIGH);
    delay(pause);
    digitalWrite(LED_6, LOW);
    delay(pause);
  }
}
