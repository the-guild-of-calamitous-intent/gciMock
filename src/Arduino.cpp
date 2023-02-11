#include "Arduino.h"


#include <algorithm> // min, max
#include <stdlib.h>  // rand, srand
#include <unistd.h>  // usleep
#include <time.h>    // time, clock_gettime
#include <sys/time.h> // gettimeofday

// error: C++ requires a type specifier for all declarations gettimeofday(&epoch, NULL);
// I seem to HAVE TO get the return value ... wtf?
// static struct timeval epoch;
// int s = gettimeofday(&epoch, NULL); // when program starts
static struct timespec epoch;
int s = clock_gettime(CLOCK_MONOTONIC_RAW, &epoch);

uint32_t micros(void) {
  // struct timeval now;
  // gettimeofday(&now, NULL);
  // return uint32_t((now.tv_sec - epoch.tv_sec) * 1e6 + (now.tv_usec - epoch.tv_usec) );

  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC_RAW, &now);
  return uint32_t((now.tv_sec - epoch.tv_sec) * 1e6 + (now.tv_nsec - epoch.tv_nsec) * 1e-3);
}

uint32_t millis(void) {return uint32_t(micros() * 1e-3);}


void delay(uint32_t ms) { usleep(1000 * ms); }
void delayMicroseconds(uint32_t us) { usleep(us); }
int constrain(int x, int a, int b) { return std::min(b, std::max(x,a)); }

int32_t random(int32_t min, int32_t max) {
  return rand() % (max - min) + min;
}
int32_t random(int32_t max){ return random(0, max); }
void randomSeed(uint32_t seed) { srand(seed); }


SerialPort Serial;
SerialPort Serial1;
SerialPort Serial2;