#include <gtest/gtest.h>
#include <mock_serial.hpp>


TEST(gciMock, serial) {
  SerialPort Serial;
  Serial.begin(9600);

  EXPECT_TRUE(Serial);

  int cnt = Serial.available();
  EXPECT_EQ(cnt, 1);

  cnt = Serial.read();
  EXPECT_EQ(cnt, 1);

  cnt = Serial.write(2);
  EXPECT_EQ(cnt, 1);

  uint8_t buff[3];
  cnt = Serial.write(buff, 3);
  EXPECT_EQ(cnt, 3);

  EXPECT_NO_THROW(Serial.print("hello"));
  EXPECT_NO_THROW(Serial.println("hello"));
  EXPECT_NO_THROW(Serial.print(3.1));
  EXPECT_NO_THROW(Serial.println(3.1));
}