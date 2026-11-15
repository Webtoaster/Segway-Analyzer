#pragma once
#ifndef SPI_TFT_H
#define SPI_TFT_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

// Color definitions (16-bit 565 format)
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

extern void initDisplay();
extern void updateDisplay();
extern void lcdTestPattern();
extern void clearDisplay();
extern void writeText(int, String);
extern void drawBatteryLine(int, int);

#endif
