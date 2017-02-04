#pragma once
#include "common_lib.h"


class Creature
{
private:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_atk;
    int m_gold;
public:
    // constructor
    Creature(const std::string &name = "", char symbol = 'x',
        int health = 0, int atk = 0, int gold = 0) :
        m_name(name), m_symbol(symbol), m_health(health),
        m_atk(atk), m_gold(gold)
    {}

    // accessor
    const std::string& getName() const;
    char getSymbol() const;
    int getHealth() const;
    int getAtk() const;
    int getGold() const;
    Creature& addGold(int gold_gain);
    Creature& reduceHealth(int health_loss);
    Creature& addHp(int hp_gain, bool can_excced_max = false, int max_hp = 0);
    Creature& addAtk(int atk_gain);
    bool is_dead() const;

};