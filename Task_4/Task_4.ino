#include <LiquidCrystal.h> //includes the liquid crystal library to connect to the lcd screen.
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Initialises the pins for the lcd screen
int buttonApin = 2; //Initialises the pin for switchA, the hex selector
int buttonBpin = 3; //Initialises the pin for switchB, the position selector
int buttonCpin = 4; //Initialises the pin for switchC, the enter button
int buttonDpin = 5; //Initialises the pin for switchD, the "Diagnostics port"
int hex_dis[4] = {0, 0, 0, 0}; //Creates an integer array
bool button_enabled = false; //Creates a boolean as false

void setup() {
  // Setup code to enable the correct pins and print out "Drive Disabled"
  pinMode(buttonApin, INPUT_PULLUP); //Sets pin 2 to a switch input pin
  pinMode(buttonBpin, INPUT_PULLUP); //Sets pin 3 to a switch input pin
  pinMode(buttonCpin, INPUT_PULLUP); //Sets pin 4 to a switch input pin
  pinMode(buttonDpin, INPUT_PULLUP); //Sets pin 5 to a switch input pin 
  lcd.begin(16, 2); //Turns the lcd screen on
  lcd.print("Enter Hex:"); //Print "Enter Hex" onto the lcd screen
}

void loop() {
  int j = 0; //Assign integer j as 0
  //This part of the code conatins the combination input part
  while (button_enabled == false) //While button_enabled is false, loop through the below code
  {
    //Authentication of the sequence as well as the input of it
    while (digitalRead(buttonCpin) == HIGH) //While switchC is unpressed
    {
      if (digitalRead(buttonDpin) == LOW) //if switch d is low
      {
        //if the port is activated when it isnt enabled
        lcd.clear(); //clears the screen
        lcd.setCursor(0, 0); //Sets cursor to 0, 0
        lcd.print("Disabled!"); //print "Disabled!"
        delay(3000); //delays be 3 seconds
        lcd.clear(); //clears the display
        lcd.setCursor(0, 0); //Sets cursor to 0, 0
        lcd.print("Enter Hex:"); //Print "Enter Hex" onto the lcd screen
      }
      if (digitalRead(buttonApin) == LOW) //If switchA is low
      {
        if(hex_dis[j] == 15) //If the value in position j is 15
        {
          hex_dis[j] = 0; //Change position j to 0
        }
        else
        {
          hex_dis[j] = hex_dis[j] + 1; //Add 1 to the position j in the array
        }
      }
      
      char display_char; //create variable 
      int i = 0; //Assign integer i as 0
      for(i=0;i<4;i++) //Loops through the display algorithm 4 times with i going from 0 -> 3
      {
        lcd.setCursor(0, 0); //Sets cursor to 0, 0
        lcd.print("Enter hex:"); //Print "Enter hex" onto the lcd screen
        lcd.setCursor(i, 1); //Sets the cursor to the second line and the x position alligned with the array position
        int display = hex_dis[i]; //sets integer display to the current position in the array

        //converts to actual hex values
        if (display == 10) //if display is 10
        {
          display_char = 'A';//display A
        }
        else if (display == 11)//if display is 11
        {
          display_char = 'B';//display B
        }
        else if (display == 12)//if display is 12
        {
          display_char = 'C';//display C
        }
        else if (display == 13)//if display is 13
        {
          display_char = 'D';//display D
        }
        else if (display == 14)//if display is 14
        {
          display_char = 'E';//display E
        }
        else if (display == 15)//if display is 15
        {
          display_char = 'F';//display F
        }
        else if (display == 0)//if display is 0
        {
          display_char = '0';//display 0
        }
        else if (display == 1)//if display is 1
        {
          display_char = '1';//display 1
        }
        else if (display == 2)//if display is 2
        {
          display_char = '2';//display 2
        }
        else if (display == 3)//if display is 3
        {   
          display_char = '3';//display 3
        }
        else if (display == 4)//if display is 4
        {
          display_char = '4';//display 4
        }
        else if (display == 5)//if display is 5
        {
          display_char = '5';//display 5
        }
        else if (display == 6)//if display is 6
        {
          display_char = '6';//display 6
        }
        else if (display == 7)//if display is 7
        {
          display_char = '7';//display 7
        }
        else if (display == 8)//if display is 8
        {
          display_char = '8';//display 8
        }
        else if (display == 9)//if display is 9
        {
          display_char = '9';//display 9
        }
        lcd.print(display_char); //Displays the number corresponding to the position in the array
        lcd.setCursor(0, 0); //Sets cursor to 0, 0
      }
      if (digitalRead(buttonBpin) == LOW) //If switchB is low
      {
        if (j<3) //if j is less than 3
        {
          j = j + 1; //add one to j
        }
        else
        {
          j = 0; //j is 0
        }
      }
      delay (250); //Delays of 250 milliseconds
    }
    if (hex_dis[0] == 15 && hex_dis[1] == 3 && hex_dis[2] == 4 && hex_dis[3] == 12) //If the code is equal to F34C
    {
      button_enabled = true; //puts button_enabled as true
      lcd.clear(); //clears the lcd screen
    }
    else
    {
      //if its wrong display error message
      lcd.clear(); //clears the lcd screen
      lcd.setCursor(0, 0); //Sets cursor to 0, 0
      lcd.print("Wrong!");//print "Wrong!"
      delay(5000); //delay by 5 seconds
    }
  }

  lcd.clear();//clears the screen
  lcd.setCursor(0, 0); //Sets cursor to 0, 0
  lcd.print("I/O Access Granted");//print "I/O Access Granted"
}

