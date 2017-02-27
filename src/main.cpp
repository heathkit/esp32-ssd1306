/*
  06/01/2016
  Author: Makerbro
  Platforms: ESP8266
  Language: C++
  File: ControlBrightness.ino
  ------------------------------------------------------------------------
  Description:
  Brightness control example for OLED display.
  ------------------------------------------------------------------------
  Please consider buying products from ACROBOTIC to help fund future
  Open-Source projects like this! We'll always put our best effort in every
  project, and release all our design files and code for you to use.
  https://acrobotic.com/
  ------------------------------------------------------------------------
  License:
  Released under the MIT license. Please check LICENSE.txt for more
  information.  All text above must be included in any redistribution.
*/
#include <Arduino.h>
#include <SPI.h>
#include <ssd1306.h>

#define PIN_RESET 14 // Connect RST to pin 9 (SPI & I2C)
#define PIN_DC    12 // Connect DC to pin 8 (SPI only)
#define PIN_CS    13 // Connect CS to pin 10 (SPI only)
MicroOLED oled(PIN_RESET, PIN_DC, PIN_CS);  // SPI Example

// Global variables to help draw the clock face:
const int MIDDLE_Y = oled.getLCDHeight() / 2;
const int MIDDLE_X = oled.getLCDWidth() / 2;

int CLOCK_RADIUS;
int POS_12_X, POS_12_Y;
int POS_3_X, POS_3_Y;
int POS_6_X, POS_6_Y;
int POS_9_X, POS_9_Y;
int S_LENGTH;
int M_LENGTH;
int H_LENGTH;

void initClockVariables()
{
  // Calculate constants for clock face component positions:
  oled.setFontType(0);
  CLOCK_RADIUS = min(MIDDLE_X, MIDDLE_Y) - 1;
  POS_12_X = MIDDLE_X - oled.getFontWidth();
  POS_12_Y = MIDDLE_Y - CLOCK_RADIUS + 2;
  POS_3_X  = MIDDLE_X + CLOCK_RADIUS - oled.getFontWidth() - 1;
  POS_3_Y  = MIDDLE_Y - oled.getFontHeight()/2;
  POS_6_X  = MIDDLE_X - oled.getFontWidth()/2;
  POS_6_Y  = MIDDLE_Y + CLOCK_RADIUS - oled.getFontHeight() - 1;
  POS_9_X  = MIDDLE_X - CLOCK_RADIUS + oled.getFontWidth() - 2;
  POS_9_Y  = MIDDLE_Y - oled.getFontHeight()/2;

  // Calculate clock arm lengths
  S_LENGTH = CLOCK_RADIUS - 2;
  M_LENGTH = S_LENGTH * 0.7;
  H_LENGTH = S_LENGTH * 0.5;
}

// Draw an analog clock face
void drawFace()
{
  // Draw the clock border
  oled.circle(MIDDLE_X, MIDDLE_Y, CLOCK_RADIUS);

  // Draw the clock numbers
  oled.setFontType(0); // set font type 0, please see declaration in SFE_MicroOLED.cpp
  oled.setCursor(POS_12_X, POS_12_Y); // points cursor to x=27 y=0
  oled.print(12);
  oled.setCursor(POS_6_X, POS_6_Y);
  oled.print(6);
  oled.setCursor(POS_9_X, POS_9_Y);
  oled.print(9);
  oled.setCursor(POS_3_X, POS_3_Y);
  oled.print(3);
}

void setup()
{
  oled.begin();     // Initialize the OLED
  oled.clear(PAGE); // Clear the display's internal memory
  //oled.clear(ALL);  // Clear the library's display buffer
  oled.display();   // Display what's in the buffer (splashscreen)

  //initClockVariables();

  /*
  oled.drawBitmap(ACROBOT);   // 1024 pixels for logo
  oled.setCursor(0,1);              // Set cursor position
  oled.print("   ACROBOTIC   ");
  */

/*
  oled.clear(ALL);
  oled.setFontType(1);
  oled.setCursor(0,0);
  oled.display();
  */
}

unsigned char brightness = 0;

void loop()
{
  /*
  oled.setBrightness((unsigned char)brightness);
  oled.setPageMode();
  oled.setTextXY(7,13);
  oled.putNumber(brightness);
  delay(500);
  if(brightness == 255)
  {
    oled.setTextXY(7,13);           // Display the brighness value starting from 7th Row, 13th Column
    oled.putString("   ");          // Clear 13,14 and 15th Columns. Numbers left aligned.
    brightness = 0;                 // Reset brighness to 0.
  } else
    brightness+=51;
    */
}
