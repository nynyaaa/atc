#ifndef SIGNAL_h
#define SGINAL_h

#include "PCF8574.h"

#define STOP_PIN P4

enum LightState {
    RED = P7,
    YELLOW = P6,
    GREEN = P5
};

class Signal {
    private:
        LightState _lightState;
        PinStatus _stop;
        PinStatus _sensor;
        PCF8574 _hardware;
    public:
        Signal(uint8_t addr);
        void begin();
        void refresh();
        void flush();

        bool isBlocked();
        void block();
        void release();
};

#endif