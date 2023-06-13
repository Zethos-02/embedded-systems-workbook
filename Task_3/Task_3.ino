#include <LiquidCrystal.h> //includes the liquid crystal library to connect to the lcd screen.
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Initialises the pins for the lcd screen
int buttonApin = 2; //Initialises the pin for switchA, the driver switch
int buttonBpin = 3; //Initialises the pin for switchB, the bit selector
int buttonCpin = 4; //Initialises the pin for switchC, the position selector
int buttonDpin = 5; //Initialises the pin for switchD, the "Diagnostics port"
int buttonEpin = 6; //Initialises the pin for switchE, the submission switch
int buzzer = 13; //Initialises the pin for the buzzer
int binary_dis[4]; //Creates an integer array
bool button_enabled = false; //Creates a boolean as false
bool reset = false; //Creates a boolean as false
bool looping = true; //Creates a boolean as true
int tries = 3; //Assign integer tries as 3
bool disabled = false; //Creates a boolean as false

void setup() {
  // Setup code to enable the correct pins and print out "Drive Disabled"
  pinMode(buttonApin, INPUT_PULLUP); //Sets pin 2 to a switch input pin
  pinMode(buttonBpin, INPUT_PULLUP); //Sets pin 3 to a switch input pin
  pinMode(buttonCpin, INPUT_PULLUP); //Sets pin 4 to a switch input pin
  pinMode(buttonDpin, INPUT_PULLUP); //Sets pin 5 to a switch input pin 
  pinMode(buttonEpin, INPUT_PULLUP); //Sets pin 6 to a switch input pin
  pinMode(buzzer,OUTPUT); //initialize the buzzer pin as an output
  lcd.begin(16, 2); //Turns the lcd screen on
  lcd.print("Enter numbers:"); //Print "Enter Numbers" onto the lcd screen
}

void loop() {
  //This part of the code conatins the combination input part
  while (reset == false)
  {
    while (button_enabled == false) //While button_enabled is false, loop through the below code
    {
      //Authentication of the sequence as well as the input of it
      int i = 0; //Assign integer i as 0
      int j = 0; //Assign integer j as 0
      while (digitalRead(buttonEpin) == HIGH) //While switchE is unpressed
      {
        if (digitalRead(buttonBpin) == LOW) //If switchB is low
        {
          if(binary_dis[j] == 0) //If the value in position j is 0
          {
            binary_dis[j] = 1; //Change position j to 1
          }
          else if(binary_dis[j] == 1) //If the value in position j is 1
          {
            binary_dis[j] = 0; //Change position j to 0
          }
        }
        for(i=0;i<4;i++) //Loops through the display algorithm 4 times with i going from 0 -> 3
        {
          lcd.setCursor(0, 0); //Sets cursor to 0, 0
          lcd.print("Enter numbers:"); //Print "Enter Numbers" onto the lcd screen
          lcd.setCursor(i, 1); //Sets the cursor to the second line and the x position alligned with the array position
          lcd.print(binary_dis[i]); //Displays the number corresponding to the position in the array
        }
        if (digitalRead(buttonCpin) == LOW) //If switchC is low
        {
          if (j<3) //if j is less than 3
          {
            j = j + 1; //add one to j
          }
        }
        delay (250); //Delays of 250 milliseconds
      }
    
      if (digitalRead(buttonEpin) == LOW) //If switchE is low
      //this occurs when the sequence is submitted
      {
        if (binary_dis[0] == 1 && binary_dis[1] == 0 && binary_dis[2] == 1 && binary_dis[3] == 0) //If the code is equal to 1010
        {
          button_enabled = true; //puts button_enabled as true
          lcd.clear(); //clears the lcd screen
          reset = true; //sets reset to true
        }
        else
        {
          //Sets off the buzzer and chooses the correct error path
          lcd.clear(); //clears the lcd screen
          tries = tries - 1; //takes one away from tries
          lcd.setCursor(0, 0); //Sets cursor to 0, 0
          lcd.print("Error"); //outputs "Error" to the lcd screen
          digitalWrite(buzzer,HIGH); //Sets the buzzer to on
          delay(5000);//wait for 5 seconds
          digitalWrite(buzzer,LOW); //Turns the buzzer off
          delay(1000);//wait for 1 second
          lcd.clear(); //clears the lcd screen
          lcd.setCursor(0, 0); //Sets cursor to 0, 0
          int k = 0; //sets integer k to 0
          if (tries == 2) //if tries is equal to 2
          {
            for (k=0;k<5;k++) //Loop the below code 5 times
            {
              int countdown = 5 - k; //countdown is equal to 5 - k
              lcd.print(countdown); //prints the value of countdown to the lcd screen
              delay(1000);//wait for 1 second
              lcd.setCursor(0, 0); //Sets cursor to 0, 0
            }
          }

          else if (tries == 1) //if tries is equal to 1
          {
            for (k=0;k<10;k++) //Loop the below code 10 times
            { 
              int countdown = 10 - k;//countdown is equal to 10 - k
              lcd.print(countdown); //prints the value of countdown to the lcd screen
              delay(1000);//wait for 1 second
              lcd.setCursor(0, 0); //Sets cursor to 0, 0
              lcd.clear(); //clears the lcd screen
            }
          }

          else
          {
            lcd.print("Locked!"); //prints "Locked!" to the lcd screen
            reset = true; //sets reset to true
            button_enabled = true; //sets button_enabled to true
            disabled = true; //sets disabled to true
            delay(1000); //wait for 1 second
          }
        }
      }
    }
  }

  if (disabled == false) //if disabled is set to false
  {
    while (looping == true) //while looping is set to true
    {
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
  }
  
  else
  {
    //locked out screen, chance to reset.
    lcd.setCursor(0, 1); //Sets cursor to 0, 1
    lcd.print("Please Reset"); //Prints "please reset" to the lcd screen
    while (reset == true) //While reset is set to true
    {
      if (digitalRead(buttonDpin) == LOW) //If switchD is low
      {
        //This should reset the program to the start once again
        reset = false; //Sets the bool to false
        tries = 3; //Assign integer tries as 3
        button_enabled = false; //Sets the bool to false
        disabled = false; //Sets the bool to false
        lcd.clear(); //clears the lcd screen
      }
    }
  }
}

