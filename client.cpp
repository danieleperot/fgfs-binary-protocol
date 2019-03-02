#include "UDPConnect.h"
#include "FlightGear.h"

#include <iostream>

using namespace std;

int main() {
    FlightGear* flightgear = new FlightGear(10540);

    char choice = '.';
    int intval;
    double doubleval;

    UDPConnect* udp_con = new UDPConnect("127.0.0.1", 10540);

    while (true) {
        cout << "\n[a]ileron\n[e]levator\n[r]udder\n[t]hrottle\n[m]agnetos\nmi[x]ture\n[s]end\n[0] reset\n[q]uit\nInserisci un dato:\t";
        cin >> choice;

        if (choice == 'a') {
            cout << "Valore aileron:\t";
            cin >> doubleval;
            // udp_con->send(&doubleval, sizeof(doubleval));
            flightgear->setAlieron(doubleval)->send();
        }
        if (choice == 'e') {
            cout << "Valore elevator:\t";
            cin >> doubleval;
            flightgear->setElevator(doubleval)->send();
        }
        if (choice == 'r') {
            cout << "Valore rudder:\t";
            cin >> doubleval;
            flightgear->setRudder(doubleval)->send();
        }
        if (choice == 't') {
            cout << "Valore throttle:\t";
            cin >> doubleval;
            flightgear->setThrottle(doubleval)->send();
        }
        if (choice == 'x') {
            cout << "Valore mixture:\t";
            cin >> doubleval;
            flightgear->setMixture(doubleval)->send();
        }
        if (choice == 'm') {
            cout << "Valore magnetos:\t";
            cin >> intval;
            flightgear->setMagnetos(intval)->send();
        }
        if (choice == 's') {
            cout << "Invio in corso...\n";
            flightgear->send();
        }
        if (choice == '0') {
            cout << "Reset in corso...\n";
            flightgear->resetData()->send();
        }
        if (choice == 'q') {
            exit(0);
        }
    }

    return 0; 
}
