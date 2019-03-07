#include "FlightGear.h"

// Create a new UDPConnect instance
// and reset FGFS_Data to 0
FlightGear::FlightGear(int port, char *addr)
{
    this->udp_connect = new UDPConnect(addr, port);
    this->resetData();
}

// Close the UDP connection on destroy
FlightGear::~FlightGear()
{
    this->udp_connect->closeStream();
}

void FlightGear::setFullData(FGFS_Data *fullData)
{
    this->controls = *fullData;
}

// Set all the values of the struct to 0
// and return the class instance
void FlightGear::resetData()
{
    this->controls.aileron = 0.0;
    this->controls.elevator = 0.0;
    this->controls.rudder = 0.0;
    this->controls.throttle = 0.0;
    this->controls.mixture = 0.0;
    this->controls.magnetos = 0;
    this->controls.starter = false;
}

// Return FGFS_Data for debug purposes
FGFS_Data FlightGear::getData()
{
    return this->controls;
}

// Send FGFS_Data through a UDPConnect instance
int FlightGear::send()
{
    return this->udp_connect->send(&this->controls, sizeof(this->controls));
}
