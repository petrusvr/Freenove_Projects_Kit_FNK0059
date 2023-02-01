void test3_BuzzerActive(){
  ledTestDisplay = "F- 3";
  doLedTestDisplay(true);
  Serial.println("Test 3: Buzzer Active");
  Serial.println("  Requires: D7 -> ON");
  LedDisplay(200);
//  ledTestDisplay = "    ";
//  doLedTestDisplay();
  pinMode(BUZZ_ACTIVE, OUTPUT);
  digitalWrite(BUZZ_ACTIVE, HIGH);
  LedDisplay(400);
  digitalWrite(BUZZ_ACTIVE, LOW);
  LedDisplay(400);
  digitalWrite(BUZZ_ACTIVE, HIGH);
  LedDisplay(400);
  digitalWrite(BUZZ_ACTIVE, LOW);
  LedDisplay(400);
  digitalWrite(BUZZ_ACTIVE, HIGH);
  LedDisplay(400);
  digitalWrite(BUZZ_ACTIVE, LOW);
  LedDisplay(400);
  digitalWrite(BUZZ_ACTIVE, HIGH);
  LedDisplay(400);
  digitalWrite(BUZZ_ACTIVE, LOW);
}
