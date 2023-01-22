#include <accel.h>

#define ACCEL_THRESH 7.5

accel::accel(Adafruit_MPU6050 *mpu)
{
    m_mpu = mpu;
}

int accel::init()
{
    if (!m_mpu->begin())
    {
        Serial.println("Failed to find MPU6050 chip");
        while (1)
        {
            Serial.print("L");
            delay(10);
        }
    }
    m_mpu->setAccelerometerRange(MPU6050_RANGE_8_G);
    m_mpu->setGyroRange(MPU6050_RANGE_500_DEG);
    m_mpu->setFilterBandwidth(MPU6050_BAND_21_HZ);
    return 1;
}

int accel::update()
{
    sensors_event_t a, g, temp;
    m_mpu->getEvent(&a, &g, &temp);

    // Serial.print(a.acceleration.x);
    // Serial.print(" : ");
    // Serial.print(a.acceleration.y);
    // Serial.print(" : ");
    // Serial.println(a.acceleration.z);

    m_x = a.acceleration.x;
    m_y = a.acceleration.y;
    m_z = a.acceleration.z;
    return 1;
}

float accel::get_x()
{
    return m_x;
}

float accel::get_y()
{
    return m_y;
}

float accel::get_z()
{
    return m_z;
}

ORIENTATION accel::get_orientation()
{
    if (m_z > ACCEL_THRESH)
        return SPEAR; // Spear
    if (m_z < -ACCEL_THRESH)
        return BOTTOM; // bottom
    if (m_x > ACCEL_THRESH)
        return NORTH; // cal (North)
    if (m_x < -ACCEL_THRESH)
        return SOUTH; // open (south)
    if (m_y > ACCEL_THRESH)
        return EAST; // dial (east)
    if (m_y < -ACCEL_THRESH)
        return WEST; // speaker (west)
    return NONE;
}