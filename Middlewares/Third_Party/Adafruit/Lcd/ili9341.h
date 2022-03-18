/* Interface mode
   - 1: SPI or parallel interface mode
   - 2: RGB mode (LTDC hardware, HSYNC, VSYNC, pixel clock, RGB bits data, framebuffer memory)
*/
#define  ILI9341_INTERFACE_MODE   1

/* Orientation
   - 0: 240x320 portrait (plug in top)
   - 1: 320x240 landscape (plug in left)
   - 2: 240x320 portrait (plug in bottom)
   - 3: 320x240 landscape (plug in right)
*/
#define  ILI9341_ORIENTATION      0

/* Color mode
   - 0: RGB565 (R:bit15..11, G:bit10..5, B:bit4..0)
   - 1: BRG565 (B:bit15..11, G:bit10..5, R:bit4..0)
*/
#define  ILI9341_COLORMODE        0

/* To clear the screen before display turning on ?
   - 0: does not clear
   - 1: clear
*/
#define  ILI9341_INITCLEAR        1

/* Analog touchscreen (only INTERFACE_MODE == 1, 8bit parallel IO mode)
   - 0: touchscreen disabled
   - 1: touchscreen enabled
*/
#define  ILI9341_TOUCH            1

/* Touchscreen calibration data for 4 orientations */
#define  TS_CINDEX_0        {1444723, 5348, -114234, 421806850, -131233, -975, 521525308}
#define  TS_CINDEX_1        {1444723, -131233, -975, 521525308, -5348, 114234, -76518053}
#define  TS_CINDEX_2        {1444723, -5348, 114234, -76518053, 131233, 975, -60658671}
#define  TS_CINDEX_3        {1444723, 131233, 975, -60658671, 5348, -114234, 421806850}

/* For multi-threaded or intermittent use, Lcd and Touchscreen simultaneous use can cause confusion (since it uses common I/O resources)
   Lcd functions wait for the touchscreen header, the touchscreen query is not executed when Lcd is busy.
   Note: If the priority of the Lcd is higher than that of the Touchscreen, it may end up in an infinite loop!
   - 0: multi-threaded protection disabled
   - 1: multi-threaded protection enabled
*/
#define  ILI9341_MULTITASK_MUTEX   0

#if  ILI9341_INTERFACE_MODE == 2

/* please see in the main.c what is the LTDC_HandleTypeDef name */
extern   LTDC_HandleTypeDef       hltdc;

/* Frambuffer memory alloc, free */
#define  ILI9341_MALLOC           malloc
#define  ILI9341_FREE             free

/* include for memory alloc/free */
#include <stdlib.h>

#endif  /* #if ILI9341_INTERFACE_MODE == 2 */

//-----------------------------------------------------------------------------
// ILI9341 physic resolution (in 0 orientation)
#define  ILI9341_LCD_PIXEL_WIDTH  240
#define  ILI9341_LCD_PIXEL_HEIGHT 320
