

#pragma once

class Servo {
  public:
  Servo() {}
  ~Servo() {}

  void attach(int pin, int min=0, int max=180) {}
  void write(int angle) {}
  void writeMicroseconds(int us) {}
  int read() { return 0; }
  bool attached() { return true; }
  void detach() {}
};