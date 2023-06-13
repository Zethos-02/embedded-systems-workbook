#include <LiquidCrystal.h> //includes the liquid crystal library to connect to the lcd screen.
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Initialises the pins for the lcd screen
int buttonApin = 2; //Initialises the pin for the switch
void setup() {
  // Setup code to enable the correct pins and print out "Drive Disabled"
  pinMode(buttonApin, INPUT_PULLUP); //Sets pin 2 to a switch input pin
  lcd.begin(16, 2); //Turns the lcd screen on
  lcd.print("Drive Disabled"); //Print "Drive Disabled" onto the lcd screen
}

void loop() {
  // Main code that detects the state of the switch, and changes the displayed message accordingly
  if (digitalRead(buttonApin) == LOW) //If the switch is low
  {
    lcd.setCursor(0, 0); //Set the cursor to position 0,0 on the lcd screen
    lcd.print("Drive Enabled"); //Print "Drive Enabled" onto the lcd screen
  }
  if (digitalRead(buttonApin) == HIGH) //If the switch is high
  {
    lcd.setCursor(0, 0); //Set the cursor to position 0,0 on the lcd screen
    lcd.print("Drive Disabled"); //Print "Drive Disabled" onto the lcd screen
  }
}

