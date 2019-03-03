serial: serial.cpp
	g++ serial.cpp FlightGear.cpp ArduinoConnect.cpp FlightGear.h ArduinoConnect.h UDPConnect.cpp UDPConnect.h -o serial

client: client.cpp
	g++ client.cpp FlightGear.cpp ArduinoConnect.cpp FlightGear.h ArduinoConnect.h UDPConnect.cpp UDPConnect.h -o client

copy-protocol:
	cp binary-protocol.xml /usr/share/games/flightgear/Protocol
