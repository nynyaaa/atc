/*
Mini Auto Train Control Blocking signal scheduling
*/

#include "Arduino.h"
#include "signal.h"

Signal signals[] = { Signal(0x20) , Signal(0x21), Signal(0x22), Signal(0x23) };
const int MAX_SIGNAL = 4;

void setup()
{
	Serial.begin(115200);
    for(int i = 0; i < MAX_SIGNAL; i++){
        signals[i].begin();
    }
}

void loop()
{
    delay(500);
    for(int i = 0; i < MAX_SIGNAL; i++){
        signals[i].release();
    }
    /*
    delay(500);
    for(int i = 0; i < MAX_SIGNAL; i++){
        signals[i].block();
    }
    */

    delay(1500);

    for(int i = 0; i < MAX_SIGNAL; i++){
        signals[i].block();
        if( i > 0)
            signals[i-1].release();
        delay(500);
    }
    signals[MAX_SIGNAL-1].release();
}