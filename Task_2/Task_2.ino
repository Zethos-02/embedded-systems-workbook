#include <LiquidCrystal.h> //includes the liquid crystal library to connect to the lcd screen.
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Initialises the pins for the lcd screen
int buttonApin = 2; //Initialises the pin for switchA
int buttonBpin = 3; //Initialises the pin for switchB
int buttonCpin = 4; //Initialises the pin for switchC
int buttonDpin = 5; //Initialises the pin for switchD
int buttonEpin = 6; //Initialises the pin for switchE
int binary_dis[4]; //Creates an integer array
bool button_enabled = false; //Creates a boolean as false
void setup() {
  // Setup code to enable the correct pins and print out "Drive Disabled"
  pinMode(buttonApin, INPUT_PULLUP); //Sets pin 2 to a switch input pin
  pinMode(buttonBpin, INPUT_PULLUP); //Sets pin 3 to a switch input pin
  pinMode(buttonCpin, INPUT_PULLUP); //Sets pin 4 to a switch input pin  
  pinMode(buttonDpin, INPUT_PULLUP); //Sets pin 5 to a switch input pin
  pinMode(buttonEpin, INPUT_PULLUP); //Sets pin 6 to a switch input pin
  lcd.begin(16, 2); //Turns the lcd screen on
  lcd.print("Enter The Correct Combination"); //Print "Drive Disabled" onto the lcd screen
}

void loop() {
  //This part of the code conatins the combination input part
  while (button_enabled == false) //While button_enabled is false, loop through the below code
  {
    int i = 0; //Assign integer i as 0
    if (digitalRead(buttonBpin) == LOW) //If switchB is low
    {
      if(binary_dis[0] == 0) //If the value in position 0 (1 along) is 0
      {
        binary_dis[0] = 1; //Change position 0 (1 along) to 1
      }
      else if(binary_dis[0] == 1) //If the value in position 0 (1 along) is 1
      {
        binary_dis[0] = 0; //Change position 0 (1 along) to 0
      }
    }
    if (digitalRead(buttonCpin) == LOW) //If switchC is low
    {
      if(binary_dis[1] == 0) //If the value in position 1 (2 along) is 0
      {
        binary_dis[1] = 1; //Change position 1 (2 along) to 1
      }
      else if(binary_dis[1] == 1) //If the value in position 1 (2 along) is 1
      {
        binary_dis[1] = 0; //Change position 1 (2 along) to 0
      }
    }
    if (digitalRead(buttonDpin) == LOW) //If switchD is low
    {
      if(binary_dis[2] == 0) //If the value in position 2 (3 along) is 0
      {
        binary_dis[2] = 1; //Change position 2 (3 along) to 1
      }
      else if(binary_dis[2] == 1) //If the value in position 2 (3 along) is 1
      {
        binary_dis[2] = 0; //Change position 2 (3 along) to 0
      }
    }
    if (digitalRead(buttonEpin) == LOW) //If switchE is low
    {
      if(binary_dis[3] == 0) //If the value in position 3 (4 along) is 0
      {
        binary_dis[3] = 1; //Change position 3 (4 along) to 1
      }
      else if(binary_dis[3] == 1) //If the value in position 3 (4 along) is 1
      {
        binary_dis[3] = 0; //Change position 3 (4 along) to 0
      }
    }
    for(i=0;i<4;i++) //Loops through the display algorithm 4 times with i going from 0 -> 3
    {
      lcd.setCursor(i, 1); //Sets the cursor to the second line and the x position alligned with the array position
      lcd.print(binary_dis[i]); //Displays the number corresponding to the position in the array
    }
    if (binary_dis[0] == 1 && binary_dis[1] == 0 && binary_dis[2] == 1 && binary_dis[3] == 0) //If the code is equal to 1010
    {
      button_enabled = true; //puts button_enabled as true
      lcd.clear(); //clears the lcd screen
    }
    delay (250); //Delays of 250 milliseconds
  }

  //This part of the code displays the correct message based on the switch's position
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

