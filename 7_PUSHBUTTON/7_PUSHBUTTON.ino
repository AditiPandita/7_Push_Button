#include <TM1637Display.h>

// TM1637 pins
#define CLK 2
#define DIO 3

// Button pins
#define S1 4
#define S2 5
#define S3 6
#define S4 7

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(7);  // Set display brightness (0–7)

  // Set buttons as input with pull-up
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  pinMode(S4, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(S1) == LOW) {
    display.showNumberDec(1);
  } else if (digitalRead(S2) == LOW) {
    display.showNumberDec(2);
  } else if (digitalRead(S3) == LOW) {
    display.showNumberDec(3);
  } else if (digitalRead(S4) == LOW) {
    display.showNumberDec(4);
  } else {
    display.clear();  // No button pressed
  }

  delay(100);  // Debounce delay
}