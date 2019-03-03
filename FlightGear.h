#ifndef FLIGHT_GEAR
#define FLIGHT_GEAR

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "UDPConnect.h"

// FGFS_Data makes the exchange of binary data
// between the client and FlightGear very easy
typedef struct {
    int magnetos = 0;
    float mixture = 0.0;
    float throttle = 0.0;
    float aileron = 0.0;
    float elevator = 0.0;
    float rudder = 0.0;
} FGFS_Data;

class FlightGear {
    private:
        FGFS_Data controls;
        UDPConnect* udp_connect;
    public:
        FlightGear(int port, char* addr = "127.0.0.1");
        ~FlightGear();
        FlightGear* setAlieron(float aileron);
        FlightGear* setElevator(float elevator);
        FlightGear* setRudder(float rudder);
        FlightGear* setThrottle(float throttle);
        FlightGear* setMixture(float mixture);
        FlightGear* setMagnetos(int magnetos);
        FlightGear* resetData();
        FGFS_Data getData();
        int send();
};

#endif