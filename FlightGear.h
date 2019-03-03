#ifndef FLIGHT_GEAR
#define FLIGHT_GEAR

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "UDPConnect.h"

// FGFS_Data makes the exchange of binary data
// between the client and FlightGear very easy
typedef struct
{
    int magnetos = 0;
    double mixture = 0.0;
    double throttle = 0.0;
    double aileron = 0.0;
    double elevator = 0.0;
    double rudder = 0.0;
} FGFS_Data;

class FlightGear
{
  private:
    FGFS_Data controls;
    UDPConnect *udp_connect;

  public:
    FlightGear(int port, char *addr = "127.0.0.1");
    ~FlightGear();
    FlightGear *setAlieron(double aileron);
    FlightGear *setElevator(double elevator);
    FlightGear *setRudder(double rudder);
    FlightGear *setThrottle(double throttle);
    FlightGear *setMixture(double mixture);
    FlightGear *setMagnetos(int magnetos);
    FlightGear *setFullData(FGFS_Data fullData);
    FlightGear *resetData();
    FGFS_Data getData();
    int send();
};

#endif
