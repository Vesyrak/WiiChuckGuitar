#include "Arduino.h"
#include "Wire.h"
#include "WiiChuckGuitar.h"

void WiiChuckGuitar::begin(){
    delay(100);
    Wire.begin();
    Wire.beginTransmission(0x52);
    Wire.write(0x40);
    Wire.write(0x00);
    Wire.endTransmission();
}

uint8_t WiiChuckGuitar::decode(uint8_t b){
    return (b^0x17)+0x17;
}

void WiiChuckGuitar::poll(){
    Wire.requestFrom(0x52,6);
    uint8_t x=0;
    while(Wire.available())
    {
        data[x++] = decode(Wire.read());
    }
    parse(data);
    Wire.beginTransmission(0x52);
    Wire.write(0x00);
    Wire.endTransmission();
}

void WiiChuckGuitar::parse(uint8_t data[]){
    AnalogX=data[0];
    AnalogY=data[1];
    TouchBar=data[2];
    WhammyBar=data[3];
    Plus=!((data[4]>>2)&1);
    Minus=!((data[4]>>4)&1);
    Down=!((data[4]>>6)&1);
    Up=!((data[5]>>0)&1);
    Yellow=!((data[5]>>3)&1);
    Green=!((data[5]>>4)&1);
    Blue=!((data[5]>>5)&1);
    Red=!((data[5]>>6)&1);
    Orange=!((data[5]>>7)&1);
}
