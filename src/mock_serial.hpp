/**************************************************\
* The MIT License (MIT)
* Copyright (c) 2019 The Guild of Calamitous Intent
* see LICENSE for full details
\**************************************************/
#pragma once

#include <stdlib.h>
#include <fcntl.h> // open
#include <unistd.h> // close
#if defined(__APPLE__)
#include <util.h>
#elif defined(linux)
#include <pty.h>
#endif

/*
(py)  kevin@Logan ~ % stty -f /dev/ttys006
speed 9600 baud;
lflags: echoe echoke echoctl
oflags: -oxtabs
cflags: cs8 -parenb

(py)  kevin@Logan ~ % stty -f /dev/ttys006
speed 9600 baud;
lflags: -icanon -isig -iexten -echo echoke echoctl
iflags: -icrnl -ixon -imaxbel ignbrk -brkint
oflags: -opost -oxtabs
cflags: cs8 -parenb
*/

class SerialPipe {
  public:
  SerialPipe();
  ~SerialPipe();

  int masterfd;
  int slavefd;
};