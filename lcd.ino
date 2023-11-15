#include <Pin.hpp>
#include <LED.hpp>

#include <LiquidCrystal.h>

#define D7 12
#define D6 11
#define D5 10
#define D4 9
#define E 5
#define RS 3
#define IN_A_POTENT 14
#define OUT_LED_RED 6

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

AnalogPin potentPin(IN_A_POTENT, AnalogPin::Mode::Input);
AnalogLED redLED(OUT_LED_RED);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.setTimeout(50);
}

void loop() {
  float potent = potentPin.read() / 1024.f ;

  Serial.println((int)(potent * 255));
  
  lcd.clear();
  lcd.print("Potentiometer:");

  lcd.setCursor(0, 1);
  lcd.print(potent);

  String input = Serial.readString();
  if (input != "")
    redLED.setBrightness(input.toFloat());

  

}
