#ifndef ARDUINO_CONNECT
#define ARDUINO_CONNECT

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

class ArduinoConnect
{
  private:
    int arduino_fd;
    struct termios arduino_toptions;

  public:
    ArduinoConnect(char *port = "/dev/ttyUSB0");
    ~ArduinoConnect();
    int sendData(const void *data, int size_data);
    int readData(void *buffer, int buffer_size);
    int closeConnection();

  private:
    void boot();
};

#endif