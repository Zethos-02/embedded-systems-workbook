#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int buttonApin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonApin, INPUT_PULLUP);  
  lcd.begin(16, 2);
  lcd.print("Drive Disabled");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonApin) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Drive Enabled");
  }
  if (digitalRead(buttonApin) == HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("Drive Disabled");
  }
}

