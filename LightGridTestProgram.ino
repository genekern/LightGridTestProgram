// Hack Pittsburgh Charactor Test program

#include <SoftwareSerial.h>

SoftwareSerial LCD(2,3);

#include <G35String.h>
#include <G35StringGroup.h>

#include "led_utils.h"

Led_utils led_board;

int brightness;
int led = -1;
unsigned int color = 0x0888;

void setup() 
{
  Serial.begin(9600);
  
  led_board.initialize();
  LCD.begin(9600);
  LCD.write(12); // Form Feed, clear screen
  LCD.write(17); // Turn on backlight (Parallax LCD)
  LCD.print("Light Grid Test");
  LCD.write(148); // move to line 1 pos 0

  led_board.clearscreen();
  delay(200);
}

void loop() 
{
  char inchar;

  if (Serial.available ())
  {
    led_board.clearscreen();
    inchar = Serial.read();
    Serial.print("CHAR = ");
    Serial.println(inchar);
    if ( inchar == 0x052 || inchar == 0x072  ) { color = 0x008; brightness = 170; }
    if ( inchar == 0x047 || inchar == 0x067  ) { color = 0x080; brightness = 170; }
    if ( inchar == 0x042 || inchar == 0x062  ) { color = 0x800; brightness = 170; }
//    if ( inchar >= 0x20 && inchar <= 0x7F ) led_board.outChar( inchar, color, -1, FONT_5_X_7);
//    if ( inchar >= 0x20 && inchar <= 0x7F ) led_board.outChar( inchar, color, 6, FONT_3_X_5);
    LCD.write(12); // Form Feed, clear screen
    LCD.write(148); // move to line 1 pos 0
    LCD.print("CHAR = ");
    LCD.print(inchar);
    led = -1;
    // brightness = 0;
    delay(1000);
  }
  else
  {
    LCD.write(148); // move to line 1 pos 0
    if ( led < 71 )
    {
      if ( led > -1 ) led_board.setLed(led, 125, COLOR_BLACK);
      led++;
      led_board.setLed(led, 125, color);
      LCD.print("LED Number = ");
      LCD.print(led);
      Serial.print("LED Number = ");
      Serial.println(led);
      delay(250);
    }
    else
    {
      if ( brightness < 0x0cc ) brightness = brightness + 5;
      else
      {
        if ( color < 0x0fff )
        {
          LCD.write(12); // Form Feed, clear screen
          LCD.print("color = ");
          LCD.print(color, HEX);
          color++;
          brightness = 0;
          LCD.write(12); // Form Feed, clear screen
          LCD.print("color = ");
          LCD.print(color, HEX);
        }
        else
        {
          color = 0;
          brightness = 5;
          led = -1;
        }
        delay(5000);
      }
      led_board.setLed(23, brightness, color);
      led_board.setLed(24, brightness, color);
      led_board.setLed(25, brightness, color);
      led_board.setLed(30, brightness, color);
      led_board.setLed(31, brightness, color);
      led_board.setLed(32, brightness, color);
      led_board.setLed(37, brightness, color);
      led_board.setLed(38, brightness, color);
      led_board.setLed(39, brightness, color);
      led_board.setLed(44, brightness, color);
      led_board.setLed(45, brightness, color);
      led_board.setLed(46, brightness, color);
      Serial.print("color = ");
      Serial.print(color, HEX);
      Serial.print(" bright = ");
      Serial.println(brightness);
      LCD.write(148); // move to line 1 pos 0
      LCD.print("bright = ");
      LCD.print(brightness);
      delay(100);
    }
  }
}





