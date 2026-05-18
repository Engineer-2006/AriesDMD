#include <AriesRGB.h>
#include "fonts/SystemFont5x7.h"
#include "fonts/Arial14.h"

AriesRGB panel(
    3,4,5, 6,7,8, // R0, G0, B0, R1, G1, B1
    14,15,16,  // CLK, LAT, OE
    10,11,12,13,9,  // A, B, C, D, E
    2,2  // panelsWide, panelsHigh
);

void setup()
{
    panel.begin();
}

void loop()
{
    panel.clear();

    panel.setFont(SystemFont5x7);
    panel.setCursor(0, 0);
    panel.setTextColor(1,0,0);
    panel.setTextSize(1);
    panel.print("HELLO");

    panel.setFont(Arial_14);
    panel.setCursor(0, 20);
    panel.setTextColor(0,1,0);
    panel.print("DMD");

    for(int i=0;i<200;i++)
        panel.refresh();
}
