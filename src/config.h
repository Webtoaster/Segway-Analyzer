#pragma once

/* =========================================================================
 * Battery Type Selection
 * Uncomment ONE battery chemistry below (Lithium or NiMH)
 * ========================================================================= */

// For Lithium Segway Batteries:
#define TYPE 0x31
#define CELLGROUPS 23
#define TSENSORS 4

// For NiMH Segway Batteries:
/*
#define TYPE 0x62
#define CELLGROUPS 6
#define TSENSORS 4
*/

/* =========================================================================
 * Communication & Diagnostics
 * ========================================================================= */

// Uncomment for interactive Serial menu (57600 baud) and debug logs
#define SERIAL_SHELL

/* =========================================================================
 * Display Selection
 * Uncomment at most ONE display option below.
 * Note: Required libraries must be listed under lib_deps in platformio.ini.
 * ========================================================================= */

// I2C 20x4 Character LCD (PCF8574 backpack at 0x27)
// Requires: marcoschwartz/LiquidCrystal_I2C in platformio.ini
// #define I2C_LCD_DISPLAY

// SPI 96x64 16-bit Color OLED (SSD1331 driver)
// Requires: adafruit/Adafruit SSD1331 OLED Driver Library for Arduino in platformio.ini
//#define SPI_OLED_DISPLAY

// 3.5" 480x320 TFT Touch Shield (MCUFRIEND_kbv parallel driver)
// Requires: prenticedavid/MCUFRIEND_kbv in platformio.ini
#define SPI_TFT_DISPLAY

/* =========================================================================
 * Sanity Checks / Compile-Time Validations
 * ========================================================================= */

#if !defined(TYPE) || !defined(CELLGROUPS) || !defined(TSENSORS)
  #error "No battery type configured! Please uncomment Lithium or NiMH in config.h."
#endif

#if (defined(I2C_LCD_DISPLAY) + defined(SPI_OLED_DISPLAY) + defined(SPI_TFT_DISPLAY)) > 1
  #error "Multiple display options defined in config.h! Please enable only one display at a time."
#endif
