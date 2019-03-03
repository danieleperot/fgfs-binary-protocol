typedef struct {
    int magnetos = 0;
    const int first_int_for_padding = 0;
    float mixture = 0.0;
    float throttle = 0.0;
    float aileron = 0.0;
    float elevator = 0.0;
    float rudder = 0.0;
} FGFS_Data;

FGFS_Data flightData;

int aileronPin = A0;
int elevatorPin = A1;
int rudderPin = A2;
int mixturePin = A3;
int throttlePin = A4;
int starterPin = 2;

float mapFloat(int initial, int from_low, int from_high, int to_low, int to_high)
{
    return (float) map(initial, from_low, from_high, to_low * 1000, to_high * 1000) / 1000;
}

void setup()
{
    Serial.begin(9600);
    Serial.write(0x01);
    Serial.flush();
    flightData.magnetos = 3;
    flightData.mixture = 0.8;
    flightData.throttle = 0.3;
    flightData.aileron = 1;
    flightData.elevator = -1;
    flightData.rudder = 0.5;
}

void loop()
{
    if (Serial.available() > 0)
    {
        if (digitalRead(starterPin))
            flightData.magnetos = 4;
        else
            flightData.magnetos = 3;
        
        flightData.aileron = mapFloat(analogRead(aileronPin), 0, 1024, -1, 1);
        flightData.elevator = mapFloat(analogRead(elevatorPin), 0, 1024, -1, 1);
        flightData.rudder = mapFloat(analogRead(rudderPin), 0, 1024, -1, 1);
        flightData.mixture = mapFloat(analogRead(mixturePin), 0, 1024, 0, 1);
        flightData.throttle = mapFloat(analogRead(throttlePin), 0, 1024, 0, 1);
        Serial.write((uint8_t *)&flightData, sizeof(flightData));
        // Serial.flush();
        Serial.read();
    }
}