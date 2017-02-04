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

Creature& Creature::addHp(int hp_gain, bool can_excced_max, int max_hp)
{
    int new_hp{ m_health + hp_gain };
    if (can_excced_max)
    {
        m_health = new_hp;
    }
    else
    {
        m_health = new_hp < max_hp ? new_hp : max_hp;
    }
    return *this;
}

Creature& Creature::addAtk(int atk_gain)
{
    m_atk += atk_gain;
    return *this;
}

bool Creature::is_dead() const
{
    return m_health <= 0;
}