#include "mock_serial.hpp"

SerialPipe::SerialPipe() {
  masterfd = ::open("/dev/ptmx", O_RDWR | O_NOCTTY);
  // masterfd = ::open("/dev/ptmx", O_RDWR | O_NOCTTY | O_NONBLOCK);

  grantpt(masterfd);
  unlockpt(masterfd);
  char* slavename = ptsname(masterfd);

  slavefd = ::open(slavename, O_RDWR | O_NOCTTY);
  // slavefd = ::open(slavename, O_RDWR | O_NOCTTY | O_NONBLOCK);

  // fixes slave write, master read issue -----
  // https://stackoverflow.com/questions/23459520/how-to-read-write-
  //   to-linux-pseudoterminals-using-separate-processes-but-without
  struct termios ts;
  if(tcgetattr(slavefd, &ts)) {
    perror("tcgetattr");
    exit(1);
  }
  cfmakeraw(&ts);
  tcsetattr (slavefd, TCSANOW, &ts);

  // cout << "master " << masterfd << endl;
  // cout << "slave " << ttyname(slavefd) << " " << slavefd << endl;
}

SerialPipe::~SerialPipe() {
  close(masterfd);
  close(slavefd);
}