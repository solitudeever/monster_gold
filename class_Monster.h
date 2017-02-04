#pragma once
#include "class_Creature.h"
#include "common_lib.h"


class Monster : public Creature
{
private:
    // struct of a monster, use Monster_type as index
    struct Monster_data
    {
        std::string name;
        char symbol;
        int health;
        int atk;
        int gold;
    };

public:
    // types of monster, served as index for mon_arr
    enum Monster_type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_MON_TYPES,
    };

    // array of monster struct: Monster_data
    const static Monster_data mon_arr[MAX_MON_TYPES];

    // constructor, using data in mon_arr
    Monster(Monster_type type) :
        Creature(mon_arr[type].name, mon_arr[type].symbol,
            mon_arr[type].health, mon_arr[type].atk, mon_arr[type].gold)
    {}
};