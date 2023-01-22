#ifndef ACCEL_H
#define ACCEL_H

#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

enum ORIENTATION
{
    SPEAR,
    BOTTOM,
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NONE
};

class accel
{
public:
    accel(Adafruit_MPU6050 *mpu);
    int init();
    int update(); // get the newest accelerometer values

    float get_x();
    float get_y();
    float get_z();

    ORIENTATION get_orientation();

private:
    Adafruit_MPU6050 *m_mpu;
    float m_x;
    float m_y;
    float m_z;
};

#endif