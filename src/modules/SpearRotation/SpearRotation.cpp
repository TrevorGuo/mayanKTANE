#include "SpearRotation.h"
#include "SpearRotationNode.h"

SpearRotation::SpearRotation(Servo *spear)
{
    m_spear = spear;
    m_step = 0;
}

void SpearRotation::begin()
{
    m_gameNum = rand() % 3;
    Serial.print("game number: ");
    Serial.println(m_gameNum);
    m_spear->attach(SERVO_PIN);
    if (m_gameNum == 0)
    {
        setGame0();
    }
    else if (m_gameNum == 1)
    {
        setGame1();
    }
    else
    {
        setGame2();
    }
    m_spear->write(m_game[m_step][0]);
}

bool SpearRotation::readInput(ORIENTATION top)
{
    Serial.print("Step: ");
    Serial.print(m_step);
    Serial.print(" -> ");
    if (m_step == 4)
    {
        Serial.println();
        return 0;
    }

    if (top == m_game[m_step][1])
        m_step += 1;
    else if (m_step == 0)
    {
        Serial.println();
        return 0;
    }
    else
        m_step = 0;

    Serial.println(m_step);

    m_spear->write(m_game[m_step][0]);
    return m_step == 4;
}

void SpearRotation::setGame0()
{
    m_game[0][0] = SERVO_POS_CENTER;
    m_game[0][1] = SPEAR;
    m_game[1][0] = SERVO_POS_CENTER;
    m_game[1][1] = NORTH;
    m_game[2][0] = SERVO_POS_RIGHT;
    m_game[2][1] = SOUTH;
    m_game[3][0] = SERVO_POS_CENTER;
    m_game[3][1] = SOUTH;
    m_game[4][0] = SERVO_POS_CENTER;
    m_game[4][1] = -1;
}

void SpearRotation::setGame1()
{
    m_game[0][0] = SERVO_POS_CENTER;
    m_game[0][1] = SPEAR;

    m_game[1][0] = SERVO_POS_LEFT;
    m_game[1][1] = WEST;

    m_game[2][0] = SERVO_POS_CENTER;
    m_game[2][1] = BOTTOM;

    m_game[3][0] = SERVO_POS_LEFT;
    m_game[3][1] = NORTH;

    m_game[4][0] = SERVO_POS_CENTER;
    m_game[4][1] = -1;
}

void SpearRotation::setGame2()
{
    m_game[0][0] = SERVO_POS_CENTER;
    m_game[0][1] = SPEAR;

    m_game[1][0] = SERVO_POS_RIGHT;
    m_game[1][1] = EAST;

    m_game[2][0] = SERVO_POS_LEFT;
    m_game[2][1] = EAST;

    m_game[3][0] = SERVO_POS_RIGHT;
    m_game[3][1] = BOTTOM;

    m_game[4][0] = SERVO_POS_CENTER;
    m_game[4][1] = -1;
}
