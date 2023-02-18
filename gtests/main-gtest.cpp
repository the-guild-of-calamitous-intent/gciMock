#include <gtest/gtest.h>
#include <Arduino.h>
#include <SPI.h>
#include <Servo.h>
#include <Wire.h>
#include <Serial.hpp>


TEST(gciMock, math) {
  int a = constrain(4,1,3);
  EXPECT_EQ(a,3);

  a = constrain(0,1,3);
  EXPECT_EQ(a,1);
  a = constrain(2,1,3);
  EXPECT_EQ(a,2);
}

TEST(gciMock, interfaces) {
  Servo s;
  EXPECT_TRUE(true);

  SPISettings ss(
    SPI::LSBFIRST,
    SPI::SPI_MODE0,
    SPI::SPI_CLOCK_DIV2
  );

  TwoWire Wire;

  SerialPort Serial;
  Serial.begin(9600);

  int cnt = Serial.available();
  EXPECT_EQ(cnt, 1);

  cnt = Serial.read();
  EXPECT_EQ(cnt, 1);

  cnt = Serial.write(2);
  EXPECT_EQ(cnt, 1);

  uint8_t buff[3];
  cnt = Serial.write(buff, 3);
  EXPECT_EQ(cnt, 3);
}