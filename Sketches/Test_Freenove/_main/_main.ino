#define LED_6 13
#define BTN_BLUE 2
#define BTN_RED 3
#define BTN_YELLOW 4
#define BTN_GREEN 5
#define BUZZ_PASSIVE 6
#define BUZZ_ACTIVE 7
#define SEGDIP_LATCH_PIN   12 // Pin connected to ST_CP of 74HC595（Pin12）
#define SEGDIP_CLOCK_PIN   13 // Pin connected to SH_CP of 74HC595（Pin11）
#define SEGDIP_DATA_PIN    11 // Pin connected to DS of 74HC595（Pin14）



String ledTestDisplay = "F- 0";

void doLedTestDisplay(bool setup){
  if(setup){
  // set pins to output
    pinMode(SEGDIP_LATCH_PIN, OUTPUT);
    pinMode(SEGDIP_CLOCK_PIN, OUTPUT);
    pinMode(SEGDIP_DATA_PIN, OUTPUT);
  }
  ledDisplay(ledTestDisplay);
}

void doLedTestDisplay(){ doLedTestDisplay(false); }

void LedDisplay(unsigned long time){
  unsigned long ms = millis();
  while(millis() - ms < time){
      doLedTestDisplay();
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  test0_IndicatorsLED();
  test1_Buttons();
  test2_BuzzerPassive();
  test3_BuzzerActive();
  test6_LED();
  test15_SegmentDisplay();

}
