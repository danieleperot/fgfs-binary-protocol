#include "UDPConnect.h"
#include "FlightGear.h"

#include <iostream>

int main() {
    FlightGear* flightgear = new FlightGear(2115);

    flightgear->setMagnetos(1)->send();

    return 0; 
}
