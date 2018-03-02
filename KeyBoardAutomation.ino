//Author : Arunav Mallik Avi (Avi)
//For Keyboard Emulation purposes
//Microcontroller : Arduino Leonardo


char val; 
const int buttonPin = 4;    //Emergency stop button :)    
int buttonState = 0; 

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
  Keyboard.begin();
  Mouse.begin();
}

void loop() {

  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) { 
    Keyboard.releaseAll();
    Keyboard.end();
    Keyboard.begin();
  
  }
  
  if( Serial1.available() )       
  {
    val = Serial1.read();         
  }
  if( val == '1' )               
  {
      Keyboard.press(0xDA);   //UP arrow
  } 
  if( val == '2' )
  {
      Keyboard.press(0xD9);   //DOWN arrow
  }
    if( val == '3' )               
  {
      Keyboard.press(0xD8);   //LEFT arrow
  } 
  if( val == '4' )
  {
      Keyboard.press(0xD7);   //RIGHT arrow
  }
  if( val == '5' )
  {
      Keyboard.press(0xB0);   //Enter Key
  }
  if( val == '6' )
  {
      Keyboard.press(0xB2);   //Back Key
  }
  
  
  if( val == 'x' )
  {
      Keyboard.press(0xB3); //TAB
  }
  
  if( val == 'y' )
  {
      //Mouse.click();
      Keyboard.press(0x82); //Left Alt
  }
  
  if( val == '0' ) 
  {
      Keyboard.releaseAll();   
      Keyboard.end();
      Keyboard.begin();
  }
} 

