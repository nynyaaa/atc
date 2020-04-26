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

    delay(1500);

    for(int i = 0; i < MAX_SIGNAL; i++){
        signals[i].release();
        signals[i].release();
    }
}

void loop()
{

    for(int i = 0; i < MAX_SIGNAL; i++){
        signals[i].refresh();
        int prev = i -1;
        if(prev < 0) {
            prev += MAX_SIGNAL;
        }
        if(signals[i].isBlocked()){
            signals[prev].block();
        } else {
            signals[prev].release();
        }
    }

}