#include <Ps3Controller.h>

bool stateIsConnected = false;

void notify()
{
    if( Ps3.data.button.cross ){
        Serial.println("Pressing the cross button");
    }

    if( Ps3.data.button.square ){
        Serial.println("Pressing the square button");
    }

    if( Ps3.data.button.triangle ){
        Serial.println("Pressing the triangle button");
    }

    if( Ps3.data.button.circle ){
        Serial.println("Pressing the circle button");
    }
}

void setup()
{
    Serial.begin(115200);
    Ps3.attach(notify);
    Ps3.begin("01:02:03:04:05:06");
    Serial.println("Ready.");
}

void loop()
{
    if(stateIsConnected == false){
        if (Ps3.isConnected()){
            delay(250);    // ToDo: the ps3 library should handle this delay
            Ps3.setLed(1); // ToDo: the ps3 library should set LED 1 on connect by default
            stateIsConnected = true;
        }
    }
}
