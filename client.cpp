#include "FlightGear.h"

#include <iostream>

using namespace std;

int main()
{
    // Initialize a new FlightGear instance
    // It will take care of sending the right
    // data to FlighGear through UDP
    FlightGear *flightgear = new FlightGear(10540);

    char choice = '.';
    int intval;
    double doubleval;

    // Just a simple CLI prompt ;)
    while (true)
    {
        cout << "\n[a]ileron\n[e]levator\n[r]udder\n[t]hrottle\n[m]agnetos\nmi[x]ture\n[0] reset\n[q]uit\nChoose an option:\t";
        cin >> choice;

        // I would really love to find a way to make this code
        // less redundant. But without Switch - Case.
        if (choice == 'a')
        {
            cout << "Aileron (-1.0 to +1.0):\t";
            cin >> doubleval;
            flightgear->setAlieron(doubleval)->send();
        }
        if (choice == 'e')
        {
            cout << "Elevator (-1.0 to +1.0):\t";
            cin >> doubleval;
            flightgear->setElevator(doubleval)->send();
        }
        if (choice == 'r')
        {
            cout << "Rudder (-1.0 to +1.0):\t";
            cin >> doubleval;
            flightgear->setRudder(doubleval)->send();
        }
        if (choice == 't')
        {
            cout << "Throttle (0.0 to +1.0):\t";
            cin >> doubleval;
            flightgear->setThrottle(doubleval)->send();
        }
        if (choice == 'x')
        {
            cout << "Mixture (0.0 to 1.0):\t";
            cin >> doubleval;
            flightgear->setMixture(doubleval)->send();
        }
        if (choice == 'm')
        {
            cout << "Magnetos (0 to 4):\t";
            cin >> intval;
            flightgear->setMagnetos(intval)->send();
        }
        if (choice == '0')
        {
            cout << "Reset...\n";
            flightgear->resetData()->send();
        }
        if (choice == 'q')
        {
            exit(0);
        }
        else
        {
            cout << "Option not available\n";
        }
    }

    return 0;
}
