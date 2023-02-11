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

// using namespace std;
using std::string;
using std::to_string;
using std::cout;
using std::endl;


static void pinMode(uint8_t pin, uint8_t mode) {}
static void digitalWrite(uint8_t pin, uint8_t val) {}
static int digitalRead(uint8_t pin) {return 0;}
static int analogRead(uint8_t pin) {return 0;}
static void analogReference(uint8_t mode) {}
static void analogWrite(uint8_t pin, int32_t val) {}


/*
sec      1e0
millisec 1e-3
microsec 1e-6
nanosec  1e-9
*/
uint32_t micros(void);
uint32_t millis(void);

void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);
int constrain(int x, int a, int b);

/*
Parameters
min: lower bound of the random value, default 0, inclusive (optional).
max: upper bound of the random value, exclusive.

Returns
A random number between min and max-1. Data type: int32_t.

`random(0,100)` returns [0 - 99]
*/
int32_t random(int32_t min, int32_t max);
int32_t random(int32_t max);
void randomSeed(uint32_t seed);

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

extern SerialPort Serial;
extern SerialPort Serial1;
extern SerialPort Serial2;
