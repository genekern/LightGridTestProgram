
#include <G35String.h>
#include <G35StringGroup.h>

#include "led_utils.h"

Led_utils::Led_utils (  )
:
lights_1(8,35),
lights_2(7,35),
string_group()
{
}

void Led_utils::initialize ( void )
{
  // light board setup
  lights_1.enumerate();
  lights_2.enumerate();

  string_group.AddString(&lights_1);
  string_group.AddString(&lights_2);
  delay(500);
  clearscreen();
  string_group.fill_color(0,70,0,0);
}
/*
void Led_utils::setCol(byte col, byte pattern, byte intesity, unsigned int color) 
 {
 byte led;
 byte dir = 0;
 byte pattern_mask = 0x40;
 
 if (col & 0x01) dir = 6;
 
 for ( byte i = 0; i < 7; i++)
 {  
 if (pattern & pattern_mask) 
 { 
 led = (col*7)+(abs(dir-i)); 
 string_group.set_color(led, intesity, color);
 }
 else
 { 
 led = (col*7)+(abs(dir-i)); 
 string_group.set_color(led, intesity, COLOR_BLACK);
 }
 pattern_mask = pattern_mask >> 1;
 }
 }
 
 
 void Led_utils::scrollSequence(char *seq, byte len, byte intensity, unsigned int color) 
 {
 // 10 is the number of columns in the grid
 for (int p = 0; p < len+10; p++)
 {
 for (int j = 0; j < len; j++)
 {
 if (((p-j) > -1) && ((p-j) < 10))
 {
 setCol(p-j, (byte)seq[j], intensity, color);
 }
 }
 delay(150);
 }
 }
 
 
 void Led_utils::putChar(char *seq, int c, int font_size)
 {
 if (c == 0) 
 {
 *seq++ = 0;
 }
 else 
 {
 if ( c >= 0x60 && c <= 0x7f ) c = c - 0x20;
 if ( font_size <= FONT_3_X_5 )
 {
 for (int col=0; col < FONT_3_X_5; col++)
 {
 *seq++ = pgm_read_byte_near(&font3x5[c - 0x20][col]);
 }
 }
 else
 {
 for (int col=0; col < FONT_5_X_7; col++)
 {
 *seq++ = pgm_read_byte_near(&font5x7[c - 0x20][col]);
 }
 }
 }
 *seq++ = 0;
 }
 
 
 void Led_utils::scrollText(const char* string, unsigned int string_color, int font_size) 
 {
 char scroll_buf[(font_size + 1)*50];
 
 for ( int i = 0; i < (font_size + 1)*50 ; i++ ) scroll_buf[i] = 0;
 
 for (int i = 0; i < strlen(string); i++)
 {
 putChar(scroll_buf + (i * (font_size + 1)), string[i], font_size);
 }
 scrollSequence(scroll_buf, strlen(string)*(font_size + 1), 255, string_color);
 }
 
 void Led_utils::outChar( char inchar, unsigned int string_color, int left_column, int font_size)
 {
 char column_buffer[10];
 
 for ( int i = 0; i < 10 ; i++ ) column_buffer[i] = 0;
 
 putChar(column_buffer, inchar, font_size);
 
 for (int j = 0; j < font_size; j++)
 {
 setCol(font_size + left_column - j, (byte)column_buffer[j], 255, string_color);
 }
 }
 */
void Led_utils::setLed( int led, int brightness, unsigned int color )
{
  string_group.set_color(led, brightness, color);
}

void Led_utils::clearscreen() 
{
  string_group.fill_color(0,70,0,0);
}






