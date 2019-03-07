#include "ArduinoConnect.h"
#include "FlightGear.h"
#include <iostream>

// I had to create this struct with float values
// becuase I currently have some problems with
// sending double data from Arduino
typedef struct {
    float mixture = 0.0;
    float throttle = 0.0;
    float aileron = 0.0;
    float elevator = 0.0;
    float rudder = 0.0;
    int magnetos = 0;
    bool starter = false;
} ARDUINO_Data;

int main()
{
    unsigned int n;
    ARDUINO_Data fromArduino;
    FGFS_Data convertData;
    // Connect to Arduino (default port is /dev/ttyUSB0
    // but you can just add the port name to the constructor)"
    ArduinoConnect *arduino = new ArduinoConnect();
    // Initialize FlightGear connection
    FlightGear *flightgear = new FlightGear(10540);

    while (true)
    {
        // Send a byte to Arduino to tell it to send back data
        arduino->sendData("0", 1);

        // Read data from Arduino
        arduino->readData(&fromArduino, sizeof(fromArduino));

        // Convert float values to double
        convertData.aileron = (double) fromArduino.aileron;
        convertData.elevator = (double) fromArduino.elevator;
        convertData.rudder = (double) fromArduino.rudder;
        convertData.mixture = (double) fromArduino.mixture;
        convertData.throttle = (double) fromArduino.throttle;
        convertData.magnetos = fromArduino.magnetos;
        convertData.starter = fromArduino.starter;

        // Send data to FlightGear
        flightgear->setFullData(convertData)->send();

        // Print the values
        printf(
            "Aileron: %f, Elevator: %f, Rudder: %f, Mixture: %f, Throttle: %f, Magnetos: %d, Starter: %d\n",
            fromArduino.aileron,
            fromArduino.elevator,
            fromArduino.rudder,
            fromArduino.mixture,
            fromArduino.throttle,
            fromArduino.magnetos,
            fromArduino.starter
        );
    }

    return 0;
}
