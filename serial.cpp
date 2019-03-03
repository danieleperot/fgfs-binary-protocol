#include "ArduinoConnect.h"
#include "FlightGear.h"

typedef struct {
    int magnetos = 0;
    float mixture = 0.0;
    float throttle = 0.0;
    float aileron = 0.0;
    float elevator = 0.0;
    float rudder = 0.0;
} ARDUINO_Data;

int main()
{
    unsigned int n;
    char buf[6], key;
    ARDUINO_Data fromArduino;
    FGFS_Data convertData;
    ArduinoConnect *arduino = new ArduinoConnect();
    FlightGear *flightgear = new FlightGear(10540);

    while (true)
    {
        usleep(100000);

        arduino->sendData("0", 1);
        n = arduino->readData(&fromArduino, sizeof(fromArduino));
        convertData.aileron = (double) fromArduino.aileron;
        convertData.elevator = (double) fromArduino.elevator;
        convertData.rudder = (double) fromArduino.rudder;
        convertData.mixture = (double) fromArduino.mixture;
        convertData.throttle = (double) fromArduino.throttle;
        convertData.magnetos = fromArduino.magnetos;
        flightgear->setFullData(convertData)->send();
        printf(
            "Aileron: %f, Elevator: %f, Rudder: %f, Mixture: %f, Throttle: %f, Magnetos: %d\n",
            fromArduino.aileron,
            fromArduino.elevator,
            fromArduino.rudder,
            fromArduino.mixture,
            fromArduino.throttle,
            fromArduino.magnetos
        );
    }

    return 0;
}
