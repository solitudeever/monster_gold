#include "class_Creature.h"


const std::string& Creature::getName() const
{
    return m_name;
}

char Creature::getSymbol() const
{
    return m_symbol;
}

int Creature::getHealth() const
{
    return m_health;
}

int Creature::getAtk() const
{
    return m_atk;
}

int Creature::getGold() const
{
    return m_gold;
}

Creature& Creature::addGold(int gold_gain)
{
    m_gold += gold_gain;
    return *this;
}

Creature& Creature::reduceHealth(int health_loss)
{
    m_health -= health_loss;
    return *this;
}