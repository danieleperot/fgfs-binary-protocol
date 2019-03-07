#include "FlightGear.h"

#include <iostream>

using namespace std;

int main()
{
    // Initialize a new FlightGear instance
    // It will take care of sending the right
    // data to FlighGear through UDP
    FlightGear *flightgear = new FlightGear(10540);

    FGFS_Data cli_data;

    char choice = '.';
    int intval;
    double doubleval;
    bool boolval;

    // Just a simple CLI prompt ;)
    while (true)
    {
        cout << "\n[a]ileron\n[e]levator\n[r]udder\n[t]hrottle\n[m]agnetos\nmi[x]ture\n[s]tarter\n[0] reset\n[q]uit\nChoose an option:\t";
        cin >> choice;

        // I would really love to find a way to make this code
        // less redundant. But without Switch - Case.
        if (choice == 'a')
        {
            cout << "Aileron (-1.0 to +1.0):\t";
            cin >> cli_data.aileron;
        }
        if (choice == 'e')
        {
            cout << "Elevator (-1.0 to +1.0):\t";
            cin >> cli_data.elevator;
        }
        if (choice == 'r')
        {
            cout << "Rudder (-1.0 to +1.0):\t";
            cin >> cli_data.rudder;
        }
        if (choice == 't')
        {
            cout << "Throttle (0.0 to +1.0):\t";
            cin >> cli_data.throttle;
        }
        if (choice == 'x')
        {
            cout << "Mixture (0.0 to 1.0):\t";
            cin >> cli_data.mixture;
        }
        if (choice == 'm')
        {
            cout << "Magnetos (0 to 4):\t";
            cin >> cli_data.magnetos;
        }
        if (choice == 's')
        {
            cout << "Starter (0 = false, 1 = true):\t";
            cin >> cli_data.starter;
        }
        if (choice == '0')
        {
            cout << "Reset...\n";
            flightgear->resetData();
        }
        if (choice == 'q')
        {
            exit(0);
        }

        flightgear->setFullData(&cli_data);
        flightgear->send();
    }

    return 0;
}
