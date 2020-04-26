#include "signal.h"

Signal::Signal(uint8_t addr) :
    _sensor(LOW),
    _hardware(addr),
    _stop(HIGH),
    _lightState(RED)
{
}

void Signal::begin() {
    _hardware.pinMode(P0, INPUT);
    _hardware.pinMode(P4, OUTPUT);
    _hardware.pinMode(P5, OUTPUT);
    _hardware.pinMode(P6, OUTPUT);
    _hardware.pinMode(P7, OUTPUT);
    _hardware.begin();
    flush();
}

void Signal::refresh() {
    _sensor = static_cast<PinStatus>(_hardware.digitalRead(P0));
}

void Signal::flush(){
    _hardware.digitalWrite(RED, LOW);
    _hardware.digitalWrite(YELLOW, LOW);
    _hardware.digitalWrite(GREEN, LOW);
    _hardware.digitalWrite(_lightState, HIGH);
    _hardware.digitalWrite(STOP_PIN, _stop);
}

bool Signal::isBlocked() {
    return _sensor == HIGH;
}

void Signal::block() {
    _lightState = RED;
    _stop = HIGH;
    flush();
}

void Signal::release() {
    if(_lightState == RED){
        _lightState = YELLOW;
        _stop = LOW;
    } else if (_lightState == YELLOW) {
        _lightState = GREEN;
    }
    flush();
}