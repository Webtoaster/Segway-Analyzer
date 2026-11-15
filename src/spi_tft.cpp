#include "config.h"

#ifdef SPI_TFT_DISPLAY
#include "spi_tft.h"

int refreshdisplay = 0;

static String displayLines[7];

MCUFRIEND_kbv display;

void initDisplay() {
  uint16_t ID = display.readID();
  // If the shield returns 0xD3D3, 0xD3, or fails to read ID, 0x9486 is the standard 3.5" 480x320 controller
  if (ID == 0xD3D3 || ID == 0x00D3 || ID == 0x0000 || ID == 0xFFFF) {
    ID = 0x9486;
  }
  display.begin(ID);
  display.setRotation(1); // Landscape: 480x320
  display.fillScreen(BLACK);
  lcdTestPattern();
  delay(500);
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(2);
  display.fillScreen(BLACK);
}

void clearDisplay() {
  display.fillScreen(BLACK);
  for (int i = 0; i < 7; i++) {
    displayLines[i] = "";
  }
  refreshdisplay = 1;
}

void writeText(int line, String text) {
  if (line >= 1 && line <= 7) {
    displayLines[line - 1] = text;
    refreshdisplay = 1;
  }
}

void updateDisplay() {
  if (!refreshdisplay) {
    return;
  }

  display.setTextColor(WHITE, BLACK);
  display.setTextSize(2);

  for (int i = 0; i < 7; i++) {
    display.setCursor(10, i * 22 + 10);
    display.print(displayLines[i]);

    // Overwrite trailing characters if new string is shorter than previous.
    // At text size 2 (12 px per char), 480 px width fits ~38 characters.
    int remaining = 38 - displayLines[i].length();
    while (remaining-- > 0) {
      display.print(' ');
    }
  }

  refreshdisplay = 0;
}

void drawBatteryLine(int battery, int voltage) {
  if (battery < 0 || battery >= CELLGROUPS) {
    return;
  }

  int col = (battery > 11) ? 1 : 0;
  int labelX = (col == 1) ? 245 : 10;
  int barX = (col == 1) ? 275 : 40;
  int y = 160 + (11 * (battery % 12));

  // Cell index label
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(labelX, y);
  if (battery < 10) display.print(' ');
  display.print(battery);
  display.print(':');

  // Background empty bar (RED) - 190px wide
  display.fillRect(barX, y, 190, 8, RED);

  if (voltage > 460 || voltage < 320) {
    display.fillRect(barX, y, 190, 8, MAGENTA);
  } else {
    // Scale voltage 320-460 across 190 pixels: 190 / 140 = ~1.357 px per step
    int barWidth = (int)(1.357 * (voltage - 320));
    if (barWidth > 190) {
      barWidth = 190;
    }
    if (barWidth > 0) {
      display.fillRect(barX, y, barWidth, 8, GREEN);
    }
  }
}

void lcdTestPattern() {
  const uint16_t colors[] = {BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE};
  int w = display.width();
  int h = display.height();
  int barWidth = w / 8;
  for (uint8_t i = 0; i < 8; i++) {
    display.fillRect(i * barWidth, 0, barWidth, h, colors[i]);
  }
}

#endif
