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

// These following methods just set the values of the struct
// I like to return the instance of the class as i like
// to concatenate methods.
// I would want to improve the code by finding a wait to not
// repeat all of these functions and make it easier to just
// add a new property in the protocol
FlightGear *FlightGear::setAlieron(double aileron)
{
    this->controls.aileron = aileron;
    return this;
}

FlightGear *FlightGear::setElevator(double elevator)
{
    this->controls.elevator = elevator;
    return this;
}

FlightGear *FlightGear::setRudder(double rudder)
{
    this->controls.rudder = rudder;
    return this;
}

FlightGear *FlightGear::setThrottle(double throttle)
{
    this->controls.throttle = throttle;
    return this;
}

FlightGear *FlightGear::setMixture(double mixture)
{
    this->controls.mixture = mixture;
    return this;
}

FlightGear *FlightGear::setMagnetos(int magnetos)
{
    this->controls.magnetos = magnetos;
    return this;
}

FlightGear *FlightGear::setStarter(bool starter)
{
    this->controls.starter = starter;
    return this;
}

FlightGear *FlightGear::setFullData(FGFS_Data fullData)
{
    this->controls = fullData;
    return this;
}

// Set all the values of the struct to 0
// and return the class instance
FlightGear *FlightGear::resetData()
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
