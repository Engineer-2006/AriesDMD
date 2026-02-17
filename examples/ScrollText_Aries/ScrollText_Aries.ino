#include "AriesDMD.h"
#include "AriesFont5x7.h"

AriesDMD dmd(2, 1, 8, 6, 7, 5);   // 2 panels wide

const char text[] = "NISHIL PATEL";
int scrollX;

void setup() {
  dmd.begin();
  scrollX = dmd.width();
}

// Right to Left
/* 
void loop() {
  dmd.scanDisplay();

  static unsigned long lastMove = 0;
  if (millis() - lastMove > 70) {
    lastMove = millis();

    dmd.clearScreen(true);
    AriesDrawString(dmd, scrollX, 4, text);

    scrollX--;
    int textWidth = strlen(text) * (ARIES_FONT_WIDTH + 1);

    if (scrollX < -textWidth) {
      scrollX = dmd.width();
    }
  }
}
*/ 

// Left to Right 
void loop() {
    dmd.scanDisplay();   

    static unsigned long lastMove = 0;
    if (millis() - lastMove > 40) {
        lastMove = millis();

        dmd.clearScreen(true);
        AriesDrawString(dmd, scrollX, 4, text);

        scrollX++;   

        int textWidth = strlen(text) * (ARIES_FONT_WIDTH + 1);
        if (scrollX > dmd.width()) {
            scrollX = -textWidth;   
        }
    }
}
