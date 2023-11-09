#include <LiquidCrystal.h>

#define D7 7
#define D6 8
#define D5 9
#define D4 10
#define E 11
#define RS 12
#define IN_A_POTENT 14

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {
  lcd.begin(16,2);
  pinMode(IN_A_POTENT, INPUT);
}

void loop() {
  float potent = analogRead(IN_A_POTENT) / 1024.f ;

  lcd.clear();
  lcd.print("Potentiometer:");

  lcd.setCursor(0, 1);
  lcd.print(potent);
  
  delay(50);
}
