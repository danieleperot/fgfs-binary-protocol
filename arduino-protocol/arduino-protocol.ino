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
        Serial.write((uint8_t *)&flightData, sizeof(flightData));
        // Serial.flush();
        Serial.read();
    }
}