#ifndef _CP_OLED_DISPLAY_H_
#define _CP_OLED_DISPLAY_H_

#define USE_U8G2 1
#ifdef USE_U8G2
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


#else
#include "SSD1306Wire.h"  // legacy: #include "SSD1306.h"
#endif

#define DISPLAY_128_64 1


class CPOledDisplay {
public:
  CPOledDisplay();
  void init();
  void setStatus(String text);
  void updatePagerMessage(String sender, String receiver, String message, String textPixelBase64, int textCount);
  void drawTextPixel(int x, int y, int width, int height, const uint16_t* textPixels);
  void drawTest(const unsigned char* data, int dataLen, int textCount);
  void marquee();
private:
#ifdef USE_U8G2
#if DISPLAY_128_64
  U8G2_SSD1306_128X64_NONAME_F_SW_I2C display;
#else
  U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C display;
#endif
#else
  SSD1306Wire display;
#endif
  String messageText;
  int textPosition;
};
#endif