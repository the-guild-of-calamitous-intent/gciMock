
#pragma once

#if defined(linux) || defined(__APPLE__)
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#endif

struct Stream {
  void begin(int r) {}
  void print(string a) { cout << a; }
  void print(float a, int v = 0) { cout << a; }
  void println(float a, int v = 0) { cout << a << endl; }
  void println(string a) { cout << a << endl; }
  void setTimeout(int) {}
  int available() { return 1; }
  int peak() { return 100; }
  int read() { return 100; }
  string readString() { return "dummy"; }
  int readBytes(uint8_t *buf, int size) { return size; };
  int write(uint8_t *, int size) { return size; }
  int write(uint8_t) { return 1; }
  int write(const string& s) { return s.length(); }

  // this isn't real, so always return "true"
  inline explicit operator bool() const noexcept { return true; }
};

struct SerialPort : Stream {};