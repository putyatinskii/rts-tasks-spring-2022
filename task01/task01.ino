int ledMas[] = {3, 5, 6, 9, 10};
unsigned long intervalMas[] = {540000, 390000, 39000, 345, 45};

int ledState[] = {LOW, LOW, LOW, LOW, LOW};
unsigned long previousMilliseconds[] = {0, 0, 0, 0, 0};

void setup() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    pinMode(ledMas[ledN], OUTPUT);
  } 
}

void loop() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    unsigned long currentMilliseconds = micros();
    if (currentMilliseconds - previousMilliseconds[ledN] >= intervalMas[ledN]) {
      previousMilliseconds[ledN] = currentMilliseconds;

      if (ledState[ledN] == LOW) {
        ledState[ledN] = HIGH;
      } 
      else {
        ledState[ledN] = LOW;
      }
       digitalWrite(ledMas[ledN], ledState[ledN]);
    }
  }
}
