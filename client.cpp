#include "UDPConnect.h"

using namespace std;
typedef struct {
    int magnetos = 0;
    double mixture = 0.0;
    double throttle = 0.0;
    double aileron = 0.0;
    double elevator = 0.0;
    double rudder = 0.0;
} FGFS_Data;

int main() {
    UDPConnect* udp_connection = new UDPConnect("127.0.0.1", 2115);
    FGFS_Data test_data;

    test_data.magnetos = 1;
    test_data.aileron = 0.01;
    udp_connection->send(&test_data, sizeof(test_data));

    cout << sizeof(test_data) << "\n";

    return 0; 
}
