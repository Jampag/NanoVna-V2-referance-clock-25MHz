/*
 * Font size 5x7 pixels
 * most font glyph have width 5 pixels
 */

#include <stdint.h>

/*
 * Check 1 byte of char bitmap data for get width
 */

// Font definitions
#define FONT_GET_DATA(ch)   (&x5x7_bits[ch*7])
#define FONT_GET_WIDTH(ch)  (8-(x5x7_bits[ch*7]&7))
#define FONT_MAX_WIDTH      7
#define FONT_WIDTH          5
#define FONT_GET_HEIGHT     7
#define FONT_STR_HEIGHT     8

#define CHAR5x7_WIDTH_1px  0x07
#define CHAR5x7_WIDTH_2px  0x06
#define CHAR5x7_WIDTH_3px  0x05
#define CHAR5x7_WIDTH_4px  0x04
#define CHAR5x7_WIDTH_5px  0x03
#define CHAR5x7_WIDTH_6px  0x02
#define CHAR5x7_WIDTH_7px  0x01
#define CHAR5x7_WIDTH_8px  0x00

/* Font character bitmap data. */
const uint8_t x5x7_bits[127*7] =
{

  /* Character (0x00):
     width=5
     +--------+
     |****    |
     |****    |
     |****    |
     |****    |
     |****    |
     |****    |
     |        |
     +--------+ */
  0b11110000|CHAR5x7_WIDTH_5px,
  0b11110000,
  0b11110000,
  0b11110000,
  0b11110000,
  0b11110000,
  0b00000000,

  /* Character (0x01):
     width=5
     +--------+
     |        |
     |  *     |
     | ***    |
     |*****   |
     | ***    |
     |  *     |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b01110000,
  0b11111000,
  0b01110000,
  0b00100000,
  0b00000000,

  /* Character (0x02):
     width=5
     +--------+
     | * *    |
     |* * *   |
     | * *    |
     |* * *   |
     | * *    |
     |* * *   |
     | * *    |
     +--------+ */
  0b01010000|CHAR5x7_WIDTH_5px,
  0b10101000,
  0b01010000,
  0b10101000,
  0b01010000,
  0b10101000,
  0b01010000,

  /* Character (0x03):
     width=5
     +--------+
     |* *     |
     |***     |
     |* *     |
     |* *     |
     | ***    |
     |  *     |
     |  *     |
     +--------+ */
  0b10100000|CHAR5x7_WIDTH_5px,
  0b11100000,
  0b10100000,
  0b10100000,
  0b01110000,
  0b00100000,
  0b00100000,

  /* Character (0x04):
     width=6
     +--------+
     |        |
     |  *     |
     |  *     |
     | * *    |
     | * *    |
     |*   *   |
     |*****   |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00100000,
  0b00100000,
  0b01010000,
  0b01010000,
  0b10001000,
  0b11111000,

  /* Character (0x05):
     width=5
     +--------+
     |**      |
     |*       |
     |**      |
     | **     |
     | * *    |
     | **     |
     | * *    |
     +--------+ */
  0b11000000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b11000000,
  0b01100000,
  0b01010000,
  0b01100000,
  0b01010000,

  /* Character (0x06):
     width=5
     +--------+
     |*       |
     |*       |
     |**      |
     |  **    |
     |  *     |
     |  **    |
     |  *     |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b11000000,
  0b00110000,
  0b00100000,
  0b00110000,
  0b00100000,

  /* Character (0x07):
     width=5
     +--------+
     |  *     |
     | * *    |
     |  *     |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b01010000,
  0b00100000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x08):
     width=5
     +--------+
     |        |
     |  *     |
     | ***    |
     |  *     |
     |        |
     | ***    |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b01110000,
  0b00100000,
  0b00000000,
  0b01110000,
  0b00000000,

  /* Character (0x09):
     width=5
     +--------+
     |*  *    |
     |** *    |
     |* **    |
     |*  *    |
     |  *     |
     |  *     |
     |  **    |
     +--------+ */
  0b10010000|CHAR5x7_WIDTH_5px,
  0b11010000,
  0b10110000,
  0b10010000,
  0b00100000,
  0b00100000,
  0b00110000,

  /* Character (0x0a):
     width=5
     +--------+
     |* *     |
     |* *     |
     |* *     |
     | *      |
     | ***    |
     |  *     |
     |  *     |
     +--------+ */
  0b10100000|CHAR5x7_WIDTH_5px,
  0b10100000,
  0b10100000,
  0b01000000,
  0b01110000,
  0b00100000,
  0b00100000,

  /* Character (0x0b):
     width=5
     +--------+
     |  *     |
     |  *     |
     |  *     |
     |***     |
     |        |
     |        |
     |        |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b00100000,
  0b11100000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x0c):
     width=5
     +--------+
     |        |
     |        |
     |        |
     |***     |
     |  *     |
     |  *     |
     |  *     |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b00000000,
  0b11100000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x0d):
     width=5
     +--------+
     |        |
     |        |
     |        |
     |  ***   |
     |  *     |
     |  *     |
     |  *     |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b00000000,
  0b00111000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x0e):
     width=5
     +--------+
     |  *     |
     |  *     |
     |  *     |
     |  ***   |
     |        |
     |        |
     |        |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b00100000,
  0b00111000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x0f):
     width=5
     +--------+
     |  *     |
     |  *     |
     |  *     |
     |*****   |
     |  *     |
     |  *     |
     |  *     |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b00100000,
  0b11111000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x10):
     width=5
     +--------+
     |        |
     |*****   |
     |        |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b11111000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x11):
     width=5
     +--------+
     |        |
     |        |
     |*****   |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b11111000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x12):
     width=5
     +--------+
     |        |
     |        |
     |        |
     |*****   |
     |        |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b00000000,
  0b11111000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x13):
     width=5
     +--------+
     |        |
     |        |
     |        |
     |        |
     |*****   |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111000,
  0b00000000,
  0b00000000,

  /* Character (0x14):
     width=5
     +--------+
     |        |
     |        |
     |        |
     |        |
     |        |
     |*****   |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111000,
  0b00000000,

  /* Character (0x15):
     width=5
     +--------+
     |  *     |
     |  *     |
     |  *     |
     |  ***   |
     |  *     |
     |  *     |
     |  *     |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b00100000,
  0b00111000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x16):
     width=5
     +--------+
     |   **   |
     |  ***   |
     |  ***   |
     |  ***   |
     |  ***   |
     |  ***   |
     |   **   |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b00100000,
  0b11100000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x17):
     width=6
     +--------+
     |        |
     |**      |
     |****    |
     |******  |
     |****    |
     |**      |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b11000000,
  0b11110000,
  0b00011100,
  0b11110000,
  0b11000000,
  0b00000000,

  /* Character (0x18):
     width=5
     +--------+
     |*       |
     |**      |
     |***     |
     |****    |
     |***     |
     |**      |
     |*       |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_4px,
  0b11000000,
  0b11100000,
  0b11110000,
  0b11100000,
  0b11000000,
  0b10000000,

  /* Character (0x19):
     width=7
     +--------+
     |        |
     | ** **  |
     |* **  * |
     |*  *  * |
     |*  ** * |
     | ** **  |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_7px,
  0b01101100,
  0b10110010,
  0b10010010,
  0b10011010,
  0b01101100,
  0b00000000,

  /* Character (0x1a):
     width=6
     +--------+
     |        |
     |  *     |
     | *      |
     |*****   |
     | *      |
     |  *     |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00100000,
  0b01000000,
  0b11111000,
  0b01000000,
  0b00100000,
  0b00000000,

  /* Character (0x1b):
     width=6
     +--------+
     |        |
     |  *     |
     |   *    |
     |*****   |
     |   *    |
     |  *     |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00100000,
  0b00010000,
  0b11111000,
  0b00010000,
  0b00100000,
  0b00000000,

  /* Character (0x1c):
      width=6
     +--------+
     |        |
     |*****   |
     | * *    |
     | * *    |
     | * *    |
     | * *    |
     |*  **   |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b11111000,
  0b01010000,
  0b01010000,
  0b01010000,
  0b01010000,
  0b10011000,

  /* Character (0x1d):
     width=6
     +--------+
     |        |
     |        |
     |*   *   |
     |*   *   |
     |** **   |
     |* * *   |
     |*       |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00000000,
  0b10001000,
  0b10001000,
  0b11011000,
  0b10101000,
  0b10000000,

  /* Character (0x1e):
     width=6
     +--------+
     |        |
     | ***    |
     |*   *   |
     |*   *   |
     |*   *   |
     | * *    |
     |** **   |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b01110000,
  0b10001000,
  0b10001000,
  0b10001000,
  0b01010000,
  0b11011000,

  /* Character (0x1f):
     width=5
     +--------+
     | **     |
     |*  *    |
     |*  *    |
     | **     |
     |        |
     |        |
     |        |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b01100000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x20): ' '
     width=3
     +--------+
     |        |
     |        |
     |        |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_4px,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x21): '!'
     width=3
     +--------+
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |        |
     |  *     |
     +--------+ */
  0b01000000|CHAR5x7_WIDTH_3px,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b00000000,
  0b01000000,

  /* Character (0x22): '"'
     width=5
     +--------+
     | * *    |
     | * *    |
     | * *    |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b01010000,
  0b01010000,
  0b01010000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x23): '#'
     width=5
     +--------+
     | * *    |
     | * *    |
     |*****   |
     | * *    |
     |*****   |
     | * *    |
     | * *    |
     +--------+ */
  0b01010000|CHAR5x7_WIDTH_6px,
  0b01010000,
  0b11111000,
  0b01010000,
  0b11111000,
  0b01010000,
  0b01010000,

  /* Character (0x24): '$'
    width=5
     +--------+
     |  *     |
     | ****   |
     |* *     |
     | ***    |
     |  * *   |
     |****    |
     |  *     |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_6px,
  0b01111000,
  0b10100000,
  0b01110000,
  0b00101000,
  0b11110000,
  0b00100000,

  /* Character (0x25): '%'
     width=6
     +--------+
     |**      |
     |**  *   |
     |   *    |
     |  *     |
     | *      |
     |*  **   |
     |   **   |
     +--------+ */
  0b11000000|CHAR5x7_WIDTH_6px,
  0b11001000,
  0b00010000,
  0b00100000,
  0b01000000,
  0b10011000,
  0b00011000,

  /* Character (0x26): '&'
     width=5
     +--------+
     |        |
     |  *     |
     | * *    |
     | **     |
     |* * *   |
     |*  *    |
     | ** *   |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00100000,
  0b01010000,
  0b01100000,
  0b10101000,
  0b10010000,
  0b01101000,

  /* Character (0x27): '''
     width=4
     +--------+
     | **     |
     | *      |
     |*       |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b10000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x28): '('
     width=4
     +--------+
     |  *     |
     | *      |
     |*       |
     |*       |
     |*       |
     | *      |
     |  *     |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b01000000,
  0b00100000,

  /* Character (0x29): ')'
     width=5
     +--------+
     |*       |
     | *      |
     |  *     |
     |  *     |
     |  *     |
     | *      |
     |*       |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b01000000,
  0b10000000,

  /* Character (0x2a): '*'
     width=6
     +--------+
     |        |
     |  *     |
     |* * *   |
     | ***    |
     |* * *   |
     |  *     |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00100000,
  0b10101000,
  0b01110000,
  0b10101000,
  0b00100000,
  0b00000000,

  /* Character (0x2b): '+'
     width=6
     +--------+
     |        |
     |  *     |
     |  *     |
     |*****   |
     |  *     |
     |  *     |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00100000,
  0b00100000,
  0b11111000,
  0b00100000,
  0b00100000,
  0b00000000,

  /* Character (0x2c): ','
     width=4
     +--------+
     |        |
     |        |
     |        |
     |        |
     |**      |
     | *      |
     |*       |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_3px,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11000000,
  0b01000000,
  0b10000000,

  /* Character (0x2d): '-'
     width=5
     +--------+
     |        |
     |        |
     |        |
     |****    |
     |        |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b00000000,
  0b11110000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x2e): '.'
     width=3
     +--------+
     |        |
     |        |
     |        |
     |        |
     |        |
     |**      |
     |**      |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_3px,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11000000,
  0b11000000,

  /* Character (0x2f): '/'
     width=4
     +--------+
     |  *     |
     |  *     |
     | *      |
     | *      |
     | *      |
     |*       |
     |*       |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_4px,
  0b00100000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b10000000,
  0b10000000,

  /* Character (0x30): '0'
     width=5
     +--------+
     | **     |
     |*  *    |
     |* **    |
     |** *    |
     |*  *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10110000,
  0b11010000,
  0b10010000,
  0b10010000,
  0b01100000,

  /* Character (0x31): '1'
     width=5
     +--------+
     |  *     |
     | **     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     | ***    |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b01100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b01110000,

  /* Character (0x32): '2'
     width=5
     +--------+
     | **     |
     |*  *    |
     |   *    |
     |  *     |
     | *      |
     |*       |
     |****    |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b00010000,
  0b00100000,
  0b01000000,
  0b10000000,
  0b11110000,

  /* Character (0x33): '3'
     width=5
     +--------+
     | **     |
     |*  *    |
     |   *    |
     | **     |
     |   *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b00010000,
  0b01100000,
  0b00010000,
  0b10010000,
  0b01100000,

  /* Character (0x34): '4'
     width=5
     +--------+
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |****    |
     |   *    |
     |   *    |
     +--------+ */
  0b10010000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b10010000,
  0b11110000,
  0b00010000,
  0b00010000,

  /* Character (0x35): '5'
     width=5
     +--------+
     |****    |
     |*       |
     |***     |
     |   *    |
     |   *    |
     |*  *    |
     | **     |
     +--------+ */
  0b11110000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b11100000,
  0b00010000,
  0b00010000,
  0b10010000,
  0b01100000,

  /* Character (0x36): '6'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*       |
     |***     |
     |*  *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10000000,
  0b11100000,
  0b10010000,
  0b10010000,
  0b01100000,

  /* Character (0x37): '7'
     width=5
     +--------+
     |****    |
     |   *    |
     |  *     |
     |  *     |
     | *      |
     | *      |
     | *      |
     +--------+ */
  0b11110000|CHAR5x7_WIDTH_5px,
  0b00010000,
  0b00100000,
  0b00100000,
  0b01000000,
  0b01000000,
  0b01000000,

  /* Character (0x38): '8'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*  *    |
     | **     |
     |*  *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b01100000,
  0b10010000,
  0b10010000,
  0b01100000,

  /* Character (0x39): '9'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*  *    |
     | ***    |
     |   *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b01110000,
  0b00010000,
  0b10010000,
  0b01100000,

  /* Character (0x3a): ':'
      width=3
     +--------+
     |        |
     |**      |
     |**      |
     |        |
     |**      |
     |**      |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_4px,
  0b11000000,
  0b11000000,
  0b00000000,
  0b11000000,
  0b11000000,
  0b00000000,

  /* Character (0x3b): ';'
     width=4
     +--------+
     |        |
     | **     |
     | **     |
     |        |
     | **     |
     | *      |
     |*       |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_4px,
  0b01100000,
  0b01100000,
  0b00000000,
  0b01100000,
  0b01000000,
  0b10000000,

  /* Character (0x3c): '<'
    width=5
     +--------+
     |        |
     |  *     |
     | *      |
     |*       |
     | *      |
     |  *     |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00100000,
  0b01000000,
  0b10000000,
  0b01000000,
  0b00100000,
  0b00000000,

  /* Character (0x3d): '='
     width=5
     +--------+
     |        |
     |        |
     |****    |
     |        |
     |****    |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b11110000,
  0b00000000,
  0b11110000,
  0b00000000,
  0b00000000,

  /* Character (0x3e): '>'
     width=5
     +--------+
     |        |
     |*       |
     | *      |
     |  *     |
     | *      |
     |*       |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b01000000,
  0b00100000,
  0b01000000,
  0b10000000,
  0b00000000,

  /* Character (0x3f): '?'
     width=5
     +--------+
     | **     |
     |*  *    |
     |   *    |
     |  *     |
     | *      |
     |        |
     | *      |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b00010000,
  0b00100000,
  0b01000000,
  0b00000000,
  0b01000000,

  /* Character (0x40): '@'
     width=5
     +--------+
     | **     |
     |*  *    |
     |* **    |
     |* **    |
     |*       |
     |*       |
     | ***    |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10110000,
  0b10110000,
  0b10000000,
  0b10000000,
  0b01110000,

  /* Character (0x41): 'A'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*  *    |
     |*  *    |
     |****    |
     |*  *    |
     |*  *    |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b10010000,
  0b11110000,
  0b10010000,
  0b10010000,

  /* Character (0x42): 'B'
     width=5
     +--------+
     |***     |
     |*  *    |
     |*  *    |
     |***     |
     |*  *    |
     |*  *    |
     |***     |
     +--------+ */
  0b11100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b11100000,
  0b10010000,
  0b10010000,
  0b11100000,

  /* Character (0x43): 'C'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*       |
     |*       |
     |*       |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10010000,
  0b01100000,

  /* Character (0x44): 'D'
     width=5
     +--------+
     |***     |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |***     |
     +--------+ */
  0b11100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b11100000,

  /* Character (0x45): 'E'
     width=5
     +--------+
     |****    |
     |*       |
     |*       |
     |***     |
     |*       |
     |*       |
     |****    |
     +--------+ */
  0b11110000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b10000000,
  0b11100000,
  0b10000000,
  0b10000000,
  0b11110000,

  /* Character (0x46): 'F'
     width=5
     +--------+
     |****    |
     |*       |
     |*       |
     |***     |
     |*       |
     |*       |
     |*       |
     +--------+ */
  0b11110000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b10000000,
  0b11100000,
  0b10000000,
  0b10000000,
  0b10000000,

  /* Character (0x47): 'G'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*       |
     |* **    |
     |*  *    |
     |*  *    |
     | ***    |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10000000,
  0b10110000,
  0b10010000,
  0b10010000,
  0b01110000,

  /* Character (0x48): 'H'
     width=5
     +--------+
     |*  *    |
     |*  *    |
     |*  *    |
     |****    |
     |*  *    |
     |*  *    |
     |*  *    |
     +--------+ */
  0b10010000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b11110000,
  0b10010000,
  0b10010000,
  0b10010000,

  /* Character (0x49): 'I'
     width=4
     +--------+
     |***     |
     | *      |
     | *      |
     | *      |
     | *      |
     | *      |
     |***     |
     +--------+ */
  0b11100000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b11100000,

  /* Character (0x4a): 'J'
     width=5
     +--------+
     | ***    |
     |   *    |
     |   *    |
     |   *    |
     |   *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01110000|CHAR5x7_WIDTH_5px,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b10010000,
  0b01100000,

  /* Character (0x4b): 'K'
     width=5
     +--------+
     |*  *    |
     |*  *    |
     |* *     |
     |**      |
     |* *     |
     |*  *    |
     |*  *    |
     +--------+ */
  0b10010000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b11100000,
  0b10010000,
  0b10010000,
  0b10010000,

  /* Character (0x4c): 'L'
     width=5
     +--------+
     |*       |
     |*       |
     |*       |
     |*       |
     |*       |
     |*       |
     |****    |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b11110000,

  /* Character (0x4d): 'M'
     width=6
     +--------+
     |*   *   |
     |** **   |
     |* * *   |
     |* * *   |
     |*   *   |
     |*   *   |
     |*   *   |
     +--------+ */
  0b10001000|CHAR5x7_WIDTH_6px,
  0b11011000,
  0b10101000,
  0b10101000,
  0b10001000,
  0b10001000,
  0b10001000,

  /* Character (0x4e): 'N'
     width=5
     +--------+
     |*  *    |
     |*  *    |
     |** *    |
     |* **    |
     |*  *    |
     |*  *    |
     |*  *    |
     +--------+ */
  0b10010000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b11010000,
  0b10110000,
  0b10010000,
  0b10010000,
  0b10010000,

  /* Character (0x4f): 'O'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b01100000,

  /* Character (0x50): 'P'
     width=5
     +--------+
     |***     |
     |*  *    |
     |*  *    |
     |***     |
     |*       |
     |*       |
     |*       |
     +--------+ */
  0b11100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b11100000,
  0b10000000,
  0b10000000,
  0b10000000,

  /* Character (0x51): 'Q'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |* *     |
     | * *    |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10100000,
  0b01010000,

  /* Character (0x52): 'R'
     width=5
     +--------+
     |***     |
     |*  *    |
     |*  *    |
     |***     |
     |* *     |
     |*  *    |
     |*  *    |
     +--------+ */
  0b11100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b11100000,
  0b10010000,
  0b10010000,
  0b10010000,

  /* Character (0x53): 'S'
     width=5
     +--------+
     | **     |
     |*  *    |
     |*       |
     | **     |
     |   *    |
     |*  *    |
     | **     |
     +--------+ */
  0b01100000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10000000,
  0b01100000,
  0b00010000,
  0b10010000,
  0b01100000,

  /* Character (0x54): 'T'
     width=6
     +--------+
     |*****   |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     +--------+ */
  0b11111000|CHAR5x7_WIDTH_6px,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x55): 'U'
     width=5
     +--------+
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     | ***    |
     +--------+ */
  0b10010000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b01110000,

  /* Character (0x56): 'V'
     width=5
     +--------+
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     |*  *    |
     | **     |
     | **     |
     +--------+ */
  0b10010000|CHAR5x7_WIDTH_5px,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b01100000,
  0b01100000,

  /* Character (0x57): 'W'
     width=6
     +--------+
     |*   *   |
     |*   *   |
     |*   *   |
     |* * *   |
     |* * *   |
     |* * *   |
     | * *    |
     +--------+ */
  0b10001000|CHAR5x7_WIDTH_6px,
  0b10001000,
  0b10001000,
  0b10101000,
  0b10101000,
  0b10101000,
  0b01010000,

  /* Character (0x58): 'X'
     width=6
     +--------+
     |*   *   |
     |*   *   |
     | * *    |
     |  *     |
     | * *    |
     |*   *   |
     |*   *   |
     +--------+ */
  0b10001000|CHAR5x7_WIDTH_6px,
  0b10001000,
  0b01010000,
  0b00100000,
  0b01010000,
  0b10001000,
  0b10001000,

  /* Character (0x59): 'Y'
     width=6
     +--------+
     |*   *   |
     |*   *   |
     |*   *   |
     | * *    |
     |  *     |
     |  *     |
     |  *     |
     +--------+ */
  0b10001000|CHAR5x7_WIDTH_6px,
  0b10001000,
  0b10001000,
  0b01010000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x5a): 'Z'
     width=5
     +--------+
     |****    |
     |   *    |
     |  *     |
     | *      |
     |*       |
     |*       |
     |****    |
     +--------+ */
  0b11110000|CHAR5x7_WIDTH_5px,
  0b00010000,
  0b00100000,
  0b01000000,
  0b10000000,
  0b10000000,
  0b11110000,

  /* Character (0x5b): '['
     width=4
     +--------+
     |***     |
     |*       |
     |*       |
     |*       |
     |*       |
     |*       |
     |***     |
     +--------+ */
  0b11100000|CHAR5x7_WIDTH_4px,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b11100000,

  /* Character (0x5c): '\'
     width=4
     +--------+
     |*       |
     |*       |
     | *      |
     | *      |
     | *      |
     |  *     |
     |  *     |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_4px,
  0b10000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b00100000,
  0b00100000,

  /* Character (0x5d): ']'
     width=4
     +--------+
     |***     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |***     |
     +--------+ */
  0b11100000|CHAR5x7_WIDTH_4px,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b11100000,

  /* Character (0x5e): '^'
     width=4
     +--------+
     | *      |
     |* *     |
     |        |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b01000000|CHAR5x7_WIDTH_4px,
  0b10100000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x5f): '_'
     width=5
     +--------+
     |        |
     |        |
     |        |
     |        |
     |        |
     |        |
     |*****   |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111000,

  /* Character (0x60): '`'
     width=4
     +--------+
     |**      |
     | *      |
     |  *     |
     |        |
     |        |
     |        |
     |        |
     +--------+ */
  0b11000000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b00100000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,

  /* Character (0x61): 'a'
     width=5
     +--------+
     |        |
     |        |
     | ***    |
     |*  *    |
     |*  *    |
     |* **    |
     | * *    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01110000,
  0b10010000,
  0b10010000,
  0b10110000,
  0b01010000,

  /* Character (0x62): 'b'
     width=5
     +--------+
     |*       |
     |*       |
     |* *     |
     |** *    |
     |*  *    |
     |*  *    |
     |***     |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b10100000,
  0b11010000,
  0b10010000,
  0b10010000,
  0b11100000,

  /* Character (0x63): 'c'
     width=5
     +--------+
     |        |
     |        |
     | ***    |
     |*       |
     |*       |
     |*       |
     | ***    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01110000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b01110000,

  /* Character (0x64): 'd'
     width=5
     +--------+
     |   *    |
     |   *    |
     | * *    |
     |* **    |
     |*  *    |
     |*  *    |
     | ***    |
     +--------+ */
  0b00010000|CHAR5x7_WIDTH_5px,
  0b00010000,
  0b01010000,
  0b10110000,
  0b10010000,
  0b10010000,
  0b01110000,

  /* Character (0x65): 'e'
     width=5
     +--------+
     |        |
     |        |
     | **     |
     |*  *    |
     |****    |
     |*       |
     | ***    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01100000,
  0b10010000,
  0b11110000,
  0b10000000,
  0b01110000,

  /* Character (0x66): 'f'
     width=5
     +--------+
     |  *     |
     | * *    |
     | *      |
     |***     |
     | *      |
     | *      |
     | *      |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_5px,
  0b01010000,
  0b01000000,
  0b11100000,
  0b01000000,
  0b01000000,
  0b01000000,

  /* Character (0x67): 'g'
     width=5
     +--------+
     |        |
     |        |
     | ***    |
     |*  *    |
     | ***    |
     |   *    |
     | **     |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01110000,
  0b10010000,
  0b01110000,
  0b00010000,
  0b01100000,

  /* Character (0x68): 'h'
     width=5
     +--------+
     |*       |
     |*       |
     |* *     |
     |** *    |
     |*  *    |
     |*  *    |
     |*  *    |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b10100000,
  0b11010000,
  0b10010000,
  0b10010000,
  0b10010000,

  /* Character (0x69): 'i'
     width=4
     +--------+
     | *      |
     |        |
     |**      |
     | *      |
     | *      |
     | *      |
     |***     |
     +--------+ */
  0b01000000|CHAR5x7_WIDTH_4px,
  0b00000000,
  0b11000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b11100000,

  /* Character (0x6a):
     width=4
     +--------+
     |  *     |
     |        |
     |  *     |
     |  *     |
     |  *     |
     |* *     |
     | *      |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_4px,
  0b00000000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b10100000,
  0b01000000,

  /* Character (0x6b): 'k'
     width=5
     +--------+
     |*       |
     |*       |
     |*  *    |
     |* *     |
     |**      |
     |* *     |
     |*  *    |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_5px,
  0b10000000,
  0b10010000,
  0b10100000,
  0b11000000,
  0b10100000,
  0b10010000,

  /* Character (0x6c): 'l'
     width=4
     +--------+
     |**      |
     | *      |
     | *      |
     | *      |
     | *      |
     | *      |
     |***     |
     +--------+ */
  0b11000000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b11100000,

  /* Character (0x6d): 'm'
     width=6
     +--------+
     |        |
     |        |
     |****    |
     |* * *   |
     |* * *   |
     |* * *   |
     |* * *   |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00000000,
  0b11110000,
  0b10101000,
  0b10101000,
  0b10101000,
  0b10101000,

  /* Character (0x6e): 'n'
     width=5
     +--------+
     |        |
     |        |
     |* *     |
     |** *    |
     |*  *    |
     |*  *    |
     |*  *    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b10100000,
  0b11010000,
  0b10010000,
  0b10010000,
  0b10010000,

  /* Character (0x6f): 'o'
     width=5
     +--------+
     |        |
     |        |
     | **     |
     |*  *    |
     |*  *    |
     |*  *    |
     | **     |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01100000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b01100000,

  /* Character (0x70): 'p'
     width=5
     +--------+
     |        |
     |        |
     |***     |
     |*  *    |
     |*  *    |
     |***     |
     |*       |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b11100000,
  0b10010000,
  0b10010000,
  0b11100000,
  0b10000000,

  /* Character (0x71): 'q'
     width=5
     +--------+
     |        |
     |        |
     | ***    |
     |*  *    |
     |*  *    |
     | ***    |
     |   *    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01110000,
  0b10010000,
  0b10010000,
  0b01110000,
  0b00010000,

  /* Character (0x72): 'r'
     width=5
     +--------+
     |        |
     |        |
     |* *     |
     |** *    |
     |*       |
     |*       |
     |*       |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b10100000,
  0b11010000,
  0b10000000,
  0b10000000,
  0b10000000,

  /* Character (0x73): 's'
     width=5
     +--------+
     |        |
     |        |
     | ***    |
     |*       |
     | **     |
     |   *    |
     |***     |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01110000,
  0b10000000,
  0b01100000,
  0b00010000,
  0b11100000,

  /* Character (0x74): 't'
     width=5
     +--------+
     | *      |
     | *      |
     |***     |
     | *      |
     | *      |
     | *      |
     |  **    |
     +--------+ */
  0b01000000|CHAR5x7_WIDTH_5px,
  0b01000000,
  0b11100000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b00110000,

  /* Character (0x75): 'u'
     width=5
     +--------+
     |        |
     |        |
     |*  *    |
     |*  *    |
     |*  *    |
     |* **    |
     | * *    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b10110000,
  0b01010000,

  /* Character (0x76): 'v'
     width=5
     +--------+
     |        |
     |        |
     |*  *    |
     |*  *    |
     |*  *    |
     | **     |
     | **     |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b10010000,
  0b10010000,
  0b10010000,
  0b01100000,
  0b01100000,

  /* Character (0x77): 'w'
     width=6
     +--------+
     |        |
     |        |
     |*   *   |
     |*   *   |
     |* * *   |
     |* * *   |
     | * *    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_6px,
  0b00000000,
  0b10001000,
  0b10001000,
  0b10101000,
  0b10101000,
  0b01010000,

  /* Character (0x78): 'x'
     width=5
     +--------+
     |        |
     |        |
     |*  *    |
     |*  *    |
     | **     |
     |*  *    |
     |*  *    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b10010000,
  0b10010000,
  0b01100000,
  0b10010000,
  0b10010000,

  /* Character (0x79): 'y'
     width=5
     +--------+
     |        |
     |        |
     |*  *    |
     |*  *    |
     | ***    |
     |   *    |
     |***     |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b10010000,
  0b10010000,
  0b01110000,
  0b00010000,
  0b11100000,

  /* Character (0x7a): 'z'
     width=5
     +--------+
     |        |
     |        |
     |****    |
     |  *     |
     | *      |
     |*       |
     |****    |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b11110000,
  0b00100000,
  0b01000000,
  0b10000000,
  0b11110000,

  /* Character (0x7b): '{'
     width=5
     +--------+
     |  *     |
     | *      |
     | *      |
     |*       |
     | *      |
     | *      |
     |  *     |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b01000000,
  0b10000000,
  0b01000000,
  0b01000000,
  0b00100000,

  /* Character (0x7c): '|'
     width=5
     +--------+
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     |  *     |
     +--------+ */
  0b00100000|CHAR5x7_WIDTH_4px,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,
  0b00100000,

  /* Character (0x7d): '}'
     width=5
     +--------+
     |*       |
     | *      |
     | *      |
     |  *     |
     | *      |
     | *      |
     |*       |
     +--------+ */
  0b10000000|CHAR5x7_WIDTH_4px,
  0b01000000,
  0b01000000,
  0b00100000,
  0b01000000,
  0b01000000,
  0b10000000,

  /* Character (0x7e): '~'
     width=5
     +--------+
     |        |
     |        |
     | * *    |
     |* *     |
     |        |
     |        |
     |        |
     +--------+ */
  0b00000000|CHAR5x7_WIDTH_5px,
  0b00000000,
  0b01010000,
  0b10100000,
  0b00000000,
  0b00000000,
  0b00000000,
};