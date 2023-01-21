#include <accel.h>

#define ACCEL_THRESH 7.5

accel::accel(Adafruit_MPU6050* mpu) {
    m_mpu = mpu;
}

int accel::init() {
    if (!m_mpu->begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
    m_mpu->setAccelerometerRange(MPU6050_RANGE_8_G);
    m_mpu->setGyroRange(MPU6050_RANGE_500_DEG);
    m_mpu->setFilterBandwidth(MPU6050_BAND_21_HZ);
    return 1;
}

int accel::update() {
    sensors_event_t a, g, temp;
    m_mpu->getEvent(&a, &g, &temp);
    m_x = a.acceleration.x;
    m_y = a.acceleration.y;
    m_z = a.acceleration.z;
    return 1;
}

float accel::get_x() {
    return m_x;
}

float accel::get_y() {
    return m_y;
}

float accel::get_z() {
    return m_z;
}

ORIENTATION accel::get_orientation() {
    if (m_z > ACCEL_THRESH)
        return SIDE_0;
    if (m_z < -ACCEL_THRESH)
        return SIDE_1;
    if (m_x > ACCEL_THRESH)
        return SIDE_2;
    if (m_x < -ACCEL_THRESH)
        return SIDE_3;
    if (m_y > ACCEL_THRESH)
        return SIDE_4;
    if (m_y < -ACCEL_THRESH)
        return SIDE_5;
    return NONE;
}