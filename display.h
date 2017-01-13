#ifndef display_h
#define display_h

#include "Arduino.h"
#include <avr/io.h>

#define DEBUG_DISPLAY false
#define FPS = 30;

#define SHIFT_PORT PORTB
#define SR_DATA (1<<PB3)  // MOSI (SI)  11
#define SR_LATCH (1<<PB2) // SS   (RCK) 10
#define SR_CLOCK (1<<PB5) // SCK  (SCK) 13
#define SR_RESET (1<<PB1) // 9


class Display
{
  public:
    Display();
    void init();
    void update(unsigned long t); // t = time in milliseconds
    void set_pixel(byte x, byte y, byte value);
    void clear_pixel(byte x, byte y);
    byte get_pixel(byte x, byte y);
    
  private:
    void shiftout(byte* data);
    void spi_send(byte data);
    void clearscreen();

    unsigned long _last_update;
    byte _data[7];
    byte _framebuffer[20][10];
    byte _palette[8][3] = { { 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 1, 1, 0 }, { 0, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
};

#endif
