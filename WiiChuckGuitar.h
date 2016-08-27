#ifndef WiiChuckGuitar_h
#define WiiChuckGuitar_h
#include "Wire.h"
#include "Arduino.h"

class WiiChuckGuitar{
    public:
        uint8_t AnalogX;
        uint8_t AnalogY;
        uint8_t TouchBar;
        uint8_t WhammyBar;
        uint8_t Plus;
        uint8_t Minus;
        uint8_t Down;
        uint8_t Up;
        uint8_t Yellow;
        uint8_t Green;
        uint8_t Blue;
        uint8_t Red;
        uint8_t Orange;
        void begin();
        void poll();
    private:
        uint8_t data[6];
        uint8_t decode(uint8_t b);
        void parse(uint8_t data[]);
};
#endif
