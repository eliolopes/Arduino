// http://www.instructables.com/id/Arduino-LEDs-fan-POV-APPLAUSE-sign/?ALLSTEPS
// defining the alphabet
 #include "font.h"
 
 // define the Arduino LED pins in use
 const int LEDpins[] = {
   1,2,3,4,5,6,7};
 
 // number of LEDs
  const int charHeight = sizeof(LEDpins);
  const int charWidth = 5;

 const char textString[] = "Elio Lopes";
 
 void setup()
 {
   pinMode(13, OUTPUT);
    pinMode(1 , OUTPUT);
   pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
 }
 
 void loop()
 {
    digitalWrite(13, LOW);
     
   // printing every letter of the textString
   for (int k=0; k<sizeof(textString); k++){
     printLetter(textString[k]);
   }
 }
 void printLetter(char ch)
 {
   if (ch < 32 || ch > 126){
     ch = 32;
   }
   // subtract the space character (converts the ASCII number to the font index number)
   ch -= 32;
   // step through each byte of the character array
   for (int i=0; i<charWidth; i++) {
     byte b = font[ch][i];
 
     // bit shift through the byte and output it to the pin
     for (int j=0; j<charHeight; j++) {
       digitalWrite(LEDpins[j], !!(b & (1 << j)));
     
     }
     // space between columns
 
 delayMicroseconds(900);
   }
   //clear the LEDs
 digitalWrite(1 , LOW);   // set the LED on
digitalWrite(2 , LOW);   // set the LED on
digitalWrite(3 , LOW);   // set the LED on
digitalWrite(4 , LOW);   // set the LED on
digitalWrite(5 ,LOW);   // set the LED on
digitalWrite(6 , LOW);   // set the LED on
digitalWrite(7 , LOW);   // set the LED on
   
   // space between letters
   delayMicroseconds(2500);
 
 }
