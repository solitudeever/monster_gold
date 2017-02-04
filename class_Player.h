#pragma once
#include "common_lib.h"
#include "class_Creature.h"


class Player : public Creature
{
private:
    int m_level;
    // initial status for a player
    const static char init_symbol;
    const static int init_health;
    const static int init_level;
    const static int init_atk;
    const static int init_gold;
public:
    Player(const std::string& name) :
        Creature(name, init_symbol, init_health, init_atk, init_gold),
        m_level(init_level)
    {}


};
