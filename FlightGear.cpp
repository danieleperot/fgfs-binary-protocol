#include "FlightGear.h"

FlightGear::FlightGear(int port, char* addr) {
    this->udp_connect = new UDPConnect(addr, port);
    this->resetData();
}
FlightGear::~FlightGear() {}
FlightGear* FlightGear::setAlieron(double aileron) {
    this->controls.aileron = aileron;
    return this;
}
FlightGear* FlightGear::setElevator(double elevator) {
    this->controls.elevator = elevator;
    return this;
}
FlightGear* FlightGear::setRudder(double rudder) {
    this->controls.rudder = rudder;
    return this;
}
FlightGear* FlightGear::setThrottle(double throttle) {
    this->controls.throttle = throttle;
    return this;
}
FlightGear* FlightGear::setMixture(double mixture) {
    this->controls.mixture = mixture;
    return this;
}
FlightGear* FlightGear::setMagnetos(int magnetos) {
    this->controls.magnetos = magnetos;
    return this;
}
FlightGear* FlightGear::resetData() {
    this->controls.aileron = 0.0;
    this->controls.elevator = 0.0;
    this->controls.rudder = 0.0;
    this->controls.throttle = 0.0;
    this->controls.mixture = 0.0;
    this->controls.magnetos = 0;
}
FGFS_Data FlightGear::getData() {
    return this->controls;
}
int FlightGear::send() {
    return this->udp_connect->send(&this->controls, sizeof(this->controls));
}