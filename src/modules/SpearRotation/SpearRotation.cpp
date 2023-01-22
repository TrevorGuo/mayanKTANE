#include "SpearRotation.h"
#include "SpearRotationNode.h"

SpearRotation::SpearRotation()
{
    spear.attach(SERVO_PIN);
}

void SpearRotation::begin()
{
    spear.attach(SERVO_PIN);
    m_gameNum = 0;

    SpearRotationNode *start = new SpearRotationNode(false, SERVO_POS_CENTER);
    m_fsm.setStart(start);
    if (m_gameNum == 0)
    {
        setGame0(start);
    }
    else if (m_gameNum == 1)
    {
        setGame1(start);
    }
    else
    {
        setGame2(start);
    }
    updateHardware(start);
}

bool SpearRotation::readInput(ORIENTATION top)
{
    updateHardware(m_fsm.stateTransition(top));
    return m_fsm.isCompleted();
}

void SpearRotation::updateHardware(SpearRotationNode *curr)
{
    Serial.print("UPDATING TO: ");
    Serial.println(curr->getSPos());
    spear.write(curr->getSPos());
}

void SpearRotation::setGame0(SpearRotationNode *start)
{
    SpearRotationNode *s1 = new SpearRotationNode(false, SERVO_POS_CENTER);
    SpearRotationNode *s2 = new SpearRotationNode(false, SERVO_POS_RIGHT);
    SpearRotationNode *s3 = new SpearRotationNode(false, SERVO_POS_CENTER);
    SpearRotationNode *s4 = new SpearRotationNode(true, SERVO_POS_CENTER);
    start->addNextNode(SPEAR, s1);
    s1->addNextNode(NORTH, s2);
    s2->addNextNode(EAST, s3);
    s3->addNextNode(NORTH, s4);
}

void setGame1(SpearRotationNode *start)
{
    SpearRotationNode *s1 = new SpearRotationNode(false, SERVO_POS_LEFT);
    SpearRotationNode *s2 = new SpearRotationNode(false, SERVO_POS_CENTER);
    SpearRotationNode *s3 = new SpearRotationNode(false, SERVO_POS_LEFT);
    SpearRotationNode *s4 = new SpearRotationNode(true, SERVO_POS_CENTER);
    start->addNextNode(SPEAR, s1);
    s1->addNextNode(WEST, s2);
    s2->addNextNode(BOTTOM, s3);
    s3->addNextNode(NORTH, s4);
}

void setGame2(SpearRotationNode *start)
{
    SpearRotationNode *s1 = new SpearRotationNode(false, SERVO_POS_RIGHT);
    SpearRotationNode *s2 = new SpearRotationNode(false, SERVO_POS_LEFT);
    SpearRotationNode *s3 = new SpearRotationNode(false, SERVO_POS_RIGHT);
    SpearRotationNode *s4 = new SpearRotationNode(true, SERVO_POS_CENTER);
    start->addNextNode(SPEAR, s1);
    s1->addNextNode(EAST, s2);
    s2->addNextNode(WEST, s3);
    s3->addNextNode(EAST, s4);
}
