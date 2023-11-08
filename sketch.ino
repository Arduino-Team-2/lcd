#include <LiquidCrystal.h>

#define D7 2
#define D6 3
#define D5 4
#define D4 5
#define D3 6
#define D2 7
#define D1 8
#define D0 9
#define E 10
#define RW 11
#define RS 12
#define IN_A_POTENT 14

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);


void setup() {
  lcd.begin(16,1);
  lcd.print("hello, world!");
  pinMode(IN_A_POTENT, INPUT);
}

float lastPotent = 0;

void loop() {
  float potent = analogRead(IN_A_POTENT) / 1024.f;
  if (potent == lastPotent) return;
  lcd.clear();
  lcd.print("Potentiometer:");
  lcd.setCursor(0, 1);
  lcd.print(potent);
  lastPotent = potent;
  delay(50);
}

