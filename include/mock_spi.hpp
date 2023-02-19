/**************************************************\
* The MIT License (MIT)
* Copyright (c) 2019 The Guild of Calamitous Intent
* see LICENSE for full details
\**************************************************/
#pragma once

#include <stdint.h>

struct SPISettings {
  SPISettings(int a, int b, int c) {
    speedMaximum = a;
    dataOrder = b;
    dataMode = c;
  }
  int speedMaximum, dataOrder, dataMode;
};

class SPI {
public:
  SPI() {}
  ~SPI() {}

  enum Order_t { LSBFIRST, MSBFIRST };

  enum Mode_t { SPI_MODE0, SPI_MODE1, SPI_MODE2, SPI_MODE3 };

  enum ClockDivider_t {
    SPI_CLOCK_DIV2,
    SPI_CLOCK_DIV4,
    SPI_CLOCK_DIV8,
    SPI_CLOCK_DIV16,
    SPI_CLOCK_DIV32,
    SPI_CLOCK_DIV64,
    SPI_CLOCK_DIV128
  };

  void begin() {}
  void beginTransaction(SPISettings &s) {}
  void endTransaction() {}
  void end() {}
  void setBitOrder(Order_t order) {}
  void setClockDivider(ClockDivider_t div) {}
  void setDataMode(Mode_t mode) {}
  uint8_t transfer(uint8_t val) { return 0; }
  uint16_t transfer(uint16_t val) { return 0; }
  uint8_t *transfer(uint8_t *buff) { return buff; }
  void usingInterrupt(int num) {}
};