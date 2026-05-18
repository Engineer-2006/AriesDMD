#pragma once
#include <Arduino.h>

class AriesRGBFont {
public:
    AriesRGBFont(const uint8_t* f = NULL);

    void setFont(const uint8_t* f);

    bool isCharValid(char c);
    uint8_t getCharWidth(char c);
    uint8_t getHeight();

    uint8_t getColumn(char c, uint8_t col);

private:
    const uint8_t* font;

    uint8_t firstChar;
    uint8_t charCount;
    uint8_t fontHeight;
};
