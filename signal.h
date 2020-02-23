#ifndef SIGNAL_h
#define SGINAL_h

#include "PCF8574.h"

enum LightState {
    RED = P7,
    YELLOW = P6,
    GREEN = P5
};

class Signal {
    private:
        LightState _lightState;
        PCF8574 _hardware;
    public:
        Signal(uint8_t addr);
        void begin();
        void refresh();
        void flush();

        void block();
        void release();
};

#endif