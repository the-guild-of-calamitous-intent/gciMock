#include "SPI.h"

SPISettings s(
  SPI::LSBFIRST,
  SPI::SPI_MODE0,
  SPI::SPI_CLOCK_DIV2
);

SPI spi; // just making sure it compiles