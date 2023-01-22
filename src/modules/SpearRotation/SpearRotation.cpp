#include "SpearRotation.h"
#include "SpearRotationNode.h"

SpearRotation::SpearRotation(Servo *spear)
{
    m_spear = spear;
    m_step = 0;
}

void SpearRotation::begin()
{
    m_gameNum = 0;
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
    m_spear->write(m_game[m_gameNum][0]);
}

bool SpearRotation::readInput(ORIENTATION top)
{
    if (m_step == 4)
        return 0;

    if (top == m_game[m_step][1])
        m_step += 1;
    else if (m_step == 0)
        return 0;
    else
        m_step = 0;

    m_spear->write(m_game[m_gameNum][0]);
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
    // m_game[0] = {SERVO_POS_CENTER, SPEAR};
    // m_game[1] = {SERVO_POS_LEFT, WEST};
    // m_game[2] = {SERVO_POS_CENTER, BOTTOM};
    // m_game[3] = {SERVO_POS_RIGHT, NORTH};
    // m_game[4] = {SERVO_POS_CENTER, -1};
}

void SpearRotation::setGame2()
{
    // m_game[0] = {SERVO_POS_CENTER, SPEAR};
    // m_game[1] = {SERVO_POS_RIGHT, EAST};
    // m_game[2] = {SERVO_POS_LEFT, EAST};
    // m_game[3] = {SERVO_POS_RIGHT, BOTTOM};
    // m_game[4] = {SERVO_POS_CENTER, -1};
}
