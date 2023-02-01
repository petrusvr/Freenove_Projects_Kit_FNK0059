int countValue = 0; // Digital tube display value

byte num[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,  //0-7
              0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e };//8-F

void test15_SegmentDisplay(){
  Serial.println("Test 15: 4-Digit 7-segment display");
  Serial.println("  Requires: 15 -> ON");
  ledTestDisplay = "F-15";
  doLedTestDisplay(true);
  LedDisplay(1000);
  // set pins to output
  pinMode(SEGDIP_LATCH_PIN, OUTPUT);
  pinMode(SEGDIP_CLOCK_PIN, OUTPUT);
  pinMode(SEGDIP_DATA_PIN, OUTPUT);

  int speed = 600;
  //test
  ledTestDisplay = "0000";
  LedDisplay(speed);
  ledTestDisplay = "1111";
  LedDisplay(speed);
  ledTestDisplay = "2222";
  LedDisplay(speed);
  ledTestDisplay = "3333";
  LedDisplay(speed);
  ledTestDisplay = "4444";
  LedDisplay(speed);
  ledTestDisplay = "5555";
  LedDisplay(speed);
  ledTestDisplay = "6666";
  LedDisplay(speed);
  ledTestDisplay = "7777";
  LedDisplay(speed);
  ledTestDisplay = "8888";
  LedDisplay(speed);
  ledTestDisplay = "9999";
  LedDisplay(speed);
  ledTestDisplay = "AAAA";
  LedDisplay(speed);
  ledTestDisplay = "BBBB";
  LedDisplay(speed);
  ledTestDisplay = "CCCC";
  LedDisplay(speed);
  ledTestDisplay = "DDDD";
  LedDisplay(speed);
  ledTestDisplay = "EEEE";
  LedDisplay(speed);
  ledTestDisplay = "FFFF";
  LedDisplay(speed);
  ledTestDisplay = "H-h ";
  LedDisplay(speed);
  ledTestDisplay = "PUNO";
  LedDisplay(speed);
  ledTestDisplay = "done";
  LedDisplay(1500);
  
}

void ledDisplay(String fourDigits){
  for(int s=fourDigits.length()-1; s>=0;s--){
    char c = fourDigits[s];
    DigitalTube_MSBFIRST(s,toLedDisplay(c, false));
  }
}

byte toLedDisplay(char c, bool dot){
  byte dota = 0;
  if(dot)
    dota = 128;
  switch((char)c){
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
      int digit = c - '0';
      return num[digit]-dota;
  }
  if(c == 'A' || c == 'a')
    return num[10]-dota;
  if(c == 'B' || c == 'b')
    return num[11]-dota;
  if(c == 'C' || c == 'c')
    return num[12]-dota;
  if(c == 'D' || c == 'd')
    return num[13]-dota;
  if(c == 'E' || c == 'e')
    return num[14]-dota;
  if(c == 'F' || c == 'f')
    return num[15]-dota;
  if(c == ' ')
    return 255-dota;
  if(c == '-')
    return 191-dota;
  if(c == 'H')
    return 137-dota;
  if(c == 'h')
    return 139-dota;
  if(c == 'o' || c == 'O')
    return 163-dota;
  if(c == 'P')
    return 140-dota;
  if(c == 'U')
    return 193-dota;
  if(c == 'N' || c == 'n')
    return 171-dota;
  
  return 172-dota; //?
}

void DigitalTube_MSBFIRST(int number, byte value) {
  digitalWrite(SEGDIP_LATCH_PIN, LOW);
  shiftOut(SEGDIP_DATA_PIN, SEGDIP_CLOCK_PIN, MSBFIRST, 0x01 << number);
  shiftOut(SEGDIP_DATA_PIN, SEGDIP_CLOCK_PIN, MSBFIRST, value);
  digitalWrite(SEGDIP_LATCH_PIN, HIGH);
}
