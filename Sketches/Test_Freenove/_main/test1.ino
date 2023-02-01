void test1_Buttons(){
  ledTestDisplay = "F- 1";
  doLedTestDisplay(true);
  Serial.println("Test 1: Buttons");
  Serial.println("  Requires: D2 -> ON  D3 -> ON  D4 -> ON  D5 -> ON");
  LedDisplay(1000);
  ledTestDisplay = "    ";
  doLedTestDisplay();

  int counter = 0;
  bool doTest = true;
  bool toRight = true;

  pinMode(BTN_BLUE, INPUT_PULLUP); 
  pinMode(BTN_RED, INPUT_PULLUP); 
  pinMode(BTN_YELLOW, INPUT_PULLUP); 
  pinMode(BTN_GREEN, INPUT_PULLUP); 

  while(doTest){
    if(digitalRead(BTN_GREEN) == LOW)
      doTest = false;

    if(digitalRead(BTN_BLUE) == LOW){
      counter++;
      while(digitalRead(BTN_BLUE) == LOW)
        showCounter(counter, toRight);
    }

    if(digitalRead(BTN_YELLOW) == LOW){
      counter--;
      while(digitalRead(BTN_YELLOW) == LOW)
        showCounter(counter, toRight);
    }

    if(digitalRead(BTN_RED) == LOW){
      toRight = !toRight;
      while(digitalRead(BTN_RED) == LOW)
        showCounter(counter, toRight);
    }
    
    showCounter(counter, toRight);
  }
  
  ledTestDisplay = "done";
  LedDisplay(1500);
}

void showCounter(int cnt, bool toRight){
  char buff[5];
  if(toRight)
    sprintf(buff, "%4d", cnt);
  else sprintf(buff, "%d", cnt);
  String num = buff;
  ledDisplay(num);
}
