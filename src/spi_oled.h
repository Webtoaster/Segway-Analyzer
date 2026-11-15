#pragma once
#ifndef SPI_OLED_H
#define SPI_OLED_H

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

// Display pin definitions
#ifndef CS
#define CS   10
#endif
#ifndef RST
#define RST  9
#endif
#ifndef DC
#define DC   8
#endif
#ifndef SCLK
#define SCLK 13
#endif
#ifndef MOSI
#define MOSI 11
#endif

// Lowercase aliases for backward compatibility
#ifndef cs
#define cs CS
#endif
#ifndef rst
#define rst RST
#endif
#ifndef dc
#define dc DC
#endif
#ifndef sclk
#define sclk SCLK
#endif
#ifndef mosi
#define mosi MOSI
#endif

// Color definitions
#ifndef BLACK
#define BLACK           0x0000
#endif
#ifndef BLUE
#define BLUE            0x001F
#endif
#ifndef RED
#define RED             0xF800
#endif
#ifndef GREEN
#define GREEN           0x07E0
#endif
#ifndef CYAN
#define CYAN            0x07FF
#endif
#ifndef MAGENTA
#define MAGENTA         0xF81F
#endif
#ifndef YELLOW
#define YELLOW          0xFFE0  
#endif
#ifndef WHITE
#define WHITE           0xFFFF
#endif

struct displaymsg {
  char line1[21];
  char line2[21];
  char line3[21];
  char line4[21];
};

extern void initDisplay();
extern void updateDisplay();
extern void lcdTestPattern();
extern void clearDisplay();

#endif
