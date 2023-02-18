/**************************************************\
* The MIT License (MIT)
* Copyright (c) 2019 The Guild of Calamitous Intent
* see LICENSE for full details
\**************************************************/
#pragma once

// https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h
// https://www.atwillys.de/content/cc-apps/simple-serial-port-communication-program-in-c/?lang=en

#include <stdint.h>  // uint8_t, etc
#include <string>    // string
#include <iostream>  // cout, endl
#include <math.h>    // trig

#include <algorithm> // min, max
#include <stdlib.h>  // rand, srand
#include <unistd.h>  // usleep
#include <time.h>    // time, clock_gettime
#include <sys/time.h> // gettimeofday

// using namespace std;
using std::string;
using std::to_string;
using std::cout;
using std::endl;

/*
struct initialization: https://en.cppreference.com/w/c/language/struct_initialization

c
----------------------
long   8B x86
----------------------
struct timeval {time_t tv_sec, suseconds_t tv_usec}
gettimeofday(timeval&, timezone& or NULL);

struct timespec {time_t tv_sec, long tv_nsec}
clock_gettime(CLOCK_MONOTONIC, timespec&)

time_t not defined by C

- `CLOCK_REALTIME` reports the actual wall clock time.
- `CLOCK_MONOTONIC` is for measuring relative real time. It advances at the same rate
  as the actual flow of time but it's not subject to discontinuities from manual or
  automatic (NTP) adjustments to the system clock.
- `CLOCK_PROCESS_CPUTIME_ID` is for measuring the amount of CPU time consumed by the process.
- `CLOCK_THREAD_CPUTIME_ID` is for measuring the amount of CPU time consumed by the
  thread. It's supported by modern kernels and glibc since 2.6.12, but on older linux
  kernels glibc emulates it badly by simply returning the amount of CPU time consumed
  by the process since the moment the thread was created.

arduino
----------------------
int    4B (SAMD) https://www.arduino.cc/reference/en/language/variables/data-types/int/
long   4B        https://www.arduino.cc/reference/en/language/variables/data-types/long/
float  4B        https://www.arduino.cc/reference/en/language/variables/data-types/float/
double 8B        https://www.arduino.cc/reference/en/language/variables/data-types/double/
----------------------
unsigned long (uint32_t) = millis()
unsigned long (uint32_t) = micros()
----------------------
*/


static void pinMode(uint8_t pin, uint8_t mode) {}
static void digitalWrite(uint8_t pin, uint8_t val) {}
static int digitalRead(uint8_t pin) {return 0;}
static int analogRead(uint8_t pin) {return 0;}
static void analogReference(uint8_t mode) {}
static void analogWrite(uint8_t pin, int32_t val) {}

// error: C++ requires a type specifier for all declarations gettimeofday(&epoch, NULL);
// I seem to HAVE TO get the return value ... wtf?
// static struct timeval epoch;
// int s = gettimeofday(&epoch, NULL); // when program starts
static struct timespec epoch;
int s = clock_gettime(CLOCK_MONOTONIC_RAW, &epoch);

/*
sec      1e0
millisec 1e-3
microsec 1e-6
nanosec  1e-9
*/
// overflow in ~50 days: 2**32 / 1e3 / 3600 / 24 = 49.7
uint32_t micros(void) {
  // struct timeval now;
  // gettimeofday(&now, NULL);
  // return uint32_t((now.tv_sec - epoch.tv_sec) * 1e6 + (now.tv_usec - epoch.tv_usec) );

  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC_RAW, &now);
  return uint32_t((now.tv_sec - epoch.tv_sec) * 1e6 + (now.tv_nsec - epoch.tv_nsec) * 1e-3);
}
// overflow in ~70 mins: 2**32 / 1e6 / 60 = 71.6
uint32_t millis(void) {return uint32_t(micros() * 1e-3);}

void delay(uint32_t ms) { usleep(1000 * ms); }
void delayMicroseconds(uint32_t us) { usleep(us); }
int constrain(int x, int a, int b) { return std::min(b, std::max(x,a)); }

/*
Parameters
min: lower bound of the random value, default 0, inclusive (optional).
max: upper bound of the random value, exclusive.

Returns
A random number between min and max-1. Data type: int32_t.

`random(0,100)` returns [0 - 99]
*/
int32_t random(int32_t min, int32_t max) {
  return rand() % (max - min) + min;
}
int32_t random(int32_t max){ return random(0, max); }
void randomSeed(uint32_t seed) { srand(seed); }


#if 0
struct Stream {
  void begin(int r) {}
  void print(string a) {cout << a;}
  void print(float a, int v=0) {cout << a;}
  void println(float a, int v=0) {cout << a << endl;}
  void println(string a) {cout << a << endl;}
  void setTimeout(int) {}
  int available() { return 1; }
  int read() { return 60; }
  int write(uint8_t*,int sz) { return sz; }
  int write(uint8_t) { return 1; }

  // this isn't real, so always return "true"
  inline explicit operator bool() const noexcept {return true;}
};

struct SerialPort: Stream {
};

// extern SerialPort Serial;
// extern SerialPort Serial1;
// extern SerialPort Serial2;
#endif