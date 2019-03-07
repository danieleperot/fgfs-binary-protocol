// Define what Arduino has to send to FlightGear
typedef struct {
    float mixture = 0.0;
    float throttle = 0.0;
    float aileron = 0.0;
    float elevator = 0.0;
    float rudder = 0.0;
    // I decided to use long instead of int
    // Because long is 4byte and it makes it
    // easier to avoid padding problems
    long magnetos = 0;
    bool starter = false;
} FGFS_Data;

FGFS_Data flightData;

// Initialize the correct I/O PINs
int aileronPin = A0;
int elevatorPin = A1;
int rudderPin = A2;
int mixturePin = A3;
int throttlePin = A4;
int starterPin = 2;

// This little function makes it a bit easier to map float values
float mapFloat(int initial, int from_low, int from_high, int to_low, int to_high)
{
    return (float) map(initial, from_low, from_high, to_low * 1000, to_high * 1000) / 1000;
}

void setup()
{
    // Initialize Serial communication
   Serial.begin(9600);
    // Send a byte as to say that the communication has started
    /* Serial.write(0x01); */
    // Flush all the Serial output
    /* Serial.flush(); */
    Serial.println(sizeof(float));
    Serial.println(sizeof(long));
    Serial.println(sizeof(bool));
    Serial.println(sizeof(FGFS_Data));
}

void loop()
{
    // Send data only when it is asked to
    if (Serial.available() > 0)
    {   
        // Determine starter condition
        if (digitalRead(starterPin))
        {
            flightData.starter = true;
            flightData.magnetos = 4;
        }
        else
        {
            flightData.starter = false;
            flightData.magnetos = 3;
        }
        
        // Map all the I/Os to their right properties
        flightData.aileron = mapFloat(analogRead(aileronPin), 0, 1024, -1, 1);
        flightData.elevator = mapFloat(analogRead(elevatorPin), 0, 1024, -1, 1);
        flightData.rudder = mapFloat(analogRead(rudderPin), 0, 1024, -1, 1);
        flightData.mixture = mapFloat(analogRead(mixturePin), 0, 1024, 0, 1);
        flightData.throttle = mapFloat(analogRead(throttlePin), 0, 1024, 0, 1);

        // Send data
        Serial.write((uint8_t *)&flightData, sizeof(flightData));
        Serial.read();
    }
}