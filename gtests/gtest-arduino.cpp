#include <gtest/gtest.h>
#include <Arduino.h>
#include <SPI.h>
#include <Servo.h>
#include <Wire.h>


TEST(gciMock, math) {
  int a = constrain(4,1,3);
  EXPECT_EQ(a,3);

  a = constrain(0,1,3);
  EXPECT_EQ(a,1);
  a = constrain(2,1,3);
  EXPECT_EQ(a,2);
}

TEST(gciMock, interfaces) {
  EXPECT_NO_THROW(Servo s);

  EXPECT_NO_THROW(SPISettings ss(
    SPI::LSBFIRST,
    SPI::SPI_MODE0,
    SPI::SPI_CLOCK_DIV2
  ));

  EXPECT_NO_THROW(TwoWire Wire);
}
