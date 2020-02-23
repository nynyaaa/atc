#include "signal.h"

Signal::Signal(uint8_t addr) :
    _hardware(addr),
    _lightState(RED)
{
}

void Signal::begin() {
    _hardware.pinMode(P5, OUTPUT);
    _hardware.pinMode(P6, OUTPUT);
    _hardware.pinMode(P7, OUTPUT);
    _hardware.begin();
    flush();
}

void Signal::flush(){
    _hardware.digitalWrite(RED, LOW);
    _hardware.digitalWrite(YELLOW, LOW);
    _hardware.digitalWrite(GREEN, LOW);
    _hardware.digitalWrite(_lightState, HIGH);
}

void Signal::block() {
    _lightState = RED;
    flush();
}

void Signal::release() {
    _lightState = GREEN;
    flush();
}