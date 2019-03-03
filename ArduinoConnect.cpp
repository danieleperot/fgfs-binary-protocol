#include "ArduinoConnect.h"

ArduinoConnect::ArduinoConnect(char *port)
{
    this->arduino_fd = open(port, O_RDWR | O_NOCTTY);
    this->boot();
}

ArduinoConnect::~ArduinoConnect()
{
    this->closeConnection();
}

int ArduinoConnect::sendData(const void *data, int size_data)
{
    return write(this->arduino_fd, data, size_data);
}

int ArduinoConnect::readData(void *buffer, int buffer_size)
{
    return read(this->arduino_fd, buffer, buffer_size);
}

int ArduinoConnect::closeConnection()
{
    return close(this->arduino_fd);
}

void ArduinoConnect::boot()
{
    /* get current serial port settings */
    tcgetattr(this->arduino_fd, &this->arduino_toptions);
    /* set 9600 baud both ways */
    cfsetispeed(&this->arduino_toptions, B9600);
    cfsetospeed(&this->arduino_toptions, B9600);
    /* 8 bits, no parity, no stop bits */
    this->arduino_toptions.c_cflag &= ~PARENB;
    this->arduino_toptions.c_cflag &= ~CSTOPB;
    this->arduino_toptions.c_cflag &= ~CSIZE;
    this->arduino_toptions.c_cflag |= CS8;
    /* Canonical mode */
    // this->arduino_toptions.c_lflag |= ICANON;
    /* commit the serial port settings */
    // no flow control
    this->arduino_toptions.c_cflag &= ~CRTSCTS;

    this->arduino_toptions.c_cflag |= CREAD | CLOCAL;          // turn on READ & ignore ctrl lines
    this->arduino_toptions.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl

    this->arduino_toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    this->arduino_toptions.c_oflag &= ~OPOST;                          // make raw

    tcsetattr(this->arduino_fd, TCSANOW, &this->arduino_toptions);
}