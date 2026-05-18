#include "AriesRGBFont.h"

#define FONT_FIRST_CHAR 4
#define FONT_CHAR_COUNT 5
#define FONT_HEIGHT 3
#define FONT_WIDTH 2
#define FONT_WIDTH_TABLE 6

AriesRGBFont::AriesRGBFont(const uint8_t* f) {
    setFont(f);
}

void AriesRGBFont::setFont(const uint8_t* f) {
    font = f;
    if (!font) return;

    firstChar = pgm_read_byte(font + FONT_FIRST_CHAR);
    charCount = pgm_read_byte(font + FONT_CHAR_COUNT);
    fontHeight = pgm_read_byte(font + FONT_HEIGHT);
}

bool AriesRGBFont::isCharValid(char c) {
    return (c >= firstChar && c < firstChar + charCount);
}

uint8_t AriesRGBFont::getHeight() {
    return fontHeight;
}

uint8_t AriesRGBFont::getCharWidth(char c) {
    uint8_t index = c - firstChar;
    return pgm_read_byte(font + FONT_WIDTH_TABLE + index);
}

uint8_t AriesRGBFont::getColumn(char c, uint8_t col) {
    uint8_t index = c - firstChar;

    uint16_t offset = 0;
    for (uint8_t i = 0; i < index; i++) {
        offset += getCharWidth(firstChar + i);
    }

    uint16_t bytesPerChar = (fontHeight + 7) / 8;

    return pgm_read_byte(
        font + FONT_WIDTH_TABLE + charCount + (offset * bytesPerChar) + col
    );
}