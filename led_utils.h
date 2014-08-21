
#ifndef LED_UTILS_H
#define LED_UTILS_H



/*************************************************************************************
 * Board Pattern 
 * 
 * |----|----|----|----|----|----|----|----|----|----|
 * | 69 | 56 | 55 | 42 | 41 | 28 | 27 | 14 | 13 |  0 |
 * | 68 | 57 | 54 | 43 | 40 | 29 | 26 | 15 | 12 |  1 |
 * | 67 | 58 | 53 | 44 | 39 | 30 | 25 | 16 | 11 |  2 |
 * | 66 | 59 | 52 | 45 | 38 | 31 | 24 | 17 | 10 |  3 |
 * | 65 | 60 | 51 | 46 | 37 | 32 | 23 | 18 |  9 |  4 |
 * | 64 | 61 | 50 | 47 | 36 | 33 | 22 | 19 |  8 |  5 |
 * | 63 | 62 | 49 | 48 | 35 | 34 | 21 | 20 |  7 |  6 |
 * |----|----|----|----|----|----|----|----|----|----|
 * 
 * Window Pattern From Outside
 * 
 * |----|----|----|----|----|----|----|
 * | 63 | 64 | 65 | 66 | 67 | 68 | 69 |
 * |----|----|----|----|----|----|----|
 * | 62 | 61 | 60 | 59 | 58 | 57 | 56 |
 * |----|----|----|----|----|----|----|
 * | 49 | 50 | 51 | 52 | 53 | 54 | 55 |
 * |----|----|----|----|----|----|----|
 * | 48 | 47 | 46 | 45 | 44 | 43 | 42 |
 * |----|----|----|----|----|----|----|
 * | 35 | 36 | 37 | 38 | 39 | 40 | 41 |
 * |----|----|----|----|----|----|----|
 * | 34 | 33 | 32 | 31 | 30 | 29 | 28 |
 * |----|----|----|----|----|----|----|
 * | 21 | 22 | 23 | 24 | 25 | 26 | 27 |
 * |----|----|----|----|----|----|----|
 * | 20 | 19 | 18 | 17 | 16 | 15 | 14 |
 * |----|----|----|----|----|----|----|
 * |  7 |  8 |  9 | 10 | 11 | 12 | 13 |
 * |----|----|----|----|----|----|----|
 * |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
 * |----|----|----|----|----|----|----|
 * 
 ***********************************************************************************/

#include <Arduino.h>

#include <G35.h>
#include <G35String.h>
#include <G35StringGroup.h>

#include "fonts.h"

#define  LED_STRING_1  10
#define  LED_STRING_2   9
#define  LEDS_PER_STRING  35

class Led_utils //: public G35
{
  int string_1_pin ;
  int string_2_pin ;

  G35String lights_1;//(int, int);
  G35String lights_2;//(int, int);
  G35StringGroup string_group;

public:

  Led_utils ();

  // ~Led_utils (void);

  void initialize ( void );
  /*
  void putChar(char *, int, int );
   void outChar( char , unsigned int, int, int );
   */
  void setLed( int, int, unsigned int);
  void clearscreen(); 

private:

  /*
void setCol(byte, byte, byte, unsigned int ) ;
   void scrollSequence(char*, byte, byte, unsigned int ) ;
   void scrollText(const char*, unsigned int, int ) ;
   */
};

#endif





