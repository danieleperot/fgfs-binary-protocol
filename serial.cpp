#include "ArduinoConnect.h"
#include "FlightGear.h"

int main()
{
    unsigned int n;
    char buf[6], key;
    FGFS_Data fromArduino;
    ArduinoConnect *arduino = new ArduinoConnect();
    FlightGear *flightgear = new FlightGear(10540);

    while (true)
    {
        usleep(100000);

        arduino->sendData("0", 1);
        n = arduino->readData(&fromArduino, sizeof(fromArduino));
        flightgear->setFullData(fromArduino)->send();
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
